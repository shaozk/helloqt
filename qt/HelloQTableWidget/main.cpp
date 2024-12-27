
#include <QApplication>
#include "HelloQTableWidget.h"


int main(int argc, char* argv[])
{
    QApplication app(argc, argv);
    HelloQTableWidget hello;
    hello.show();
    return app.exec();
}