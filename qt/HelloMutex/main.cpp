
#include <QApplication>
#include "HelloMutex.h"


int main(int argc, char* argv[])
{
    QApplication app(argc, argv);
    HelloMutex hello;
    hello.show();
    return app.exec();
}