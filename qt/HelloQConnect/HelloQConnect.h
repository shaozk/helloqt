
#pragma once

#include <QDialog>

#include "Factory.h"

class HelloQConnect : public QDialog
{
    Q_OBJECT

signals:
    void sigSayHello();
    void sigSayBye();

public:
    HelloQConnect(QDialog* parent = nullptr);
    void initUi();
    void helloQt();

private:
    BasePtr subA;
    BasePtr subB;
};

