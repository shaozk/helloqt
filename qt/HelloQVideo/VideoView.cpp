#include "VideoView.h"
#include "ui_VideoView.h"

VideoView::VideoView(QWidget* parent)
	: QWidget(parent)
	, ui(new Ui::VideoView)
	, mLayout(new QVBoxLayout)
	, mFrameNum(0)
	, mVideoNum(0)
	, mOldVideoNum(0)
{
	ui->setupUi(this);
	
	mLayout->setContentsMargins(0, 0, 0, 0);
}

VideoView::~VideoView()
{
	cleanContent();
	delete ui;
	delete mLayout;
}

void VideoView::setCurTimestamp(uint32_t timestamp)
{
	// 设置当前帧时间戳，需要在onShow槽函数调用前设置
	mCurTimestamp = timestamp;
}

void VideoView::setRangeTimestamp(uint32_t startTimestamp, uint32_t endTimestamp)
{
	mStartTimestamp = startTimestamp;
	mEndTimestamp = endTimestamp;
}

void VideoView::setFrameNum(size_t frameNum)
{
	mFrameNum = frameNum;
}

void VideoView::createContent()
{
	if (mOldVideoNum != 0)
	{
		if (mVideoNum >= mOldVideoNum)
		{
			// 更新旧视频URL
			for (auto iVideo = 0; iVideo < mOldVideoNum; ++iVideo)
			{
				mVideoPlayer.at(iVideo)->setMedia(QUrl::fromLocalFile(mVideoPath.at(iVideo)));
				mVideoWidget.at(iVideo)->setVisible(true);
			}
			size_t videoNum = mVideoNum - mOldVideoNum;			// 需新增视频数
			for (auto iVideo = mOldVideoNum; iVideo < mOldVideoNum + videoNum; ++iVideo)
			{
				createVideoPlayer(mVideoPath.at(iVideo));
			}
		}
		else
		{
			// 更新旧视频URL
			for (auto iVideo = 0; iVideo < mVideoNum; ++iVideo)
			{
				mVideoPlayer.at(iVideo)->setMedia(QUrl::fromLocalFile(mVideoPath.at(iVideo)));
				mVideoWidget.at(iVideo)->setVisible(true);
			}
			size_t videoNum = mOldVideoNum - mVideoNum;			// 需删除视频数
			for (auto iVideo = mVideoNum; iVideo < mVideoNum + videoNum; ++iVideo)
			{
				hideVideoPlayer(iVideo);
			}
		}
	}
	else
	{
		for (auto iVideo = 0; iVideo < mVideoNum; ++iVideo)
		{
			createVideoPlayer(mVideoPath.at(iVideo));
		}
	}
	setLayout(mLayout);

	mOldVideoNum = mVideoNum;

}

void VideoView::cleanContent()
{

	for (auto widget : mVideoWidget)
	{
		mLayout->removeWidget(widget);
		widget->deleteLater();
	}
	for (auto player : mVideoPlayer)
	{
		player->deleteLater();
	}
	mVideoWidget.clear();
	mVideoPlayer.clear();
	mOldVideoNum = 0;
}

void VideoView::hideContent()
{
	for (auto widget : mVideoWidget)
	{
		widget->setVisible(false);
	}
}

void VideoView::createVideoPlayer(const QString& videoPath)
{
	auto videoWidget = new QVideoWidget(this);
	videoWidget->setMinimumWidth(280);
	videoWidget->setMinimumHeight(210);
	videoWidget->setAttribute(Qt::WA_OpaquePaintEvent);
	videoWidget->setAutoFillBackground(true);
	auto videoPlayer = new QMediaPlayer(this, QMediaPlayer::VideoSurface);
	connect(videoPlayer, QOverload<QMediaPlayer::Error>::of(&QMediaPlayer::error), this, &VideoView::displayErrorMessage);
	videoPlayer->setVideoOutput(videoWidget);
	videoPlayer->setMedia(QUrl::fromLocalFile(videoPath));

	mLayout->addWidget(videoWidget);
	mVideoWidget.push_back(videoWidget);
	mVideoPlayer.push_back(videoPlayer);
}

