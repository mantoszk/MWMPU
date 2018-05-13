#include "measurementhandler.h"

MeasurementHandler::MeasurementHandler(): time(new QVector <double>), xAcc(new QVector <double>), yAcc(new QVector <double>), zAcc(new QVector <double>),
	xAngVel(new QVector <double>), yAngVel(new QVector <double>), zAngVel(new QVector <double>)
{
	vectorOfAccPointers.push_back(xAcc);
	vectorOfAccPointers.push_back(yAcc);
	vectorOfAccPointers.push_back(zAcc);

	vectorOfGyroPointers.push_back(xAngVel);
	vectorOfGyroPointers.push_back(yAngVel);
	vectorOfGyroPointers.push_back(zAngVel);


	accMeas = QVector <double> (3, 0.0);
	gyroMeas = QVector <double> (3, 0.0);
	angle = QVector <double> (3, 0.0);
	distance = QVector <double> (3, 0.0);
	angleP = QVector <double> (3, 0.0);
	distanceP = QVector <double> (3, 0.0);
}

MeasurementHandler::~MeasurementHandler()
{
	delete time;
	delete xAcc;
	delete yAcc;
	delete zAcc;
	delete xAngVel;
	delete yAngVel;
	delete zAngVel;
}

QVector<double> *MeasurementHandler::getTime() const
{
	return time;
}


QVector<double> *MeasurementHandler::getXAcc() const
{
	return xAcc;
}


QVector<double> *MeasurementHandler::getYAcc() const
{
	return yAcc;
}

QVector<double> *MeasurementHandler::getZAcc() const
{
	return zAcc;
}

QVector<double> *MeasurementHandler::getXAngVel() const
{
	return xAngVel;
}

QVector<double> *MeasurementHandler::getYAngVel() const
{
	return yAngVel;
}

QVector<double> *MeasurementHandler::getZAngVel() const
{
	return zAngVel;
}

void MeasurementHandler::pushTime(double value)
{
	time->push_back(value);
}

void MeasurementHandler::pushXAcc(double value)
{
	xAcc->push_back(value);
}

void MeasurementHandler::pushYAcc(double value)
{
	yAcc->push_back(value);
}

void MeasurementHandler::pushZAcc(double value)
{
	zAcc->push_back(value);
}

void MeasurementHandler::pushXAngVel(double value)
{
	xAngVel->push_back(value);
}

void MeasurementHandler::pushYAngVel(double value)
{
	yAngVel->push_back(value);
}

void MeasurementHandler::pushZAngVel(double value)
{
	zAngVel->push_back(value);
}

void MeasurementHandler::calcAngleAndDistance()
{
	const double deltaTime = 0.05; //s
	const double g = 9.81; //m/s^2
	const quint32 realityFactor = 2.5;

	for(quint32 i = 0; i <3; ++i)
	{
		angleP[i] = gyroMeas[i] * deltaTime * realityFactor;
		distanceP[i] = 0.5 * accMeas[i] * deltaTime * deltaTime * g * 100;

		if(angleP[i] > 0.1 || angleP[i]< -0.1)
		{
			angle[i] += angleP[i]; //deg
		}
		if(distanceP[i] > 0.1 || distanceP[i] < -0.1)
		{
			distance[i] += distanceP[i]; //cm
		}
	}
}

void MeasurementHandler::clearHistoryData()
{
	time->clear(); time->squeeze();
	xAcc->clear(); xAcc->squeeze();
	yAcc->clear(); yAcc->squeeze();
	zAcc->clear(); zAcc->squeeze();
	xAngVel->clear(); xAngVel->squeeze();
	yAngVel->clear(); yAngVel->squeeze();
	zAngVel->clear(); zAngVel->squeeze();
}

void MeasurementHandler::clearRealtimeData()
{
	angle = QVector <double> (3, 0.0);
	distance = QVector <double> (3, 0.0);
	angleP = QVector <double> (3, 0.0);
	distanceP = QVector <double> (3, 0.0);
}

QVector<double> MeasurementHandler::getAccMeas() const
{
	return accMeas;
}

QVector<double> &MeasurementHandler::setAccMeas()
{
	return accMeas;
}

QVector<double> MeasurementHandler::getGyroMeas() const
{
	return gyroMeas;
}

QVector<double> &MeasurementHandler::setGyroMeas()
{
	return gyroMeas;
}

QVector <double> MeasurementHandler::getAngle() const
{
	return angle;
}

QVector<double> &MeasurementHandler::setAngle()
{
	return angle;
}

QVector<double> MeasurementHandler::getDistance() const
{
	return distance;
}

QVector<double> &MeasurementHandler::setDistance()
{
	return distance;
}

QVector<QVector<double> *> MeasurementHandler::getVectorOfAccPointers() const
{
	return vectorOfAccPointers;
}

QVector<QVector<double> *> MeasurementHandler::getVectorOfGyroPointers() const
{
	return vectorOfGyroPointers;
}
