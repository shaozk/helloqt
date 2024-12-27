#include "HelloQProperty.h"

#include <QMetaObject>
#include <QMetaType>
#include <QMetaProperty>
#include <QStringList>

HelloQProperty::HelloQProperty(QObject* parent)
	: QObject(parent)
{
	QStringList signalList;
	auto meta = metaObject();
	auto count = meta->propertyCount();
	auto className = meta->className();
	for (auto i = 1; i < count; ++i)
	{
		auto proper = meta->property(i);
		auto classInfo = meta->classInfo(i);
		auto name = proper.name();
		auto typeName = proper.typeName();
		auto type = proper.type();
		auto userType = proper.userType();

		signalList.push_back(name);
	}


}