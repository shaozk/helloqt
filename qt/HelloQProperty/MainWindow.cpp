#include "MainWindow.h"
#include "ui_MainWindow.h"

#include <QString>
#include <QtConcurrent>

#include <QDataStream>
#include <QFile>
#include <QDebug>

#include "HelloQProperty.h"

MainWindow::MainWindow(QMainWindow* parent)
	: QMainWindow(parent)
	, ui(new Ui::MainWindow)
{
	ui->setupUi(this);

	HelloQProperty hello;

}

MainWindow::~MainWindow()
{
	delete ui;
}
