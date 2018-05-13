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

class OpenGLWidget : public QOpenGLWidget, protected QOpenGLFunctions
{
	Q_OBJECT

public:
	explicit OpenGLWidget(QWidget *parent = nullptr);
	~OpenGLWidget();
	void updateRotation(const QVector <double> nRotation);
	void updateDistance(const QVector <double> nDistance);

protected:
	void initializeGL() override;
	void resizeGL(int width, int height) override;
	void paintGL() override;

private:
	void createObject();

	QColor bgColor;
	QOpenGLShaderProgram *program;
	QOpenGLBuffer vbo;

	QVector <double> rotation, distance;
	WireframeModel *model;
	QOpenGLTexture *texture;
};

#endif // OPENGLWIDGET_H
