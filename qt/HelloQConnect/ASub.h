#pragma once

#include "IBase.h"

class IBase;

namespace A 
{

class ASub: public IBase
{
	Q_OBJECT
public slots:
	virtual void onSayHello();
};

}