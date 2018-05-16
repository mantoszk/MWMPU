#ifndef OPENGLWIDGET_H
#define OPENGLWIDGET_H
#include <QWidget>
#include <QOpenGLFunctions>
#include <QOpenGLWidget>
#include <QOpenGLBuffer>
#include <QOpenGLShaderProgram>
#include <QMatrix4x4>
#include <QQuaternion>
#include <QVector>
#include <QOpenGLTexture>
#include "wireframemodel.h"

/*!
 * \brief A class that creates the OpenGL window for rendering the Arduino model in real time
 */

class OpenGLWidget : public QOpenGLWidget, protected QOpenGLFunctions
{
	Q_OBJECT

public:
	explicit OpenGLWidget(QWidget *parent = nullptr);
	~OpenGLWidget();

	/*!
	 * \brief A method used to update the angular position of a rendered object
	 * \param nRotation - xyz angular position values
	 */

	void updateRotation(const QVector <double> nRotation);

	/*!
	 * \brief A method for updating the distance of a rendered object from the center of the coordinate system
	 * \param nDistance - xyz distance values
	 */

	void updateDistance(const QVector <double> nDistance);

protected:

	/*!
	 * \brief Prepares shaders, model and its textures for rendering
	 */
	void initializeGL() override;

	/*!
	 * \brief Resizes widget
	 * \param width
	 * \param height
	 */

	void resizeGL(int width, int height) override;

	/*!
	 * \brief Draws scene
	 */

	void paintGL() override;

private:
	/*!
	 * \brief Sends the coordinates of the vertices and UV's of the object to the buffer
	 */

	void createObject();

	QColor bgColor;
	QOpenGLShaderProgram *program;
	QOpenGLBuffer vbo;

	QVector <double> rotation, distance;
	WireframeModel *model;
	QOpenGLTexture *texture;
};

#endif // OPENGLWIDGET_H
