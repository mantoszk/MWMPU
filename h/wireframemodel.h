#ifndef WIREFRAMEMODEL_H
#define WIREFRAMEMODEL_H

#include <QString>
#include <QVector>
#include <QVector3D>
#include <QVector2D>
#include <QFile>
#include <QDebug>
#include <QOpenGLFunctions>

/*!
 * \brief A class that loads data from a file and stores it for rendering using OpenGL
 */

class WireframeModel
{
private:
	QVector <GLfloat> *data;

public:
	WireframeModel();
	~WireframeModel();
	/*!
	 * \brief A method for parsing and saving a 3D model
	 * \param[in] filename - path for file .obj, extension not included
	 * \return true if model is loaded succesfully
	 */
	bool LoadObject(const QString filename);

	/*!
	 * \brief Getter for object's data
	 * \return Pointer to object's data
	 */
	QVector<GLfloat> *getData() const;

	/*!
	 * \brief Getter for amount of stored vertices and UV's combined
	 * \return Size of data container
	 */
	quint32 getSize() const;
};

#endif // WIREFRAMEMODEL_H
