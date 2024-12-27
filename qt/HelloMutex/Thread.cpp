#include "Thread.h"
#include "App.h"

Thread::Thread()
{
	mStopped = false;
}

Thread::~Thread()
{

}

void Thread::stop()
{
	mStopped = true;
}

void Thread::run()
{
	while (!mStopped)
	{
		mMutex.lock();
		if (App::sList.count() > 0)
		{
			QString txt = App::sList.takeFirst();
			emit readOne(txt);
		}

		mMutex.unlock();
		QThread::msleep(100);
	}

	mStopped = false;
}

