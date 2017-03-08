#include "video.h"
#include "ui_video.h"
#include <QtMultimedia/QMediaPlayer>
#include <QtMultimediaWidgets/QVideoWidget>
#include <opencv/cv.h>
#include <opencv/highgui.h>
using namespace cv;
Video::Video(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Video)
{
    ui->setupUi(this);
    puntaje=0;
    what=0;
    Mat imagen=imread("C:/Users/Patricio/Desktop/Media/DansketballMen.jpg");
    cv::resize(imagen,imagen,cv::Size(202,202));
    //cv::pyrDown(imagen,im
    //cv::pyrDown(imagen,imagen);agen);
    int stepB= imagen.step,channelsB=imagen.channels();
    const uchar *qimagenuffer = (const uchar*)imagen.data;
    // Create QImage with same dimensions as input Mat
    QImage imagef(qimagenuffer, imagen.cols, imagen.rows, imagen.step, QImage::Format_RGB888);
    imagef=imagef.rgbSwapped();
    QLabel *label = new QLabel;
    label->setPixmap(QPixmap::fromImage(imagef));
    ui->scrollArea_2->setWidget(label);
}

Video::~Video()
{
    delete ui;
}

void Video::mostrar(int ptje){
    puntaje=ptje;
    QString ptj = QString::number(puntaje);
    ui->label->setText("Puntaje Final: "+ptj);
}

void Video::on_pushButton_2_clicked()//salir
{
    what=2;
}

void Video::on_pushButton_clicked()//reiniciar
{
    what=1;
}
void Video::mostrar(QVideoWidget *videowidget){
    ui->scrollArea->setWidget(videowidget);
}
void Video::pantalla(){
    Video::setGeometry(0,0,w,h);
    ui->scrollArea->setGeometry(-2,-2,w+3,h+4);
}
