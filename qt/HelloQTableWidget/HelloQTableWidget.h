#pragma once

#include <QWidget>
#include <QDialog>
#include <QString>

namespace Ui
{
	class HelloQTableWidget;
}

class HelloQTableWidget : public QDialog
{
	Q_OBJECT
public:
	explicit HelloQTableWidget(QDialog* parent = 0);
	~HelloQTableWidget();

private slots:
	void on_btnInit_clicked();

private:
	Ui::HelloQTableWidget* ui;


};

