#pragma once

#include <QWidget>
#include <QVector>

#include "Data.h"

class Widget
{
public:
	explicit Widget();
	~Widget();

	void sayHello();

private:
	QVector<int> vec;
	QVector<Data> dataVec;

};
