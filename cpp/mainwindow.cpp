#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent),
	transform(new MeasurementHandler), arduino(new SerialPortReader(transform)),ui(new Ui::MainWindow)
{
	ui->setupUi(this);
	connect(ui->calibrateButton, SIGNAL (released()), this, SLOT (onCalibrateButtonClicked()));
	connect(ui->calibrateButton2, SIGNAL (released()), this, SLOT (onCalibrateButtonClicked()));
	connect(ui->resetButton, SIGNAL (released()), this, SLOT (onResetButtonClicked()));
	connect(ui->resetButton2, SIGNAL (released()), this, SLOT (onResetButtonClicked()));
	connect(ui->connectButton, SIGNAL (released()), this, SLOT (onConnectButtonClicked()));
	connect(ui->autoButton, SIGNAL (released()), this, SLOT (onAutoButtonClicked()));
	connect(ui->disconnectButton, SIGNAL (released()), this, SLOT (onDisconnectButtonClicked()));

	connect(&loopTimer,SIGNAL(timeout()),this,SLOT(eventLoop()));
	connect(&statusBarTimer,SIGNAL(timeout()),this,SLOT(writeToStatusBar()));

	setGraphsProperties();
	generateLinearGraph(ui->accelerationGraph, plotsAmount, labels1, legend, plotColors, bgColor, fgColor);
	generateLinearGraph(ui->angularVelocityGraph, plotsAmount, labels2,legend ,plotColors, bgColor, fgColor);
	generateLinearGraph(ui->accelerationGraph2, plotsAmount, labels1, legend, plotColors, bgColor, fgColor);
	generateLinearGraph(ui->angularVelocityGraph2, plotsAmount, labels2, legend, plotColors, bgColor, fgColor);
	generateBarGraph(ui->angleGraph, transform->getAngle(), plotsAmount, labels3, bgColor, fgColor);
	generateBarGraph(ui->distanceGraph, transform->getDistance(), plotsAmount, labels4, bgColor, fgColor);
	generateBarGraph(ui->angleGraph2, transform->getAngle(), plotsAmount, labels3, bgColor, fgColor);
	generateBarGraph(ui->distanceGraph2, transform->getDistance(), plotsAmount, labels4, bgColor, fgColor);

	setComboBox();
}

MainWindow::~MainWindow()
{
	delete transform;
	delete arduino;
	delete ui;
}

void MainWindow::eventLoop()
{
	arduino->readLine();
	transform->calcAngleAndDistance();

	updateLinearGraph(ui->accelerationGraph, transform->getVectorOfAccPointers(),plotsAmount);
	updateLinearGraph(ui->angularVelocityGraph, transform->getVectorOfGyroPointers(),plotsAmount);
	updateLinearGraph(ui->accelerationGraph2, transform->getVectorOfAccPointers(),plotsAmount);
	updateLinearGraph(ui->angularVelocityGraph2, transform->getVectorOfGyroPointers(),plotsAmount);
	updateBarGraph(ui->angleGraph, transform->getAngle(), plotsAmount, labels3, bgColor, fgColor);
	updateBarGraph(ui->distanceGraph, transform->getDistance(), plotsAmount, labels4, bgColor, fgColor);
	updateBarGraph(ui->angleGraph2, transform->getAngle(), plotsAmount, labels3, bgColor, fgColor);
	updateBarGraph(ui->distanceGraph2, transform->getDistance(), plotsAmount, labels4, bgColor, fgColor);

	ui->openGLWidget->updateRotation(transform->getAngle());
	ui->openGLWidget2->updateRotation(transform->getAngle());
	ui->openGLWidget->updateDistance(transform->getDistance());
	ui->openGLWidget2->updateDistance(transform->getDistance());
	ui->openGLWidget->update();
	ui->openGLWidget2->update();
}

void MainWindow::setGraphsProperties()
{
	plotsAmount = 3;

	labels1.push_back("t [s]");
	labels1.push_back("a [m/s^2]");
	labels2.push_back("t [s]");
	labels2.push_back("ω [deg/s]");

	plotColors.push_back(QColor(255,0,0));
	plotColors.push_back(QColor(255,255,0));
	plotColors.push_back(QColor(0,0,255));

	bgColor = this->palette().background().color();
	fgColor = QColor(255,255,255);

	legend.push_back("x");
	legend.push_back("y");
	legend.push_back("z");

	labels3.push_back("x");
	labels3.push_back("y");
	labels3.push_back("z");
	labels3.push_back("angle [deg]");

	labels4.push_back("x");
	labels4.push_back("y");
	labels4.push_back("z");
	labels4.push_back("distance [cm]");
}

