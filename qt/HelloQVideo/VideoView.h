/**
 * @copyright	Copyright (c) Huizhou Desay SV Automotive Co., Ltd.
 * @file 		VideoView.h
 * @author 		uidq5675
 * @date		2024/01/28
 * @brief 		数据列表
 * @details     以列表形式展示点迹、航迹等信息
 */


#pragma once

#include <QWidget>
#include <QVector>
#include <QStandardItemModel>
#include <QModelIndex>
#include <QtMultimediaWidgets>
#include <QMimeData>
#include <QGridLayout>

#define DEBUG_VIDEO

namespace Ui {
    class VideoView;
}

class VideoView : public QWidget
{
    Q_OBJECT

public:

    explicit VideoView(QWidget* parent = nullptr);
    ~VideoView();

public:

    void setCurTimestamp(uint32_t timestamp);
    void setRangeTimestamp(uint32_t startTimestamp, uint32_t endTimestamp);
    void setFrameNum(size_t frameNum);

public slots:
    /**
     * @brief 显示单帧视频
     * @param frameId 帧ID
    */
    void onShow(double frameRadio);

    /**
     * @brief 设置视频路径
     * @param logPath 
    */
    void onLogPath(const QString& logPath);

    void displayErrorMessage();

private:
    /**
     * @brief 创建界面内容
    */
    void createContent();

    void cleanContent();

    void hideContent();

    /**
     * @brief 播放一帧数据
     * @param frameId
    */
    void playFrame(size_t frameId);
    void createVideoPlayer(const QString& videoPath);
    void removeVideoPlayer();
    void hideVideoPlayer(size_t index);


private:
    Ui::VideoView* ui;

    size_t mFrameNum;                      ///< 总帧数
    size_t mVideoNum;
    size_t mOldVideoNum;
    uint32_t mCurTimestamp;
    uint32_t mStartTimestamp;
    uint32_t mEndTimestamp;
    QVector<QString> mVideoPath;             ///< 数据
    QVector<QMediaPlayer*> mVideoPlayer;    ///< 视频Player
    QVector<QVideoWidget*> mVideoWidget;    ///< 视频Widget
    double mVideoTime;						///< 视频总时间
    QBoxLayout* mLayout;
};


