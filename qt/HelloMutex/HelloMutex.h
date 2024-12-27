#pragma once

#include <QWidget>
#include <QDialog>
#include <QString>
#include <QTimer>
#include <QFuture>
#include <QWaitCondition>

#include "Thread.h"

namespace Ui
{
	class HelloMutex;
}

class HelloMutex : public QDialog
{
	Q_OBJECT
public:
	explicit HelloMutex(QDialog* parent = 0);
	~HelloMutex();

private slots:
	void writeOne();
	void readOne(QString txt);

	void parseProc();
	void parseOut();

	void on_btnAppend_clicked();
	void on_btnThread_clicked();
	void on_btnTimer_clicked();
	void on_btnStartParse_clicked();
	void on_btnStopParse_clicked();

private:
	Ui::HelloMutex* ui;
	
	QTimer* mTimer;
	Thread* mThread;

	QFuture<void> mFuture;
	QMutex mMutex;
	QTimer mParse;
	QWaitCondition mCondition;
	volatile int mCnt;

};

