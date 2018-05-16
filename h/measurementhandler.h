#ifndef MEASUREMENTHANDLER_H
#define MEASUREMENTHANDLER_H

#include <QVector>
#include <QDebug>
#include <QtMath>

/*!
 * \brief A class for storing data from sensors received from the microcontroller and handling necessary conversions
 */

class MeasurementHandler
{
public:
	MeasurementHandler();
	~MeasurementHandler();

	QVector<double> *getTime() const;
	QVector<double> *getXAcc() const;
	QVector<double> *getYAcc() const;
	QVector<double> *getZAcc() const;
	QVector<double> *getXAngVel() const;
	QVector<double> *getYAngVel() const;
	QVector<double> *getZAngVel() const;

	void pushTime(double value);
	void pushXAcc(double value);
	void pushYAcc(double value);
	void pushZAcc(double value);
	void pushXAngVel(double value);
	void pushYAngVel(double value);
	void pushZAngVel(double value);

	/*!
	 * \brief Calculates angle [deg] and distance [cm]
	 */

	void calcAngleAndDistance();

	/*!
	 * \brief Deletes angular velocity and linear acceleration data
	 */

	void clearHistoryData();

	/*!
	 * \brief Deletes rotation and distance data
	 */

	void clearRealtimeData();

	QVector <double> getAccMeas() const;
	QVector <double> &setAccMeas();
	QVector <double> getGyroMeas() const;
	QVector <double> &setGyroMeas();

	QVector <double> getAngle() const;
	QVector <double> &setAngle();
	QVector <double> getDistance() const;
	QVector <double> &setDistance();

	QVector<QVector<double> *> getVectorOfAccPointers() const;
	QVector<QVector<double> *> getVectorOfGyroPointers() const;

private:
	QVector <double> *time;
	QVector <double> *xAcc, *yAcc, *zAcc;
	QVector <double> *xAngVel, *yAngVel, *zAngVel;
	QVector <double> accMeas, gyroMeas, angle, distance, angleP, distanceP;
	QVector<QVector<double> *> vectorOfAccPointers, vectorOfGyroPointers;
};

#endif // MEASUREMENTHANDLER_H
