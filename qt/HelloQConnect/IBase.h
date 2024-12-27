#pragma once

#include <QObject>

#include <QDebug>

class QObject;

class IBase : public QObject
{
	Q_OBJECT

public slots:
	virtual void onSayHello() = 0;

	void onSayBye() {
		qDebug() << "IBase:bye";
	}
};