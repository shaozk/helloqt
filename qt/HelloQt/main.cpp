
#include <QApplication>
#include "HelloQt.h"
#include "HelloProperty.h"


int main(int argc, char* argv[])
{
    QApplication app(argc, argv);
    HelloProperty hello;
    hello.helloProperty();
    hello.setId(1);
    hello.setName("shaozk");
    hello.helloProperty();
    hello.setProperty("name", "shaoxuan");
    hello.setProperty("id", "2");
    hello.helloProperty();
    return app.exec();
}