#ifndef SERIALPORTREADER_H
#define SERIALPORTREADER_H

#include <QByteArray>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QDebug>
#include <QVector3D>
#include <QString>
#include <QStringList>
#include "measurementhandler.h"
#include <QApplication>
#include <QThread>

/*!
 * \brief A class wraps everything about receiving data from the microcontroller
 */

class SerialPortReader
{
private:
	MeasurementHandler *mHandler;
	QSerialPort *m_serialPort;
	QVector <QSerialPortInfo> m_info;
	bool isOpen = false;
	quint32 errorCode = 0;

	QVector <double> time;
	QVector <double> accelerationX, accelerationY, accelerationZ;
	QVector <double> angularVelocityX, angularVelocityY, angularVelocityZ;

	/*!
	 * \brief Checks if received data from connected device is valid
	 * \return true if received data is valid
	 */

	bool goodChoice();
public:

	/*!
	 * \brief Parametric constructor
	 * \param[in] nHandler - a pointer to the object where the data of the loaded object is to be saved
	 */
	SerialPortReader(MeasurementHandler *nHandler);

	~SerialPortReader();

	/*!
	 * \brief readLine
	 * \return true if readLine is succesfull
	 */

	bool readLine();

	/*!
	 * \brief A method used to obtain information about devices connected to a computer
	 * \return the device names
	 */

	QVector<QSerialPortInfo> getInfo() const;

	/*!
	 * \brief A method to connect to the device via serial port
	 * \param[in] index - device's index
	 * \return true if device is succesfully connected
	 */

	bool connect(quint32 index);

	/*!
	 * \brief A method to disconnect device from serial port
	 * \return true if device is succesfully disconnected
	 */

	bool disconnect();

	/*!
	 * \brief A method to obtain the error code
	 * \return error's code index
	 */

	quint32 getErrorCode() const;

	/*!
	 * \brief A method to remove error signatures
	 */

	void resetErrorCode();

};

#endif // SERIALPORTREADER_H
