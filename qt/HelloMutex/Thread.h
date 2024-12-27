#pragma once

#include <QString>
#include <QThread>
#include <QMutex>

class Thread : public QThread
{
	Q_OBJECT
public:
	Thread();
	~Thread();

	void stop();

protected:
	void run();

private:
	QMutex mMutex;
	volatile bool mStopped;

signals:
	void readOne(QString txt);

};