void MainWindow::generateBarGraph(QCustomPlot *pointer, const QVector<double> &data, const quint32 &plotsAmount, const QVector<QString> &labels, const QColor &bgColor, const QColor &fgColor)
{
	pointer->setBackground(bgColor);

	// create empty bar chart object:
	QCPBars *chart = new QCPBars(pointer->xAxis, pointer->yAxis);

	// set name and color:
	chart->setPen(QPen(fgColor));
	chart->setBrush(fgColor);

	// prepare x axis with axes labels:
	QVector <double> ticks;
	QVector<QString> label;

	for(quint32 i=0; i<plotsAmount; ++i)
	{
		ticks << (i + 1);
		label << labels[i];
	}

	QSharedPointer<QCPAxisTickerText> textTicker(new QCPAxisTickerText);
	textTicker->addTicks(ticks, label);
	pointer->xAxis->setTicker(textTicker);
	pointer->xAxis->setSubTicks(false);
	pointer->xAxis->setTickLength(0, 4);
	pointer->xAxis->setRange(0, 4);
	pointer->xAxis->setBasePen(QPen(fgColor));
	pointer->xAxis->setTickPen(QPen(fgColor));
	pointer->xAxis->setTickLabelColor(fgColor);
	pointer->xAxis->setLabelColor(fgColor);

	// prepare y axis:
	pointer->yAxis->setLabel(labels[plotsAmount]);
	pointer->yAxis->setBasePen(QPen(fgColor));
	pointer->yAxis->setTickPen(QPen(fgColor));
	pointer->yAxis->setSubTickPen(QPen(fgColor));
	pointer->yAxis->setTickLabelColor(fgColor);
	pointer->yAxis->setLabelColor(fgColor);

	QVector <double> modifiedData;
	modifiedData.push_back(-data[0]);
	modifiedData.push_back(data[1]);
	modifiedData.push_back(-data[2]);

	for(quint32 i =0; i< plotsAmount; ++i)
	{
		if(qSqrt(data[i]) > maxYAxisValue)
		{
			maxYAxisValue = data[i];
		}
	}

	chart->setData(ticks, modifiedData);
	pointer->yAxis->setRange(-maxYAxisValue * 1.2, maxYAxisValue * 1.2);
	//pointer->yAxis->rescale();
	pointer->clearItems();
}

void MainWindow::updateBarGraph(QCustomPlot *pointer,const QVector<double> &data, const quint32 &plotsAmount, const QVector<QString> &labels, const QColor &bgColor, const QColor &fgColor)
{
	pointer->clearPlottables();
	generateBarGraph(pointer, data, plotsAmount, labels, bgColor, fgColor);
	pointer->replot();
	pointer->update();
}

void MainWindow::generateLinearGraph(QCustomPlot *pointer, const quint32 &plotsAmount, const QVector<QString> &labels,  const QVector<QString> &legend, const QVector<QColor> &plotColors, const QColor &bgColor, const QColor &fgColor)
{
	pointer->setBackground(bgColor);
	pointer->xAxis->setBasePen(QPen(fgColor));
	pointer->xAxis->setTickPen(QPen(fgColor));
	pointer->xAxis->setTickLabelColor(fgColor);
	pointer->xAxis->setLabelColor(fgColor);

	pointer->yAxis->setBasePen(QPen(fgColor));
	pointer->yAxis->setTickPen(QPen(fgColor));
	pointer->yAxis->setSubTickPen(QPen(fgColor));
	pointer->yAxis->setTickLabelColor(fgColor);
	pointer->yAxis->setLabelColor(fgColor);

	pointer->xAxis->setLabel(labels[0]);
	pointer->yAxis->setLabel(labels[1]);

	pointer->legend->setVisible(true);
	pointer->legend->setBrush(bgColor);

	for(quint32 i = 0; i < plotsAmount; ++i)
	{
		pointer->addGraph();
		pointer->graph(i)->setPen(QPen(plotColors[i]));
		pointer->graph(i)->setName(legend[i]);
	}

	pointer->legend->setTextColor(fgColor);
	pointer->legend->setBorderPen(QPen(fgColor));
}

