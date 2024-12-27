#include "HelloQConnect.h"

#include "QsLog.h"

#include "IBase.h"
#include "Factory.h"

#include <QPushButton>

#include <iostream>

HelloQConnect::HelloQConnect(QDialog* parent)
	: QDialog(parent)
{
	initUi();

	subA = Factory::create(Type::TypeA);
	subB = Factory::create(Type::TypeB);
	connect(this, &HelloQConnect::sigSayHello, subA.get(), &IBase::onSayHello);
	connect(this, &HelloQConnect::sigSayHello, subB.get(), &IBase::onSayHello);

	connect(this, &HelloQConnect::sigSayBye, subA.get(), &IBase::onSayBye);
	connect(this, &HelloQConnect::sigSayBye, subB.get(), &IBase::onSayBye);
}

void HelloQConnect::initUi()
{
	QPushButton* btnHello = new QPushButton(this);
	btnHello->setText("Hello");
	connect(btnHello, &QPushButton::clicked, this, &HelloQConnect::helloQt);
	
}

void HelloQConnect::helloQt()
{
	qDebug() << "HelloQConnect:hello";
	emit sigSayHello();
	emit sigSayBye();
}
