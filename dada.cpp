#include "dada.h"
#include "ui_dada.h"
#include <QtMultimedia/QMediaPlayer>
#include <QtMultimediaWidgets/QVideoWidget>

Dada::Dada(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Dada)
{
    ui->setupUi(this);

}

Dada::~Dada()
{
    delete ui;

}

void Dada::mostrar(QVideoWidget *videowidget){
    ui->scrollArea->setWidget(videowidget);
}
void Dada::pantalla(){
    Dada::setGeometry(0,0,w,h);
    ui->scrollArea->setGeometry(-2,-2,w+3,h+4);
}
