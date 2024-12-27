#include "MainWindow.h"
#include "ui_MainWindow.h"

#include <QString>
#include <QtConcurrent>

#include <QDataStream>
#include <QFile>
#include <QDebug>

MainWindow::MainWindow(QMainWindow* parent)
	: QMainWindow(parent)
	, ui(new Ui::MainWindow)
{
	ui->setupUi(this);

	QFile file("D:\\Log\\E0X\\-65.dat");
	if (!file.exists())
	{
		qDebug() << "File don't exist";
	}
	if (!file.open(QIODevice::ReadOnly))
	{
		qDebug() << "File can't open";
	}

	QDataStream stream(&file);
	char data[100];
	stream.readRawData(data, 100);
	qDebug() << data;

}

MainWindow::~MainWindow()
{
	delete ui;
}
