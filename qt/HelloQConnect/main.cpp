
#include <QApplication>
#include "HelloQConnect.h"

#include <QDebug>

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);
    HelloQConnect hello;
    hello.show();
    return app.exec();
}