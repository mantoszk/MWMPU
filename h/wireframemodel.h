#ifndef WIREFRAMEMODEL_H
#define WIREFRAMEMODEL_H

#include <QString>
#include <QVector>
#include <QVector3D>
#include <QVector2D>
#include <QFile>
#include <QDebug>
#include <QOpenGLFunctions>

class WireframeModel
{
private:
	QVector <GLfloat> *data;

public:
	WireframeModel();
	~WireframeModel();
	bool LoadObject(const QString filename);
	QVector<GLfloat> *getData() const;
	quint32 getSize() const;
};

#endif // WIREFRAMEMODEL_H
