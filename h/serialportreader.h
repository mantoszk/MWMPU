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

	bool goodChoice();
public:
	SerialPortReader(MeasurementHandler *nHandler);
	~SerialPortReader();
	void readLine();
	QVector<QSerialPortInfo> getInfo() const;
	bool connect(quint32 index);
	bool disconnect();
	quint32 getErrorCode() const;
	void resetErrorCode();

};

#endif // SERIALPORTREADER_H
