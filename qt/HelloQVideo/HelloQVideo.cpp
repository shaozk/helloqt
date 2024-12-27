#include "HelloQVideo.h"

#include <QVideoWidget>
#include <QBoxLayout>
#include <QThread>


HelloQVideo::HelloQVideo(QWidget* parent)
    : QWidget(parent)
    , mTimer(new QTimer())
{
#if 0
    mMediaPlayer = new QMediaPlayer(this, QMediaPlayer::VideoSurface);
    QVideoWidget* videoWidget = new QVideoWidget;

    QBoxLayout* layout = new QVBoxLayout;
    layout->addWidget(videoWidget);

    setLayout(layout);

    mMediaPlayer->setVideoOutput(videoWidget);
#else
   
    mVideoView = new VideoView;
    mSlider = new QSlider(Qt::Horizontal, this);
    mSlider->setRange(0, 900);
    connect(mSlider, &QSlider::valueChanged, this, &HelloQVideo::onSliderChanged);

    mBtnPlay = new QPushButton;
    connect(mBtnPlay, &QPushButton::clicked, this, &HelloQVideo::onBtnPlayClicked);

    QBoxLayout* layout = new QVBoxLayout;
    layout->addWidget(mVideoView);
    layout->addWidget(mSlider);
    layout->addWidget(mBtnPlay);
    setLayout(layout);

    connect(mTimer, SIGNAL(timeout()), this, SLOT(play()));
    
    //mTimer->start(5);
#endif
}

HelloQVideo::~HelloQVideo()
{

}

void HelloQVideo::setUrl(const QUrl& url)
{
#if 0
    mMediaPlayer->setMedia(url);
#else

#endif
}

void HelloQVideo::onSliderChanged(int index)
{
    auto radio = index * 1.0 / 900;
    mVideoView->onShow(radio);
}

void HelloQVideo::onBtnPlayClicked()
{
    mVideoView->onLogPath("");
}

void HelloQVideo::play()
{
#if 0
    switch (mMediaPlayer->state()) {
    case QMediaPlayer::PlayingState:
        mMediaPlayer->pause();
        break;
    default:
        mMediaPlayer->play();
        break;
    }
#else
    static int i = 0;
    if (i == 100)
    {
        i = 0;
    }
    else
    {
        i += 2;
    }
    mVideoView->onShow(i * 1.0 / 100);
#endif
}