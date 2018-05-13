#include "wireframemodel.h"

WireframeModel::WireframeModel(): data(nullptr)
{

}

WireframeModel::~WireframeModel()
{
	if(data != nullptr)
	{
		delete data;
	}
}

bool WireframeModel::LoadObject(const QString filename)
{
	QFile file(filename);

	if(!file.open(QIODevice::ReadOnly))
	{
		return false;
	}

	QTextStream stream(&file);
	QVector <quint32> vIndices, uIndices, nIndices;

	QVector <QVector3D> bVertices, bNormals;
	QVector <QVector2D> bUvs;

	QString trash_buffer;
	float x = 0.0f, y =0.0f, z=0.0f;

	while(!stream.atEnd())
	{
		stream >> trash_buffer;

		if(trash_buffer == "#" || trash_buffer == "o" || trash_buffer == "s") //ignore commentaries and trash
		{
			trash_buffer=stream.readLine();
		}
		else if(trash_buffer == "v") // pick vertex coordinates for xyz
		{
			stream >> x >> y >> z;

			QVector3D temp(x,y,z);
			bVertices.push_back(temp);
		}
		else if(trash_buffer == "vt")
		{
			stream >> x >> y;

			QVector2D temp(x,y);
			bUvs.push_back(temp);
		}
		else if(trash_buffer == "vn")
		{
			stream >> x >> y >> z;

			QVector3D temp(x,y,z);
			bNormals.push_back(temp);
		}
		else if(trash_buffer == "f")
		{
			for(quint32 i=0; i<3; ++i) // pick indices from V/T/N format three times for one row
			{
				stream >> trash_buffer;

				QStringList trash_list = trash_buffer.split("/", QString::SkipEmptyParts);

				vIndices.push_back(trash_list[0].toUInt());
				uIndices.push_back(trash_list[1].toUInt());
				nIndices.push_back(trash_list[2].toUInt());
			}
		}
	}
	file.close();

	data = new QVector <GLfloat>;

	for(qint32 i=0; i<vIndices.size(); ++i) //sort vec3d coordinates objects in correct order
	{
		quint32 vertexIndex = vIndices[i]-1;
		auto vertex = bVertices[vertexIndex];

		quint32 uvIndex = uIndices[i]-1;
		auto uv = bUvs[uvIndex];

		//for later use maybe
		//quint32 normalsIndex = nIndices[i]-1;
		//auto normal = bNormals[normalsIndex];

		data->push_back(vertex.x());
		data->push_back(vertex.y());
		data->push_back(vertex.z());
		data->push_back(uv.x());
		data->push_back(uv.y());
	}

	return true;
}


QVector<GLfloat> *WireframeModel::getData() const
{
	return data;
}

quint32 WireframeModel::getSize() const
{
	return data->size();
}
