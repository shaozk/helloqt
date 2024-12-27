#include "Settings.h"
#include "GeneralSetting.h"

static QSharedPointer<Settings> settings = nullptr;

Settings& Settings::instance()
{
	if (settings.isNull())
	{
		settings.reset(new Settings());
	}
	return *settings.data();
}

SettingRef Settings::setting(const QString& name)
{
	return *mSettingVec.at(0).data();
}

QStringList Settings::settingList() const
{
	return QStringList();
}

Settings::Settings()
{
	init();
}

void Settings::init()
{
	const QString& str1 = "General";
	const QString& str2 = "Config.ini";
	// GeneralSetting* setting = new GeneralSetting(str1);
	mSettingVec.push_back(QSharedPointer<GeneralSetting>());
}
