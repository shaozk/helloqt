
#include <QApplication>
#include <QWidget>
#include <QtMultimediaWidgets>
#include <QMimeData>
#include <QMediaPlayer>

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

    QMediaPlayer* player = new QMediaPlayer;

    // 创建一个播放器窗口（Widget），用于显示MediaPlayer
    QVideoWidget * vw = new QVideoWidget;

    // 将player绑定到显示的窗口上
    player->setVideoOutput(vw);

    // 打开播放器的位置
    player->setMedia(QUrl::fromLocalFile("D:\\Data\\Data\\20240126\\140559\\@Video@\\Video@2024_0125_140519_962(0).avi"));

    vw->show();
    return app.exec();
}