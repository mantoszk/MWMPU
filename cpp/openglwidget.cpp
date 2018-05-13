#include "openglwidget.h"

#define VERTEX_COORD_ATTRIBUTE 0
#define TEXTURE_COORD_ATTRIBUTE 1

OpenGLWidget::OpenGLWidget(QWidget *parent)
	:QOpenGLWidget(parent), bgColor(this->palette().background().color()), program(nullptr), model(new WireframeModel), texture(nullptr)
{
	rotation = QVector <double> (3, 0.0);
	distance = QVector <double> (3, 0.0);
}

OpenGLWidget::~OpenGLWidget()
{
	makeCurrent();

	vbo.destroy();
	delete model;
	delete texture;
	delete program;

	doneCurrent();
}

void OpenGLWidget::updateRotation(const QVector <double> nRotation)
{
	rotation = nRotation;
}

void OpenGLWidget::updateDistance(const QVector<double> nDistance)
{
	distance = nDistance;
}

void OpenGLWidget::initializeGL()
{
	initializeOpenGLFunctions();
	createObject();

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
	glEnable(GL_LIGHTING);
	glEnable(GL_COLOR_MATERIAL);

	program = new QOpenGLShaderProgram(this);
	if(program->addShaderFromSourceFile(QOpenGLShader::Vertex, ":/shaders/basicshader.vert"))
	{
		qDebug() << "Vertex shader loaded";
	}
	else
	{
		qDebug() << "Unable to load vertex shader";
		close();
	}
	if(program->addShaderFromSourceFile(QOpenGLShader::Fragment,":/shaders/basicshader.frag"))
	{
		qDebug() << "Fragment shader loaded";
	}
	else
	{
		qDebug() << "Unable to load vertex fragment";
		close();
	}

	program->bindAttributeLocation("vertex", VERTEX_COORD_ATTRIBUTE);
	program->bindAttributeLocation("texCoord", TEXTURE_COORD_ATTRIBUTE);
	program->link();

	program->bind();
	program->setUniformValue("texture", 0);
}

void OpenGLWidget::paintGL()
{
	glClearColor(bgColor.redF(), bgColor.greenF(), bgColor.blueF(), bgColor.alphaF());
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	QMatrix4x4 matrix;
	matrix.perspective(60.0f, 4.0f/3.0f, 0.1f, 100.0f);
	matrix.translate(0.0f,0.0f,-1.0f);
	matrix.translate(-distance[1] * 0.01f ,0.0f,distance[0] * 0.01f);

	matrix.rotate(rotation[0], 0.0f, 0.0f, -1.0f);
	matrix.rotate(rotation[1], 1.0f, 0.0f, 0.0f);
	matrix.rotate(rotation[2], 0.0f, -1.0f, 0.0f);

	program->setUniformValue("matrix", matrix);

	program->enableAttributeArray(VERTEX_COORD_ATTRIBUTE);
	program->enableAttributeArray(TEXTURE_COORD_ATTRIBUTE);

	program->setAttributeBuffer(VERTEX_COORD_ATTRIBUTE, GL_FLOAT, 0, 3, 5 * sizeof(GLfloat));
	program->setAttributeBuffer(TEXTURE_COORD_ATTRIBUTE, GL_FLOAT, 3 * sizeof(GLfloat), 2, 5 * sizeof(GLfloat));

	texture->bind();
	glDrawArrays(GL_TRIANGLES, 0, model->getSize());
}

void OpenGLWidget::resizeGL(int width, int height)
{
	glViewport(0, 0, width, height);
}

void OpenGLWidget::createObject()
{
	if(!model->LoadObject(":/models/arduino.obj"))
	{
		qDebug() << "Error opening model's file for reading";
	}
	else
	{
		qDebug() << "Model's file opened successfully";

		texture = new QOpenGLTexture(QImage(QString(":/images/DefaultMaterial_Base_Color.png")).mirrored());

		vbo.create();
		vbo.bind();
		vbo.allocate(model->getData()->constData(), model->getSize() * sizeof(GLfloat));
	}
}
