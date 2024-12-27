#include "HelloMutex.h"
#include "ui_HelloMutex.h"

#include "App.h"
#include <QString>
#include <QtConcurrent>

HelloMutex::HelloMutex(QDialog* parent)
	: QDialog(parent)
	, ui(new Ui::HelloMutex)
	, mCnt(0)
{
	ui->setupUi(this);

	mTimer = new QTimer(this);
	mTimer->setInterval(10);
	connect(mTimer, &QTimer::timeout, this, &HelloMutex::writeOne);

	mThread = new Thread();
	connect(mThread, &Thread::readOne, this, &HelloMutex::readOne);
	connect(&mParse, &QTimer::timeout, this, &HelloMutex::parseOut);
}

HelloMutex::~HelloMutex()
{
	delete ui;
}

void HelloMutex::writeOne()
{
	static size_t cnt = 0;
	App::sList.append(QString::number(cnt++));
}

void HelloMutex::readOne(QString txt)
{
	ui->txtOut->append(txt);
}

void HelloMutex::on_btnAppend_clicked()
{
	App::sList.append(ui->txtIn->toPlainText());
}

void HelloMutex::on_btnThread_clicked()
{
	if (ui->btnThread->text() == "Start thread")
	{
		mThread->start();
		ui->btnThread->setText("Stop thread");
		ui->txtOut->append("Start thread ok");
	}
	else
	{
		mThread->stop();
		ui->btnThread->setText("Start thread");
		ui->txtOut->append("Stop thread ok");
	}
}

void HelloMutex::on_btnTimer_clicked()
{
	if (ui->btnTimer->text() == "Start timer")
	{
		mTimer->start();
		ui->btnTimer->setText("Stop timer");
		ui->txtOut->append("Start timer ok");
	}
	else
	{
		mTimer->stop();
		ui->btnTimer->setText("Start timer");
		ui->txtOut->append("Stop timer ok");
	}
}

void HelloMutex::parseProc()
{
	while (true)
	{
		mMutex.lock();
		mCnt++;
		mCondition.wait(&mMutex);
		mMutex.unlock();
		if (mFuture.isCanceled())
		{
			break;
		}
	}
}

void HelloMutex::parseOut()
{
	mMutex.lock();
	ui->txtParse->append(QString::number(mCnt));
	mCondition.wakeAll();
	mMutex.unlock();
}

void HelloMutex::on_btnStartParse_clicked()
{
	if (!mParse.isActive())
	{
		mParse.start();
	}

	if (mFuture.isFinished())
	{
		mFuture = QtConcurrent::run(this, &HelloMutex::parseProc);
	}
}

void HelloMutex::on_btnStopParse_clicked()
{
	if (mFuture.isRunning())
	{
		mFuture.cancel();
		mCondition.wakeAll();
		mFuture.waitForFinished();
	}

	if (mParse.isActive())
	{
		mParse.stop();
	}

}