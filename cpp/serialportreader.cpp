#include "serialportreader.h"
#include <QCoreApplication>

QVector<QSerialPortInfo> SerialPortReader::getInfo() const
{
	return m_info;
}

bool SerialPortReader::connect(quint32 index)
{
	if(!isOpen)
	{
		if(m_info.size() > 0)
		{
			m_serialPort = new QSerialPort(m_info[index]);
			m_serialPort->setBaudRate(19200);

			if(m_serialPort != nullptr)
			{

				m_serialPort->open(QIODevice::ReadOnly);
				isOpen = goodChoice();

				if(!isOpen)
				{
					m_serialPort->close();
					delete m_serialPort;
					m_serialPort = nullptr;

					errorCode = 1;
					qDebug() << "Wrong SerialPort";
				}
				else
				{
					errorCode = 2;
					qDebug() << "SerialPort opened succesfully";
				}
			}
			else
			{
				errorCode = 3;
				qDebug() << "Can't open SerialPort";
			}
		}
		else
		{
			errorCode = 4;
			qDebug() << "No SerialPort to open";
		}
	}
	else
	{
		errorCode = 5;
		qDebug() << "There's already connection";
	}

	return isOpen;
}

bool SerialPortReader::disconnect()
{
	if(isOpen)
	{
		m_serialPort->close();
		delete m_serialPort;
		m_serialPort = nullptr;
		isOpen = false;
		return true;
	}
	else
	{
		return false;
	}
}

quint32 SerialPortReader::getErrorCode() const
{
	return errorCode;
}

void SerialPortReader::resetErrorCode()
{
	errorCode = 0;
}

bool SerialPortReader::goodChoice()
{
	QByteArray serialData;
	QStringList valuesList;
	quint32 flag = 0;

	//if data is available - just reeeead it (-1):= no delay
	if(m_serialPort->waitForReadyRead(-1))
	{
		//flush to remove buffer's garbage
		m_serialPort->flush();

		//sometimes values from sensors are corrupted, leave them, read next pack of readings
		while(valuesList.size()!=6)
		{
			if(m_serialPort->waitForReadyRead(-1))
			{
				if(m_serialPort->canReadLine())
				{
					serialData = m_serialPort->readLine();
					QString myData(serialData);

					//sent values are divided by | for ease to split them
					valuesList = myData.split("|");

					for(qint32 i=0; i<valuesList.size(); ++i)
					{
						//simplified removes /n/r etc.
						valuesList[i] = valuesList[i].simplified();
					}
				}
			}

			if(flag > 50)
			{
				return false;
			}
			else
			{
				++flag;
				QThread::msleep(10);
			}
		}

		for(qint32 i=0; i<valuesList.size(); ++i)
		{
			if(valuesList[i].toInt() == 0)
			{
				return false;
			}
		}
	}

	return true;
}

SerialPortReader::SerialPortReader(MeasurementHandler *nHandler): mHandler(nHandler), m_serialPort(nullptr)
{
	//search for available devices
	foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts())
	{
		m_info.push_back(info);
	}
}

SerialPortReader::~SerialPortReader()
{
	if(m_serialPort != nullptr)
	{
		m_serialPort->close();
		delete m_serialPort;
	}
}

void SerialPortReader::readLine()
{
	qint32 intResponse[6];
	QByteArray serialData;
	QStringList valuesList;

	//if data is available - just reeeead it (-1):= no delay
	if(m_serialPort->waitForReadyRead(-1))
	{
		//flush to remove buffer's garbage
		m_serialPort->flush();

		//sometimes values from sensors are corrupted, leave them, read next pack of readings
		while(valuesList.size()!=6)
		{
			if(m_serialPort->waitForReadyRead(-1))
			{
				if(m_serialPort->canReadLine())
				{
					serialData = m_serialPort->readLine();
					QString myData(serialData);

					//sent values are divided by | for ease to split them
					valuesList = myData.split("|");

					for(qint32 i=0; i<valuesList.size(); ++i)
					{
						//simplified removes /n/r etc.
						valuesList[i] = valuesList[i].simplified();
					}
				}
			}
		}

		for(qint32 i=0; i<valuesList.size(); ++i)
		{
			intResponse[i]=valuesList[i].toInt();
		}

		//convert acceleration to g units and angular velocity to degrees per second
		//using +-2mg && +-125mdps
		//acc: raw value * 0.061 = value [mg] * 0.001 = value [g]
		//gyro: raw value * 4.375 = value [mdps] = value [dps]

		double converter = 0.001;
		double accMultiplier = 0.061;
		double gyroMultiplier = 4.375;

		for(int i=0; i< 3; ++i)
		{
			mHandler->setAccMeas()[i]=intResponse[i]*accMultiplier*converter;
		}

		for(int i=0; i< 3; ++i)
		{
			mHandler->setGyroMeas()[i]=intResponse[i+3]*gyroMultiplier*converter;
		}

		//qDebug() << "Acc: " << mHandler->getAccMeas()[0] << " g " << mHandler->getAccMeas()[1] << " g " << mHandler->getAccMeas()[2] << " g";
		//qDebug() << "Gyro: " << mHandler->getGyroMeas()[0] << " dps " << mHandler->getGyroMeas()[1] << " dps " << mHandler->getGyroMeas()[2] << " dps";

		mHandler->pushTime(50.0f * 0.001f *(mHandler->getTime()->size()+1));

		mHandler->pushXAcc(mHandler->getAccMeas()[0]);
		mHandler->pushYAcc(mHandler->getAccMeas()[1]);
		mHandler->pushZAcc(mHandler->getAccMeas()[2]);

		mHandler->pushXAngVel(mHandler->getGyroMeas()[0]);
		mHandler->pushYAngVel(mHandler->getGyroMeas()[1]);
		mHandler->pushZAngVel(mHandler->getGyroMeas()[2]);
	}
}
