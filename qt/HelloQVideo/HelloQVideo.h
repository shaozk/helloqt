/**
 * @copyright	Copyright (c) Huizhou Desay SV Automotive Co., Ltd.
 * @file 		CRCCheck.h
 * @author 		uidq5675
 * @date		2024/06/07
 * @brief 	    转台控制工具
 * @details
 */

#pragma once

#include <QDialog>
#include <QMediaPlayer>
#include <QSlider>
#include <QTimer>
#include <QPushButton>
#include "VideoView.h"


class HelloQVideo : public QWidget
{
    Q_OBJECT
public:
    HelloQVideo(QWidget* parent = nullptr);
    ~HelloQVideo();

    void setUrl(const QUrl& url);

public slots:
    void play();
    void onSliderChanged(int index);
    void onBtnPlayClicked();

private:
    QMediaPlayer* mMediaPlayer;
    VideoView* mVideoView;
    QTimer* mTimer;

    QSlider* mSlider;
    QPushButton* mBtnPlay;

};

