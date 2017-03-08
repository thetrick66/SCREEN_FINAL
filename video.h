#ifndef VIDEO_H
#define VIDEO_H

#include <QWidget>
#include <QtMultimedia/QMediaPlayer>
#include <QtMultimediaWidgets/QVideoWidget>
namespace Ui {
class Video;
}

class Video : public QWidget
{
    Q_OBJECT

public:
    explicit Video(QWidget *parent = 0);
    ~Video();
    int puntaje;
    void mostrar(int ptje);
    int what;
    void mostrar(QVideoWidget *videowidget);
    int h;
    int w;
    void pantalla();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::Video *ui;
};

#endif // VIDEO_H
