
#include <QApplication>
#include <QTranslator>
#include <QSettings>

#include "QLinguistWidget.h"

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

	QTranslator trans;
	QSettings settings("Config.ini", QSettings::IniFormat);
	QString language = settings.value("Language").toString();
	if (language == "Chinese")
	{

		if (trans.load("./zh_CN.qm"))
		{
			QCoreApplication::installTranslator(&trans);
		}
	}

    QLinguistWidget widget;
    widget.show();

    return app.exec();
}