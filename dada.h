#ifndef DADA_H
#define DADA_H

#include <QWidget>
#include <QtMultimedia/QMediaPlayer>
#include <QtMultimediaWidgets/QVideoWidget>

namespace Ui {
class Dada;
}

class Dada : public QWidget
{
    Q_OBJECT

public:
    explicit Dada(QWidget *parent = 0);
    ~Dada();
    void mostrar(QVideoWidget *videowidget);
    int h;
    int w;
    void pantalla();
private:
    Ui::Dada *ui;
};

#endif // DADA_H
