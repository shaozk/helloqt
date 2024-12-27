#pragma once

#include <QWidget>
#include <QMainWindow>
#include <QString>

namespace Ui
{
	class MainWindow;
}

class MainWindow : public QMainWindow
{
	Q_OBJECT
public:
	explicit MainWindow(QMainWindow* parent = 0);
	~MainWindow();


private:
	Ui::MainWindow* ui;


};

