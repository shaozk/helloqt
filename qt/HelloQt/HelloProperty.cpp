#include "HelloProperty.h"

#include <QDebug>

HelloProperty::HelloProperty(QObject* parent)
	: QObject(parent)
	, mId(0)
	, mName("xxx")
{

}

HelloProperty::~HelloProperty()
{
}

void HelloProperty::helloProperty()
{
	qDebug() << "Hello property";
	qDebug() << "My name is " << mName;
	qDebug() << "My id is " << mId;
}

int HelloProperty::id() const
{
	return mId;
}

void HelloProperty::setId(int id)
{
	if (id != mId)
	{
		mId = id;
		emit idChanged();
	}
}

QString HelloProperty::name() const
{
	return mName;
}

void HelloProperty::setName(const QString& name)
{
	if (name != mName)
	{
		mName = name;
		emit nameChanged();
	}
}
