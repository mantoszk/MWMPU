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
	 * \brief Enters Reset button event - deletes stored angular velocity and acceleration data (erases charts data)
	 */

	void onResetButtonClicked();

	/*!
	 * \brief Enters Calibrate button event - deletes temporary stored angle and distance data (erases bar graph data) and sets openGL object to starting coordinates
	 */

	void onCalibrateButtonClicked();

	/*!
	 * \brief Repeats events such as: reading from serial port, updating rotation and distance values and updating charts
	 */

	void eventLoop();

	/*!
	 * \brief Closes main application
	 */

	void closeAppEvent();

	/*!
	 * \brief Connects to the device using serial connection (checks whether it has connected to the right device)
	 */

	void onConnectButtonClicked();

	/*!
	 * \brief Automatically looks for proper device to connect to
	 */

	void onAutoButtonClicked();

	/*!
	 * \brief Disconnects from the device
	 */

	void onDisconnectButtonClicked();

	/*!
	 * \brief Updates status bar text (which means setting correct messages)
	 */

	void writeToStatusBar();

private:
	MeasurementHandler *transform;
	SerialPortReader *arduino;
	Ui::MainWindow *ui;

	QTimer loopTimer,  /*!< timer that sets plots refresh frequency*/
	statusBarTimer; /*!< timer that sets how long will be status bar message displayed*/

	QVector <QString> labels1, /*!< acceleration chart's labels*/
	labels2, /*!< angular velcity chart's labels*/
	labels3, /*!< angle chart's labels*/
	labels4; /*!< distance chart's labels*/

	QVector <QString> legend; /*!< legend's text for linear graphs*/

	QVector <QColor> plotColors; /*!< plot's color for linear graphs*/
	QColor bgColor, fgColor;
	quint32 plotsAmount;
	double maxYAxisValue, /*!< minimal bar graph value showed on vertical axis for angle graph*/
	maxYAxisValue2;  /*!< minimal bar graph value showed on vertical axis for distance graph*/

	/*!
	 * \brief Sets graphs properties like background and foreground colors and amount of plots (which means 1 to maximum 3 of plots on one chart)
	 */

	void setGraphsProperties();

	/*!
	 * \brief Generates bar graph
	 * \param pointer - pointer to target qtWidget
	 * \param data - data to plot (current data)
	 * \param plotsAmount - plots amount (1 to maximum 3 of plots), 1 - only x axis plot, 2 - x and y axis plots, 3 - x, y and z axis plots
	 * \param labels - labels for axes (which means labels for chart's horizontal and vertical axes)
	 * \param bgColor - background color
	 * \param fgColor - foreground color (text color)
	 */

	void generateBarGraph(QCustomPlot *pointer, const QVector <double> &data, const quint32 &plotsAmount, const QVector <QString> &labels, const QColor &bgColor, const QColor &fgColor);

	/*!
	 * \brief Updated bar graph
	 * \param pointer - pointer to target qtWidget
	 * \param data - data to plot (current data)
	 * \param plotsAmount - plots amount (1 to maximum 3 of plots), 1 - only x axis plot, 2 - x and y axis plots, 3 - x, y and z axis plots
	 * \param labels - labels for axes (which means labels for chart's horizontal and vertical axes)
	 * \param bgColor - background color
	 * \param fgColor - foreground color (text color)
	 */

	void updateBarGraph(QCustomPlot *pointer, const QVector <double> &data, const quint32 &plotsAmount, const QVector <QString> &labels, const QColor &bgColor, const QColor &fgColor);

	/*!
	 * \brief Generates linear graph
	 * \param pointer - pointer to target qtWidget
	 * \param plotsAmount - plots amount (1 to maximum 3 of plots), 1 - only x axis plot, 2 - x and y axis plots, 3 - x, y and z axis plots
	 * \param labels - labels for axes (which means labels for chart's horizontal and vertical axes)
	 * \param legend - legend's text (text for describing plots on chart)
	 * \param plotColors - plot's colors
	 * \param bgColor - background color
	 * \param fgColor - foreground color (text color)
	 */

	void generateLinearGraph(QCustomPlot *pointer, const quint32 &plotsAmount, const QVector <QString> &labels,  const QVector<QString> &legend, const QVector<QColor> &plotColors, const QColor &bgColor, const QColor &fgColor);

	/*!
	 * \brief Updated linear graph
	 * \param pointer - pointer to target qtWidget
	 * \param pointers - pointers to data received from microcontroller - with history
	 * \param plotsAmount - plots amount (1 to maximum 3 of plots), 1 - only x axis plot, 2 - x and y axis plots, 3 - x, y and z axis plots
	 */

	void updateLinearGraph(QCustomPlot *pointer, const QVector<QVector<double> *> pointers, const quint32 &plotsAmount);

	/*!
	 * \brief Deletes stored angular velocity and acceleration data (erases charts data)
	 */

	void clearHistoryPlots();

	/*!
	 * \brief Deletes temporary stored angle and distance data (erases bar graph data)
	 */

	void clearRealtimePlots();

	/*!
	 * \brief Adds available devices to comboBox menu
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
