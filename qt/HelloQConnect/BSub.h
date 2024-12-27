#pragma once

#include "IBase.h"

class IBase;

namespace B
{

class BSub : public IBase
{
	Q_OBJECT
public slots:
	virtual void onSayHello();
};

}
