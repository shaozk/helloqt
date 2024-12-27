#pragma once

#include "ISetting.h"

class GeneralSetting: public ISetting
{
public:
    enum class RunMode
    {
        CALIB,              ///< �궨ģʽ
        COLLECT,            ///< �ɼ�ģʽ
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
        NO_TT,              ///< ��ת̨����
        KEYSIGHT,           ///< ����ת̨Keysight
        DARKBOX,            ///< ����ת̨
    };

    enum class Language
    {
        English,            ///< Ӣ��
        Chinese             ///< ����
    };

public:
    virtual ~GeneralSetting() {};

    virtual void save() override;
    virtual void clean() override;

protected:
    virtual void load() override;

private:
    RunMode mRunMode;                ///< ����ģʽ
    CalibMode mCalibMode;            ///< �궨ģʽ
    Turntable mTurntable;            ///< ת̨���� 
    Language mLanguage;              ///< ����
    bool mSaveLog;                   ///< ������־��־


};
