#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QTimer>
#include <QColor>
#include <QtMath>
#include "qcustomplot.h"
#include "serialportreader.h"
#include "measurementhandler.h"

namespace Ui
{
	class MainWindow;
}

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	explicit MainWindow(QWidget *parent = nullptr);
	~MainWindow();

private slots:
	void onResetButtonClicked();
	void onCalibrateButtonClicked();
	void eventLoop();
	void closeAppEvent();

	void onConnectButtonClicked();

	void onAutoButtonClicked();

	void onDisconnectButtonClicked();

	void writeToStatusBar();

private:
	MeasurementHandler *transform;
	SerialPortReader *arduino;
	Ui::MainWindow *ui;

	QTimer loopTimer, statusBarTimer, openGLTimer;

	QVector <QString> labels1, labels2, labels3, labels4;
	QVector <QString> legend;
	QVector <QColor> plotColors;
	QColor bgColor, fgColor;
	quint32 plotsAmount;
	double maxYAxisValue, maxYAxisValue2;

	void setGraphsProperties();
	void generateBarGraph(QCustomPlot *pointer, const QVector <double> &data, const quint32 &plotsAmount, const QVector <QString> &labels, const QColor &bgColor, const QColor &fgColor);
	void updateBarGraph(QCustomPlot *pointer, const QVector <double> &data, const quint32 &plotsAmount, const QVector <QString> &labels, const QColor &bgColor, const QColor &fgColor);

	void generateLinearGraph(QCustomPlot *pointer, const quint32 &plotsAmount, const QVector <QString> &labels,  const QVector<QString> &legend, const QVector<QColor> &plotColors, const QColor &bgColor, const QColor &fgColor);
	void updateLinearGraph(QCustomPlot *pointer, const QVector<QVector<double> *> pointers, const quint32 &plotsAmount);

	void clearHistoryPlots();
	void clearRealtimePlots();

	void setComboBox();

	QString getErrorText(const quint32 errorCode) const;

	void showMessage();
	void showMessage(const quint32 errorCode);
};

#endif // MAINWINDOW_H
