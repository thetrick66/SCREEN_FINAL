#include "binary.h"
#include "ui_binary.h"
#include <opencv/cv.h>
#include <opencv/highgui.h>
#include <QLabel>
#include <iostream>
#include <QtMultimedia/QMediaPlayer>
#include <QtMultimediaWidgets/QVideoWidget>
using namespace std;
binary::binary(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::binary)
{
    ui->setupUi(this);
    ui->horizontalSlider->setMaximum(256);
    ui->horizontalSlider_2->setMaximum(256);
    ui->horizontalSlider_3->setMaximum(256);
    ui->horizontalSlider_4->setMaximum(256);
    ui->horizontalSlider_5->setMaximum(256);
    ui->horizontalSlider_6->setMaximum(256);
    ui->horizontalSlider->setValue(0);
    ui->horizontalSlider_2->setValue(256);
    ui->horizontalSlider_3->setValue(0);
    ui->horizontalSlider_4->setValue(256);
    ui->horizontalSlider_5->setValue(0);
    ui->horizontalSlider_6->setValue(256);
    accion=0;
    H_MIN=0;
    H_MAX=256;
    S_MIN=0;
    S_MAX=256;
    V_MIN=0;
    V_MAX=256;
}

binary::~binary()
{
    delete ui;
}
void binary::actualizar(){
    H_MIN=ui->horizontalSlider->value();
    H_MAX=ui->horizontalSlider_2->value();
    S_MIN=ui->horizontalSlider_3->value();
    S_MAX=ui->horizontalSlider_4->value();
    V_MIN=ui->horizontalSlider_5->value();
    V_MAX=ui->horizontalSlider_6->value();

    ui->label_7->setText(QString::number(H_MIN));
    ui->label_8->setText(QString::number(H_MAX));
    ui->label_9->setText(QString::number(S_MIN));
    ui->label_10->setText(QString::number(S_MAX));
    ui->label_11->setText(QString::number(V_MIN));
    ui->label_12->setText(QString::number(V_MAX));
}
void binary::actualizarslider(int H_MIN,int H_MAX,int S_MIN,int S_MAX,int V_MIN,int V_MAX)
{
    ui->horizontalSlider->setValue(H_MIN);
    ui->horizontalSlider_2->setValue(H_MAX);
    ui->horizontalSlider_3->setValue(S_MIN);
    ui->horizontalSlider_4->setValue(S_MAX);
    ui->horizontalSlider_5->setValue(V_MIN);
    ui->horizontalSlider_6->setValue(V_MAX);

}
void binary::mostrar(Mat imagen){
    //cv::pyrDown(imagen,imagen);
    int stepB= imagen.step,channelsB=imagen.channels();
    const uchar *qimagenuffer = (const uchar*)imagen.data;
    // Create QImage with same dimensions as input Mat
    QImage imagef(qimagenuffer, imagen.cols, imagen.rows, imagen.step, QImage::Format_Indexed8);
    imagef=imagef.rgbSwapped();
    QLabel *label = new QLabel;
    label->setPixmap(QPixmap::fromImage(imagef));
    ui->scrollArea->setWidget(label);
}

void binary::on_pushButton_clicked()
{
    accion=1;
}
void binary::mostrar(QVideoWidget *videowidget){
    ui->scrollArea_2->setWidget(videowidget);
}
void binary::pantalla(){
    binary::setGeometry(0,0,w,h);
    ui->scrollArea_2->setGeometry(-2,-2,w+3,h+4);

}
