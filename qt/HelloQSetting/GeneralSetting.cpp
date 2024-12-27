#include "GeneralSetting.h"



void GeneralSetting::save()
{
    /// General
    mSettings.data()->setValue("General/runMode", static_cast<int>(mRunMode));
    mSettings.data()->setValue("General/calibMode", static_cast<int>(mCalibMode));
    mSettings.data()->setValue("General/turntable", static_cast<int>(mTurntable));
    mSettings.data()->setValue("General/language", static_cast<int>(mLanguage));
    mSettings.data()->setValue("General/saveLog", mSaveLog);
}

void GeneralSetting::clean()
{

}

void GeneralSetting::load()
{
    /// General

    mRunMode = static_cast<RunMode>(mSettings.data()->value("General/runMode").toInt());
    mCalibMode = static_cast<CalibMode>(mSettings.data()->value("General/calibMode").toInt());
    mTurntable = static_cast<Turntable>(mSettings.data()->value("General/turntable").toInt());
    mLanguage = static_cast<Language>(mSettings.data()->value("General/language").toInt());
    mSaveLog = mSettings.data()->value("General/saveLog").toBool();
}
