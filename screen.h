#ifndef SCREEN_H
#define SCREEN_H
#include "sec.h"
#include <QMainWindow>
#include <QImage>
#include <iostream>

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <QtMultimedia/QMediaPlayer>
#include <QtMultimediaWidgets/QVideoWidget>

namespace Ui {
class Screen;
}

class Screen : public QMainWindow
{
    Q_OBJECT

public:
    explicit Screen(QWidget *parent = 0);
    ~Screen();
    void scrn_Sec(SEC *Sec);
    QMediaPlayer *player;
    QMediaPlayer *player2;
    QMediaPlayer *player3;
    QMediaPlayer *player4;
    QMediaPlayer *player5;
    QMediaPlayer *player6;
    QMediaPlayer *player7;
    QMediaPlayer *player8;
    QMediaPlayer *player9;

    QVideoWidget *videowidget;
    QVideoWidget *videowidget2;
    QVideoWidget *videowidget3;
    QVideoWidget *videowidget4;
    int flag_cuando;
    int flag_sec;
    int salto;
    void pantalla();

private:
    Ui::Screen *ui;


    QTimer* tmrTimer;

    int w;
    int h;
    int barrapuntaje;
    int div_izq;
    int div_der;
    int linea_accion;
    int linea_accion_media;
    int w_roi;
    int h_roi;
    int xi;
    int xc;
    int xd;
    int puntaje;
    int radio_balon;
    int xroi1, yroi1, xroi2, yroi2, xroi3, yroi3;
    int centro_scoreI;
    int centro_scoreC;
    int centro_scoreD;
    int puntaje_salto;
    int error_counter;
    int Sec_actual;
    int framecounter;
    int Maxframecounter;
    int roiturno;
    int flag_suma_puntaje;
    int SALIR;
    int ERROR_MAX;
    int SALTO_INIT;
    int SALTO_CAMBIO;
    int ACIERTOS_MAX;
    int aciertos_counter;

    cv::VideoCapture capwebcam;
    cv::Mat fondo;
    cv::Mat balon;
    cv::Mat interfaz;
    void on_actionSalir_triggered();

private slots:
    //void cargarFondo();
   // void cargarBalon();
    void cargarInterfaz();
    //void on_pushButton_clicked();
    //void on_pushButton_2_clicked();
    //void on_pushButton_3_clicked();
    QImage cvMatToQImage( const cv::Mat &inMat );
    double satur(double d);
    int insatur(int i);
    void refresh(int w, int h);
    //void InterfazWebcam();



signals:
    //void fondoListo();
   // void balonListo();
    //void interfazLista();
    //void refrescar();
    //void repetir();
};

#endif // SCREEN_H
