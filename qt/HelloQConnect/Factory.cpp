#include "Factory.h"

#include "ASub.h"
#include "BSub.h"

BasePtr Factory::create(Type type)
{
	if (type == Type::TypeA)
	{
		return BasePtr(new A::ASub());
	}
	else if (type == Type::TypeB)
	{
		return BasePtr(new B::BSub());
	}
}