void MainWindow::updateLinearGraph(QCustomPlot *pointer, const QVector<QVector<double> *> pointers, const quint32 &plotsAmount)
{
	for(quint32 i = 0; i<plotsAmount; ++i)
	{
		pointer->graph(i)->setData(*transform->getTime(),*pointers[i]);
	}
	pointer->xAxis->rescale();
	pointer->yAxis->rescale();

	pointer->replot();
	pointer->update();
}

void MainWindow::clearHistoryPlots()
{
	ui->accelerationGraph->replot();
	ui->angularVelocityGraph->replot();
	ui->accelerationGraph->update();
	ui->angularVelocityGraph->update();
}

void MainWindow::clearRealtimePlots()
{
	ui->distanceGraph->clearPlottables();
	ui->angleGraph->clearPlottables();
	ui->distanceGraph->replot();
	ui->angleGraph->replot();
}

void MainWindow::setComboBox()
{
	QVector <QSerialPortInfo> temp = arduino->getInfo();
	for(auto &i : temp)
	{
		ui->comboBox->addItem(i.description());
	}
}

QString MainWindow::getErrorText(const quint32 errorCode) const
{
	if(errorCode == 0)
	{
		return "";
	}
	else if(errorCode == 1)
	{
		return "Wrong SerialPort";
	}
	else if(errorCode == 2)
	{
		return "SerialPort opened successfully";
	}
	else if(errorCode == 3)
	{
		return "Can't open SerialPort";
	}
	else if(errorCode == 4)
	{
		return "There's no SerialPort to open";
	}
	else if(errorCode == 5)
	{
		return "There's already connection";
	}
	else if(errorCode == 6)
	{
		return "Can't find appropriate device, check your's device connection";
	}
	else if(errorCode == 7)
	{
		return "Connection is being closed";
	}
	else if(errorCode == 8)
	{
		return "There's nothing to disconnect from";
	}
	else if(errorCode == 9)
	{
		return "Vertex shader loaded";
	}
	else if(errorCode == 10)
	{
		return "Unable to load vertex shader";
	}
	else if(errorCode == 11)
	{
		return "Fragment shader loaded";
	}
	else if(errorCode == 12)
	{
		return "Unable to load vertex fragment";
	}
	else if(errorCode == 13)
	{
		return "Error opening model's file for reading";
	}
	else if(errorCode == 14)
	{
		return "Model's file opened successfully";
	}

	return "Wrong error's code";
}

void MainWindow::showMessage()
{
	ui->statusBar->showMessage(getErrorText(arduino->getErrorCode()));
	arduino->resetErrorCode();
	statusBarTimer.start(5000);
}

void MainWindow::showMessage(const quint32 errorCode)
{
	ui->statusBar->showMessage(getErrorText(errorCode));
	statusBarTimer.start(5000);
}

void MainWindow::closeAppEvent()
{
	QMainWindow::close();
}

void MainWindow::onResetButtonClicked()
{
	transform->clearHistoryData();
	clearHistoryPlots();
}

void MainWindow::onCalibrateButtonClicked()
{
	transform->clearRealtimeData();
	clearRealtimePlots();
}

void MainWindow::onConnectButtonClicked()
{
	if(arduino->connect(ui->comboBox->currentIndex()))
	{
		loopTimer.start(0);
	}
	showMessage();

	//ui->statusBar->showMessage("Clicked");
}

void MainWindow::onAutoButtonClicked()
{
	QVector <QSerialPortInfo> temp = arduino->getInfo();
	bool connected = false;

	for(int i=0; i< temp.size(); ++i)
	{
		if(temp[i].description().contains("Arduino Uno"))
		{
			if(arduino->connect(i))
			{
				showMessage();
				loopTimer.start(0);
				connected = true;
				break;
			}
		}
	}

	if(!connected)
	{
		showMessage(6);
		qDebug() << "Can't find appropriate device, check your's device connection";
	}
}

void MainWindow::onDisconnectButtonClicked()
{
	loopTimer.stop();
	if(arduino->disconnect())
	{
		showMessage(7);
		qDebug() << "Connection is being closed";
	}
	else
	{
		showMessage(8);
		qDebug() << "There's nothing to disconnect from";
	}
}

void MainWindow::writeToStatusBar()
{
	ui->statusBar->showMessage(getErrorText(0));
	statusBarTimer.stop();
}
