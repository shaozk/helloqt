#include "HelloQTableWidget.h"
#include "ui_HelloQTableWidget.h"

#include <QString>
#include <QtConcurrent>

HelloQTableWidget::HelloQTableWidget(QDialog* parent)
	: QDialog(parent)
	, ui(new Ui::HelloQTableWidget)
{
	ui->setupUi(this);

}

HelloQTableWidget::~HelloQTableWidget()
{
	delete ui;
}

void HelloQTableWidget::on_btnInit_clicked()
{
	ui->twData->clear();
	//设置列数
	ui->twData->setRowCount(10);

	//设置行数
	ui->twData->setColumnCount(2);

	ui->twData->setHorizontalHeaderLabels(QStringList() << "Angle" << "Err");
	
	for (auto i = 0; i < 10; ++i)
	{
		ui->twData->setItem(i, 0, new QTableWidgetItem(QString::number(i)));
		ui->twData->setItem(i, 1, new QTableWidgetItem(QString::number(i)));
	}
	ui->twData->show();
	ui->twData->update();
}