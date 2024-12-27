#include "ISetting.h"


ISetting::ISetting(const QString& name, const QString& configName)
	: mName(name)
{
	QFile file(configName);
	if (!file.exists())
	{
		file.open(QIODevice::WriteOnly);
		file.close();
	}
	mSettings.reset(new QSettings(configName, QSettings::IniFormat));
}

inline QString ISetting::name() const
{
	return mName;
}

inline void ISetting::setName(const QString& name)
{
	mName = name;
}

void ISetting::save()
{
}



inline void ISetting::reload()
{
	clean();
	load();
}