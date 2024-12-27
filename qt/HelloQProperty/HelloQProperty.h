#pragma 

#include <QObject>

class Property
{
private:
	int a;
};

Q_DECLARE_METATYPE(Property)

class HelloQProperty : public QObject
{
	Q_OBJECT
	Q_PROPERTY(int a)
	Q_PROPERTY(Property b)
	Q_PROPERTY(int* c)
public:
	explicit HelloQProperty(QObject* parent = nullptr);
private:
	int a;
	Property b;
	int c[10];
};