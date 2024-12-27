#pragma once

#include "IBase.h"

#include <QSharedPointer>

enum class Type
{
	TypeA = 0,
	TypeB = 1 
};

using BasePtr = QSharedPointer<IBase>;

class Factory
{
public:
	static BasePtr create(Type type);
};
