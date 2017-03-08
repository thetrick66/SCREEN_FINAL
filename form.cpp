#include "form.h"
#include "ui_form.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <QLabel>
#include <opencv/cv.h>
#include <opencv/highgui.h>
#include <QtMultimedia/QMediaPlayer>
#include <QtMultimediaWidgets/QVideoWidget>
using namespace std;
using namespace cv;

Form::Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{

    ui->setupUi(this);
    accion=0;
}


Form::~Form()
{
    delete ui;
}

void Form::on_pushButton_clicked()
{
    accion=1;//comenzar
}

void Form::on_pushButton_2_clicked()
{
    accion=2;//configurar
}

void Form::texto(int H_MIN2, int H_MAX2, int S_MIN2, int S_MAX2, int V_MIN2, int V_MAX2){
    H_MIN = QString::number(H_MIN2);
    H_MAX = QString::number(H_MAX2);
    S_MIN = QString::number(S_MIN2);
    S_MAX = QString::number(S_MAX2);
    V_MIN = QString::number(V_MIN2);
    V_MAX = QString::number(V_MAX2);
    final = "Hue min: "+H_MIN+"\n"+"Hue max: "+H_MAX+'\n'+"Saturation min: "+S_MIN+'\n'+"Saturation max: "+S_MAX+'\n'+"Value min: "+V_MIN+'\n'+"Value max: "+V_MAX;
    ui->label_2->setText(final);
}

void Form::on_pushButton_3_clicked()//guardar configuracion
{
    FILE *archivo=fopen("conf.txt","w");
    QString escritura=H_MIN+'\n'+H_MAX+'\n'+S_MIN+'\n'+S_MAX+'\n'+V_MIN+'\n'+V_MAX;
    const char *write=escritura.toLatin1().constData();

    fprintf(archivo,"%s",write);
    fclose(archivo);


}

void Form::on_pushButton_4_clicked()
{

    FILE *archivo=fopen("conf.txt","r");
    if (archivo!=NULL){
        char caracteres[100];
        int value;
        int i=0;
        while(feof(archivo)==0){

            fgets(caracteres,100,archivo);
            value=atoi(caracteres);
            switch(i)
            {
            case 0:H_MIN=QString::number(value);break;
            case 1:H_MAX=QString::number(value);break;
            case 2:S_MIN=QString::number(value);break;
            case 3:S_MAX=QString::number(value);break;
            case 4:V_MIN=QString::number(value);break;
            case 5:V_MAX=QString::number(value);break;
            }
            i+=1;
        }
        fclose(archivo);
        accion=3;
    }
}


void Form::on_pushButton_5_clicked()
{
    accion=4;
}

void Form::mostrar(QVideoWidget *videowidget){
    ui->scrollArea->setWidget(videowidget);
}
void Form::pantalla(){
    Form::setGeometry(0,0,w,h);
    ui->scrollArea->setGeometry(-2,-2,w+3,h+4);
}
