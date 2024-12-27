#pragma once

#include "ISetting.h"

class GeneralSetting: public ISetting
{
public:
    enum class RunMode
    {
        CALIB,              ///< 标定模式
        COLLECT,            ///< 采集模式
        RUN_MODE_NUM
    };
    enum class CalibMode
    {
        CALIB_DYNAMIC,
        CALIB_FIX,
        CALIB_MODE_NUM
    };
    enum class Turntable
    {
        NO_TT,              ///< 无转台调试
        KEYSIGHT,           ///< 暗室转台Keysight
        DARKBOX,            ///< 暗箱转台
    };

    enum class Language
    {
        English,            ///< 英文
        Chinese             ///< 中文
    };

public:
    virtual ~GeneralSetting() {};

    virtual void save() override;
    virtual void clean() override;

protected:
    virtual void load() override;

private:
    RunMode mRunMode;                ///< 运行模式
    CalibMode mCalibMode;            ///< 标定模式
    Turntable mTurntable;            ///< 转台类型 
    Language mLanguage;              ///< 语言
    bool mSaveLog;                   ///< 保存日志标志


};