void VideoView::hideVideoPlayer(size_t index)
{
	mVideoWidget.at(index)->setVisible(false);
}

void VideoView::playFrame(size_t frameId)
{
	
}

void VideoView::removeVideoPlayer()
{
	auto videoWidget = mVideoWidget.last();
	mLayout->removeWidget(videoWidget);
	videoWidget->deleteLater();

	auto videoPlayer = mVideoPlayer.last();
	videoPlayer->deleteLater();

	mVideoWidget.pop_back();
	mVideoPlayer.pop_back();
}

void VideoView::onShow(double frameRadio)
{
	for (auto videoPlayer : mVideoPlayer)
	{
		if (videoPlayer->state() != QMediaPlayer::PlayingState)
		{
			videoPlayer->play();
			videoPlayer->pause();
		}
		size_t buffer = round(videoPlayer->duration() * frameRadio);
		videoPlayer->setPosition(buffer);
	}
}

void VideoView::onLogPath(const QString& logPath)
{
#ifdef DEBUG_VIDEO
	static size_t cnt = 0;
	++cnt;
	mVideoPath.clear();
	if (cnt == 1)
	{
		mVideoPath.push_back("D:/uidq5675/data/radar/A02_39.8(1)_2023_0821_141219_912(0).avi");
	}
	else if (cnt == 2)
	{
		mVideoPath.push_back("D:/uidq5675/data/radar/A02_39.8(1)_2023_0821_141219_912(0).avi");
		mVideoPath.push_back("D:/uidq5675/data/radar/A02_39.8(1)_2023_0821_141219_912(1).avi");
		mVideoPath.push_back("D:/uidq5675/data/radar/A02_39.8(1)_2023_0821_141219_912(1).avi");
	}
	else if (cnt == 3)
	{
		mVideoPath.push_back("D:/uidq5675/data/radar/A02_39.8(1)_2023_0821_141219_912(0).avi");
		mVideoPath.push_back("D:/uidq5675/data/radar/A02_39.8(1)_2023_0821_141219_912(0).avi");

	}
	else if (cnt == 4)
	{
		mVideoPath.push_back("D:/uidq5675/data/radar/A02_39.8(1)_2023_0821_141219_912(0).avi");
		mVideoPath.push_back("D:/uidq5675/data/radar/A02_39.8(1)_2023_0821_141219_912(1).avi");
		mVideoPath.push_back("D:/uidq5675/data/radar/A02_39.8(1)_2023_0821_141219_912(0).avi");
		mVideoPath.push_back("D:/uidq5675/data/radar/A02_39.8(1)_2023_0821_141219_912(1).avi");
	}
	else if (cnt == 5)
	{
		mVideoPath.push_back("D:/uidq5675/data/radar/A02_39.8(1)_2023_0821_141219_912(0).avi");
		mVideoPath.push_back("D:/uidq5675/data/radar/A02_39.8(1)_2023_0821_141219_912(1).avi");
	}
	else if (cnt == 6)
	{

	}
	else if (cnt == 7)
	{
		mVideoPath.push_back("D:/uidq5675/data/radar/A02_39.8(1)_2023_0821_141219_912(0).avi");
		mVideoPath.push_back("D:/uidq5675/data/radar/A02_39.8(1)_2023_0821_141219_912(1).avi");
	}
	else
	{
		cnt = 0;
		mVideoPath.clear();
	}
	mVideoNum = mVideoPath.size();
#else
	mVideoNum = RadarTool::sGetMatchedVideoPaths(logPath, mVideoPath);

#endif

	if (mVideoNum > 0)
	{
		createContent();
		for (auto player : mVideoPlayer)
		{
			if (player->state() != QMediaPlayer::PlayingState)
			{
				player->play();
				if (player->state() == QMediaPlayer::PlayingState)
				{
					player->pause();
				}
			}
		}
	}
	else
	{
		hideContent();
	}
	
}

void VideoView::displayErrorMessage()
{
	qDebug() << "error";
}
