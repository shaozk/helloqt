#include "MainWindow.h"
#include "ui_MainWindow.h"

#include <QString>
#include <QtConcurrent>

#include <QDataStream>
#include <QFile>
#include <QDebug>

#include "Widget.h"

MainWindow::MainWindow(QMainWindow* parent)
	: QMainWindow(parent)
	, ui(new Ui::MainWindow)
{
	ui->setupUi(this);

	Widget w;
	w.sayHello();
	

}

MainWindow::~MainWindow()
{
	delete ui;
}
