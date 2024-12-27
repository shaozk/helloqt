
#include <QApplication>
#include <QWidget>
#include <QtMultimediaWidgets>
#include <QMimeData>
#include <QMediaPlayer>
#include <QTimer>
#include <QThread>

#include "HelloQVideo.h"
#include "VideoView.h"

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

    QString videoPath = "D:\\Data\\Data\\20240126\\140559\\@Video@\\Video@2024_0125_140519_962(0).avi";
#if 1
    HelloQVideo player;
    player.setUrl(QUrl::fromLocalFile(videoPath));
    const QRect availableGeometry = QApplication::desktop()->availableGeometry(&player);
    player.resize(availableGeometry.width() / 6, availableGeometry.height() / 4);
    player.show();
#endif


    return app.exec();
}