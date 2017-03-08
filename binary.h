#ifndef BINARY_H
#define BINARY_H
#include <opencv/cv.h>
#include <opencv/highgui.h>
#include <QWidget>
#include <QtMultimedia/QMediaPlayer>
#include <QtMultimediaWidgets/QVideoWidget>
using namespace cv;
namespace Ui {
class binary;
}

class binary : public QWidget
{
    Q_OBJECT

public:
    explicit binary(QWidget *parent = 0);
    ~binary();
    void mostrar(Mat imagen);
    void mostrar(QVideoWidget *videowidget);
    int accion;
    void actualizar();
    void actualizarslider(int H_MIN, int H_MAX,int S_MIN,int S_MAX,int V_MIN,int V_MAX);
    int H_MIN;
    int H_MAX;
    int S_MIN;
    int S_MAX;
    int V_MIN;
    int V_MAX;
    int h;
    int w;
    void pantalla();

private slots:
    void on_pushButton_clicked();

private:
    Ui::binary *ui;
};

#endif // BINARY_H
