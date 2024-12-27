
#include <QApplication>
#include <QWidget>
#include <QtMultimediaWidgets>
#include <QMimeData>
#include <QMediaPlayer>

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

    QMediaPlayer* player = new QMediaPlayer;

    // ����һ�����������ڣ�Widget����������ʾMediaPlayer
    QVideoWidget * vw = new QVideoWidget;

    // ��player�󶨵���ʾ�Ĵ�����
    player->setVideoOutput(vw);

    // �򿪲�������λ��
    player->setMedia(QUrl::fromLocalFile("D:\\Data\\Data\\20240126\\140559\\@Video@\\Video@2024_0125_140519_962(0).avi"));

    vw->show();
    return app.exec();
}