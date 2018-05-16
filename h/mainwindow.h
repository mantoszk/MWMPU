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

/*!
 * \brief A class that supports the user interface and a module that generates charts
 */

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	explicit MainWindow(QWidget *parent = nullptr);
	~MainWindow();

private slots:
	/*!
	 * \brief Enters Reset button event
	 */

	void onResetButtonClicked();

	/*!
	 * \brief Enters Calibrate button event
	 */

	void onCalibrateButtonClicked();

	/*!
	 * \brief Repeats events such as: reading from serial port, updating rotation and distance values and updating charts
	 */

	void eventLoop();

	/*!
	 * \brief Closes application
	 */

	void closeAppEvent();

	/*!
	 * \brief Connects to the device using serial connection
	 */

	void onConnectButtonClicked();

	/*!
	 * \brief Automatically looks for proper device
	 */

	void onAutoButtonClicked();

	/*!
	 * \brief Disconnects from the device
	 */

	void onDisconnectButtonClicked();

	/*!
	 * \brief Updates status bar text
	 */

	void writeToStatusBar();

private:
	MeasurementHandler *transform;
	SerialPortReader *arduino;
	Ui::MainWindow *ui;

	QTimer loopTimer,  /*!< timer that sets plots refresh frequency*/
	statusBarTimer; /*!< timer that sets how long will be status bar communicates displayed*/

	QVector <QString> labels1, /*!< acceleration chart labels*/
	labels2, /*!< angular velcity chart labels*/
	labels3, /*!< angle chart labels*/
	labels4; /*!< distance chart labels*/

	QVector <QString> legend; /*!< legend's text for linear graphs*/

	QVector <QColor> plotColors; /*!< plot's color for linear graphs*/
	QColor bgColor, fgColor;
	quint32 plotsAmount;
	double maxYAxisValue, /*!< minimal bar graph value showed on vertical axis for angle graph*/
	maxYAxisValue2;  /*!< minimal bar graph value showed on vertical axis for distance graph*/

	/*!
	 * \brief Sets graphs properties like bg and fg colors and amount of plots
	 */

	void setGraphsProperties();

	/*!
	 * \brief Generates bar graph
	 * \param pointer - pointer to target widget
	 * \param data - data to plot
	 * \param plotsAmount - plots amount
	 * \param labels - labels for axes
	 * \param bgColor - background color
	 * \param fgColor - foreground color
	 */

	void generateBarGraph(QCustomPlot *pointer, const QVector <double> &data, const quint32 &plotsAmount, const QVector <QString> &labels, const QColor &bgColor, const QColor &fgColor);

	/*!
	 * \brief Updated bar graph
	 * \param pointer - pointer to target widget
	 * \param data - data to plot
	 * \param plotsAmount - plots amount
	 * \param labels - labels for axes
	 * \param bgColor - background color
	 * \param fgColor - foreground color
	 */

	void updateBarGraph(QCustomPlot *pointer, const QVector <double> &data, const quint32 &plotsAmount, const QVector <QString> &labels, const QColor &bgColor, const QColor &fgColor);

	/*!
	 * \brief Generates linear graph
	 * \param pointer - pointer to target widget
	 * \param plotsAmount - plots amount
	 * \param labels - labels for axes
	 * \param legend - legend's text
	 * \param plotColors - plot's colors
	 * \param bgColor - background color
	 * \param fgColor - foreground color
	 */

	void generateLinearGraph(QCustomPlot *pointer, const quint32 &plotsAmount, const QVector <QString> &labels,  const QVector<QString> &legend, const QVector<QColor> &plotColors, const QColor &bgColor, const QColor &fgColor);

	/*!
	 * \brief Updated linear graph
	 * \param pointer - pointer to target widget
	 * \param pointers - pointers to time and data containers
	 * \param plotsAmount - plots amount
	 */

	void updateLinearGraph(QCustomPlot *pointer, const QVector<QVector<double> *> pointers, const quint32 &plotsAmount);

	/*!
	 * \brief Clears measurements history data
	 */

	void clearHistoryPlots();

	/*!
	 * \brief Clears real time data
	 */

	void clearRealtimePlots();

	/*!
	 * \brief Sets combo box
	 */

	void setComboBox();

	/*!
	 * \brief Returns specific error's text based on error's code
	 * \param errorCode - error's code
	 * \return Error's text
	 */

	QString getErrorText(const quint32 errorCode) const;

	/*!
	 * \brief Shows message on status bar based on arduino
	 */

	void showMessage();

	/*!
	 * \brief Shows message on status bar based on error's code
	 * \param errorCode - error's code
	 */

	void showMessage(const quint32 errorCode);
};

#endif // MAINWINDOW_H
