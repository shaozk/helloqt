#include "QLinguistWidget.h"
#include "ui_QLinguistWidget.h"

#include <QTranslator>
#include <QSettings>

QLinguistWidget::QLinguistWidget(QWidget* parent)
	: QWidget(parent)
	, ui(new Ui::QLinguistWidget)
{
	ui->setupUi(this);

	QSettings setting("Config.ini", QSettings::IniFormat);
	QString language = setting.value("Language").toString();
	if (language == "English")
	{
		ui->comboBox->setCurrentIndex(0);
	}
	if (language == "Chinese")
	{
		ui->comboBox->setCurrentIndex(1);
	}
}

QLinguistWidget::~QLinguistWidget()
{
	delete ui;
}

void QLinguistWidget::changeEvent(QEvent* event)
{
	if (event->type() == QEvent::LanguageChange) 
	{
		ui->retranslateUi(this); // ui 是界面设计器生成的对象
	}

	QWidget::changeEvent(event);

}

void QLinguistWidget::on_comboBox_currentIndexChanged(int index)
{
	QSettings setting("Config.ini", QSettings::IniFormat);
	if (index == 0)
	{
		setting.setValue("Language", "English");
	}
	else if (index == 1)
	{
		setting.setValue("Language", "Chinese");
	}
}