#pragma once

#include "ISetting.h"

#include <QVector>
#include <QSharedPointer>

using SettingPtr = QSharedPointer<ISetting>;
using SettingRef = ISetting&;

class Settings
{
public:
	Settings& instance();

	SettingRef setting(const QString& name);
	QStringList settingList() const;

private:
	Settings();

	void init();

	QVector<SettingPtr> mSettingVec;
};
