#include "screen.h"
#include "ui_screen.h"
#include <QFileDialog>
#include <QMessageBox>
#include <iostream>
#include <QImage>
#include <QLabel>
#include <QtCore>
#include <string.h>
#include <QString>
#include <QDebug>
#include <math.h>
#include <time.h>
#include "modb.h"
#include "modp.h"
#include "recb.h"
#include "sec.h"
#include "cmp.h"
#include "form.h"
#include "binary.h"
#include "video.h"
#include "dada.h"
#include <stdlib.h>
#include <QtMultimedia/QMediaPlayer>
#include <QtMultimediaWidgets/QVideoWidget>
#include <QTimer>



using namespace std;


Screen::Screen(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Screen)
{
    //QMainWindow::showFullScreen();
    QMainWindow::showMinimized();

    ui->setupUi(this);
    cv::Mat image;
    capwebcam.open(0);


    balon = cv::imread("C:/Users/Patricio/Desktop/Media/imagen2.jpeg");

    int presentacion=1;
    w=1280;
    h=720;
    div_izq=w/3;
    div_der=2*w/3;
    w_roi= ((w/3)*1/4);
    h_roi= ((w/3)*1/4);
    // espacio de 1 vez el tamaño de la imagen de la pelota
    barrapuntaje=0+h_roi;
    linea_accion=h-h_roi;
    linea_accion_media=h-w_roi/2;//mitad de balon verde
    xi=((w/3)*0.5)- w_roi/2;
    xc=xi+(w/3);
    xd=xc+(w/3);
    centro_scoreI=(w/3)*0.5;
    centro_scoreC=((w/3)*0.5)+(w/3);
    centro_scoreD=((w/3)*0.5)+(2*(w/3));
    radio_balon= h_roi/2;
    xroi1=-1,yroi1=-1;
    xroi2=-1,yroi2=-1;
    xroi3=-1,yroi3=-1;
    puntaje=0;
    Maxframecounter=5*(h-barrapuntaje)/12;
    framecounter=Maxframecounter-1;
     // aki  dnde va el 6 que seria el ERROR_MAX pero definido como constante
    Sec_actual=0; //
    roiturno = 0;
    flag_cuando = 0;
    flag_sec = -1;
    flag_suma_puntaje = 1;
    SALTO_INIT=10;
    salto=SALTO_INIT;
    SALIR=0;
    ERROR_MAX=7;
    error_counter=ERROR_MAX;
    SALTO_CAMBIO=2;
    ACIERTOS_MAX=16;
    aciertos_counter=ACIERTOS_MAX;


    player  = new QMediaPlayer;
    player2 = new QMediaPlayer;
    player3 = new QMediaPlayer;
    player4 = new QMediaPlayer;
    player5 = new QMediaPlayer;
    player6 = new QMediaPlayer;
    player7 = new QMediaPlayer;
    player8 = new QMediaPlayer;
    player9 = new QMediaPlayer;
    player->setMedia(QUrl::fromLocalFile("C:/Users/Patricio/Desktop/Media/Intro.avi"));
    player2->setMedia(QUrl::fromLocalFile("C:/Users/Patricio/Desktop/Media/Config_sound.mp3"));
    player4->setMedia(QUrl::fromLocalFile("C:/Users/Patricio/Desktop/Media/chasss.mp3"));
    player5->setMedia(QUrl::fromLocalFile("C:/Users/Patricio/Desktop/Media/malo1.mp3"));
    player6->setMedia(QUrl::fromLocalFile("C:/Users/Patricio/Desktop/Media/malo.mp3"));
    player7->setMedia(QUrl::fromLocalFile("C:/Users/Patricio/Desktop/Media/cinco.avi"));
    player8->setMedia(QUrl::fromLocalFile("C:/Users/Patricio/Desktop/Media/tres.avi"));
    player9->setMedia(QUrl::fromLocalFile("C:/Users/Patricio/Desktop/Media/uno.avi"));

    videowidget = new QVideoWidget;
    videowidget2 = new QVideoWidget;
    videowidget3 = new QVideoWidget;
    videowidget4 = new QVideoWidget;

    player->setVideoOutput(videowidget);
    player7->setVideoOutput(videowidget2);//forma
    player8->setVideoOutput(videowidget3);//configuracion
    player9->setVideoOutput(videowidget4);//puntaje
    //webeo
    /*Form *forma=new Form();
    RecB *prog = new RecB(w,h);
    prog->H_MIN = 0;
    prog->H_MAX = 256;
    prog->S_MIN = 0;
    prog->S_MAX = 256;
    prog->V_MIN = 0;
    prog->V_MAX = 256;
        ModB *bote = new ModB();
        ModP *pos = new ModP(640);
        CMP *comp = new CMP();
        SEC *sec=new SEC();
        Dada *dada=new Dada();
    forma->mostrar(videowidget2);
    forma->showFullScreen();
    player2->play();
    player7->play();*/


    RecB *prog = new RecB(w,h);
    ModB *bote = new ModB();
    ModP *pos = new ModP(640);
    CMP *comp = new CMP();
    SEC *sec=new SEC();

    prog->modificar=0;
    if (prog->modificar==0)
    {
        prog->H_MIN = 0;
        prog->H_MAX = 256;
        prog->S_MIN = 0;
        prog->S_MAX = 256;
        prog->V_MIN = 0;
        prog->V_MAX = 256;
    }
    char opt=0;
    int boteo=0;
    int cont=0;
    int cuando=0;
    int asignar=1;
    int maximize=0;
    int contador=0;
    Form *forma=new Form();
    forma->mostrar(videowidget2);
    int forma1=0;
    //forma->setVisible(false);
    forma->showMinimized();
    //forma->showFullScreen();
    Dada *dada=new Dada();
    //dada->setVisible(false);
    if (presentacion==1){
        dada->mostrar(videowidget);
        //dada->setVisible(true);
        dada->showMaximized();
        //dada->showFullScreen();
        player->play();
    }
    binary *bin=new binary();
    //bin->setVisible(false);
    bin->showMinimized();
    bin->mostrar(videowidget3);
    Video *video = new Video();
    //video->setVisible(false);
    video->showMinimized();
    video->mostrar(videowidget4);
    int comienzo=0;
    int num=0;
    forma->texto(prog->H_MIN,prog->H_MAX,prog->S_MIN,prog->S_MAX,prog->V_MIN,prog->V_MAX);

    bin->h=h;
    bin->w=w;
    forma->h=h;
    forma->w=w;
    dada->h=h;
    dada->w=w;
    video->h=h;
    video->w=w;


    //bin->pantalla();
    //dada->pantalla();
    //forma->pantalla();
    //this->pantalla();
    //video->pantalla();
    //QMainWindow::showMaximized();
    while(1 && opt!='q' && video->what!=2 && forma->accion!=4 && SALIR!=1)//video->what==2 -> 'Salir' luego de puntaje final
    {
        player2->setVolume(50);
        player3->setVolume(50);
        player4->setVolume(100);
        player5->setVolume(100);
        player6->setVolume(100);
        player7->setMuted(true);
        player8->setMuted(true);
        player9->setMuted(true);
        if(!player->state()&&comienzo==0){
            comienzo=1;
            if(presentacion==1){
            player->stop();

            //dada->setVisible(false);
            dada->showMinimized();
            dada->~Dada();

            }
            player2->play();
            //forma->setVisible(true);
            forma->showMaximized();
            //forma->showFullScreen();

        }
        if(!player7->state()){
            player7->play();
        }
        if(!player8->state()){
            player8->play();
        }
        if(!player9->state()){
            player9->play();
        }
        if(forma->accion==1)
        {
            player2->stop();
            player3->play();
            if(maximize==0)//reiniciar variables e inicio del juego
            {
                num=rand() % 7;
                if (num==0){
                    player3->setMedia(QUrl::fromLocalFile("C:/Users/Patricio/Desktop/Media/All the Small Things.mp3"));
                }
                if (num==1){
                    player3->setMedia(QUrl::fromLocalFile("C:/Users/Patricio/Desktop/Media/Click Click Boom.mp3"));
                }
                if (num==2){
                    player3->setMedia(QUrl::fromLocalFile("C:/Users/Patricio/Desktop/Media/Fat Lip.mp3"));
                }
                if (num==3){
                    player3->setMedia(QUrl::fromLocalFile("C:/Users/Patricio/Desktop/Media/Highway To Hell.mp3"));
                }
                if (num==4){
                    player3->setMedia(QUrl::fromLocalFile("C:/Users/Patricio/Desktop/Media/Holiday.mp3"));
                }
                if (num==5){
                    player3->setMedia(QUrl::fromLocalFile("C:/Users/Patricio/Desktop/Media/Rock You Like A Hurricane.mp3"));
                }
                if (num==6){
                    player3->setMedia(QUrl::fromLocalFile("C:/Users/Patricio/Desktop/Media/You Give Love A Bad Name.mp3"));
                }

                xroi1=-1,yroi1=-1;
                xroi2=-1,yroi2=-1;
                xroi3=-1,yroi3=-1;
                framecounter=Maxframecounter-1;
                //QMainWindow::setVisible(true);
                QMainWindow::showMaximized();
                //forma->setVisible(false);
                forma->showMinimized();
                //QMainWindow::showFullScreen();
                maximize=1;
            }
            capwebcam.read(fondo);
            flip(fondo,fondo,1);
            interfaz = fondo.clone();
            prog->cameraFeed = fondo.clone();

            scrn_Sec(sec);

            refresh(w,h);

            cargarInterfaz();

            prog->getBall();
            bote->getBote(prog->posy);//0:no bote, 1: bote
            pos->ubicar(prog->posx);//0:Izquierda 1:Centro 2:Derecha
            if (bote->flag_bote==1 && boteo==0 && prog->objectFound){//definir 1 solo bote
                boteo=1;
                comp->comparar(flag_cuando,flag_sec,pos->Flag_P,bote->flag_bote);

                player4->stop();
                player5->stop();
                if(comp->ptj=='o'&& asignar==1){//puedes asignar bueno
                    player4->play();
                    puntaje+=100;
                    error_counter = ERROR_MAX;
                    aciertos_counter--;
                    if(aciertos_counter==0){
                        if (salto+SALTO_CAMBIO < h_roi/2){
                            salto+=SALTO_CAMBIO;
                            aciertos_counter = ACIERTOS_MAX;
                        }
                    }
                    //vida+=1;
                    asignar=0;
                }
                if(comp->ptj=='x' && asignar==0){
                    player5->play();
                    puntaje+=-50;
                    error_counter--;
                    //vida-=1;
                }
                if(comp->ptj=='x' && asignar==1){
                    player5->play();
                     puntaje+=-50;
                     error_counter--;
                     //vida-=1;
                }
            }
            if(boteo==1){
                if (bote->flag_bote==0){
                    boteo=0;
                }
            }
            if(flag_cuando==1 && cuando==0){
                cuando=1;
                player6->stop();
            }
            if(cuando==1){
                if(flag_cuando==0){
                    cuando=0;
                    if(asignar==1){//no hubo buen bote
                         puntaje+=-50;
                         player6->play();
                         error_counter--;
                    }
                    else{
                        asignar=1;
                    }
                }
            }

            if(!prog->objectFound){//balon fuera de escena, PS
                cont+=1;
                if (cont==30){
                    contador=0;
                    while(1 && opt!='y'){
                        if(QMainWindow::isMinimized()){
                            SALIR=1;
                            break;
                        }
                        cv::resize(prog->cameraFeed,prog->cameraFeed,cv::Size(w,h));
                        interfaz = prog->cameraFeed;
                        cv::Mat roiPuntaje(interfaz, cv::Rect(0,0,interfaz.cols,interfaz.rows));

                        std::string text = "PAUSA";

                        int baseline=0;
                        int fontFace = cv::FONT_HERSHEY_SIMPLEX;
                        double fontScale = 10;
                        int thickness = 10;

                        baseline += thickness;
                        cv::Size textSize = cv::getTextSize(text, fontFace,
                                                    fontScale, thickness, &baseline);

                        // center the text
                        cv::Point textOrg((roiPuntaje.cols - textSize.width)/2,
                                      (textSize.height + roiPuntaje.rows)/2);

                        // then put the text itself
                        cv::putText(roiPuntaje, text, textOrg, fontFace, fontScale,
                                    cv::Scalar(255,0,0), thickness, 8);
                        cargarInterfaz();
                        capwebcam.read(image);
                        cv::resize(image,image,cv::Size(w,h));
                        flip(image,image,1);
                        prog->cameraFeed=image.clone();
                        prog->getBall();
                        if (prog->objectFound){
                            contador+=1;
                            if(contador==5){
                                contador=0;
                                break;
                            }
                        }
                        else{
                            contador=0;
                        }
                        opt=waitKey(2);
                    }
                    cont=0;
                }

            }

        }
        if(forma->accion==2 && forma1==0)//configurar
        {
            //bin->setVisible(true);
            bin->showMaximized();
            //bin->showFullScreen();
            prog->modificar=1;
            //forma->setVisible(false);
            forma->showMinimized();
            capwebcam.read(image);
            flip(image,image,1);
            cv::resize(image,image,cv::Size(800,450));
            prog->cameraFeed=image.clone();
            prog->getBall();
            bin->actualizar();
            prog->H_MIN = bin->H_MIN;
            prog->H_MAX = bin->H_MAX;
            prog->S_MIN = bin->S_MIN;
            prog->S_MAX = bin->S_MAX;
            prog->V_MIN = bin->V_MIN;
            prog->V_MAX = bin->V_MAX;
            bin->mostrar(prog->threshold);

        }
        if(forma->accion==2 && bin->accion==1)//fin de configurar
        {
            bin->accion=5;
            forma->accion=5;
            player2->play();
            forma->showMaximized();
            //forma->setVisible(true);
            //forma->showFullScreen();
            //bin->setVisible(false);
            bin->showMinimized();
            forma->texto(prog->H_MIN,prog->H_MAX,prog->S_MIN,prog->S_MAX,prog->V_MIN,prog->V_MAX);



        }
        if(forma->accion==3){//cargar configuracion
            prog->H_MIN = forma->H_MIN.toInt();
            prog->H_MAX = forma->H_MAX.toInt();
            prog->S_MIN = forma->S_MIN.toInt();
            prog->S_MAX = forma->S_MAX.toInt();
            prog->V_MIN = forma->V_MIN.toInt();
            prog->V_MAX = forma->V_MAX.toInt();
            forma->texto(prog->H_MIN,prog->H_MAX,prog->S_MIN,prog->S_MAX,prog->V_MIN,prog->V_MAX);
            bin->actualizarslider(prog->H_MIN,prog->H_MAX,prog->S_MIN,prog->S_MAX,prog->V_MIN,prog->V_MAX);
        }
        if(error_counter<=0){//mostrar puntaje final

            player3->stop();
            video->mostrar(puntaje);
            player2->play();
            //video->setVisible(true);
            video->showMaximized();
            //QMainWindow::setVisible(false);
            QMainWindow::showMinimized();
            //video->showFullScreen();
            forma->accion=0;
        }
        if (video->what==1){//reiniciar
            video->what=0;
            bin->accion=0;
            puntaje=0;
            maximize=0;
            salto=SALTO_INIT;
            error_counter=ERROR_MAX;
            player2->play();
            //forma->setVisible(true);
            forma->showMaximized();
            //video->setVisible(false);
            video->showMinimized();
            //forma->showFullScreen();
        }
        //delay so that screen can refresh.
        opt=waitKey(1000);
    }

    capwebcam.release();
    exit(0);

}

Screen::~Screen()
{
    delete ui;
}


void Screen::scrn_Sec(SEC *sec){

    framecounter=framecounter + salto;

    if (framecounter >= Maxframecounter){
        sec->sec_generator();
        Sec_actual=sec->sec_actual;
        //METODO PARA PEDIR SECUENCIA A SEC
        if (roiturno == 0){ //Le toca al roi1
            if (Sec_actual == 0) xroi1=xi; //Izq
            else if (Sec_actual == 1) xroi1=xc; //Centro
            else xroi1=xd; //Derecha
            yroi1=0;
        }
        else if (roiturno == 1){ //Le toca al roi2
            if (Sec_actual == 0) xroi2=xi; //Izq
            else if (Sec_actual == 1) xroi2=xc; //Centro
            else xroi2=xd; //Derecha
            yroi2=0;
        }
        else { //Le toca al roi3
            if (Sec_actual == 0) xroi3=xi; //Izq
            else if (Sec_actual == 1) xroi3=xc; //Centro
            else xroi3=xd; //Derecha
            yroi3=0;
        }
        roiturno++;
        roiturno = roiturno % 3;

        //Sec_actual++;
        //Sec_actual = Sec_actual % 3;
        framecounter = 0;
    }

    //Desplazo posiciones

    if (yroi1 != -1 )yroi1=yroi1+salto;
    if (yroi2 != -1) yroi2=yroi2+salto;
    if (yroi3 != -1) yroi3=yroi3+salto;

    //Verifico si entran a zona de accion

    if (yroi1 >= h){
        yroi1 = -1;
        flag_cuando = 0;
        flag_sec = -1;
    }
    else if (yroi1+h_roi >= linea_accion){
        flag_cuando = 1;
        if (xroi1 == xi) flag_sec = 0; //Izq
        if (xroi1 == xc) flag_sec = 1; //Centro
        if (xroi1 == xd) flag_sec = 2; //Der
    }
    if (yroi2 >= h){
        yroi2 = -1;
        flag_cuando = 0;
        flag_sec = -1;
    }
    else if (yroi2+h_roi >= linea_accion){
        flag_cuando = 1;
        if (xroi2 == xi) flag_sec = 0; //Izq
        if (xroi2 == xc) flag_sec = 1; //Centro
        if (xroi2 == xd) flag_sec = 2; //Der
    }
    if (yroi3 >= h){
        yroi3 = -1;
        flag_cuando = 0;
        flag_sec = -1;
    }
    else if (yroi3+h_roi >= linea_accion){
        flag_cuando = 1;
        if (xroi3 == xi) flag_sec = 0; //Izq
        if (xroi3 == xc) flag_sec = 1; //Centro
        if (xroi3 == xd) flag_sec = 2; //Der
    }

}


void Screen::cargarInterfaz() {
    QImage img3(cvMatToQImage(interfaz.clone()));
    ui->label->setPixmap(QPixmap::fromImage(img3));
}

void Screen::refresh(int w,int h){
    interfaz = fondo.clone();

    cv::resize(interfaz,interfaz,cv::Size(w,h));

    cv::Mat roiPuntaje(interfaz, cv::Rect(0,0,interfaz.cols,barrapuntaje-3));

    std::string text = "PUNTAJE: "+QString::number(puntaje).toStdString()+" pts"+"  "+QString::number(error_counter).toStdString();

    int baseline=0;
    int fontFace = cv::FONT_HERSHEY_PLAIN;
    double fontScale = 3;
    int thickness = 3;

    baseline += thickness;
    cv::Size textSize = cv::getTextSize(text, fontFace,
                                fontScale, thickness, &baseline);

    // center the text
    cv::Point textOrg((roiPuntaje.cols - textSize.width)/2,
                  (textSize.height + roiPuntaje.rows)/2);

    // then put the text itself
    cv::putText(roiPuntaje, text, textOrg, fontFace, fontScale,
                cv::Scalar(255,0,0), thickness, 8);

    cv::Mat roiBarraPuntaje(interfaz, cv::Rect(0,barrapuntaje-2,interfaz.cols,5));
    roiBarraPuntaje = cv::Scalar(0,0,255);

    cv::Mat roiLineaAccion(interfaz, cv::Rect(0,linea_accion-2,interfaz.cols,5));
    roiLineaAccion = cv::Scalar(0,0,255);

    cv::Mat roiZonaAccion(interfaz, cv::Rect(0,linea_accion+3,interfaz.cols,interfaz.rows-linea_accion-3));
    uchar *rZA = roiZonaAccion.data;
    int i,cols=roiZonaAccion.cols,rows=roiZonaAccion.rows;
    for (i=0;i<rows*cols*3;i++){
        rZA[i] = insatur((int)rZA[i]-30);
    }

    cv::Mat roiDivIzq(interfaz, cv::Rect(div_izq-2,barrapuntaje+3,5,interfaz.rows-(barrapuntaje+3)));
    roiDivIzq = cv::Scalar(0,0,255);

    cv::Mat roiDivDer(interfaz, cv::Rect(div_der-2,barrapuntaje+3,5,interfaz.rows-(barrapuntaje+3)));
    roiDivDer = cv::Scalar(0,0,255);

    cv::circle(interfaz, cv::Point(centro_scoreI,linea_accion_media),radio_balon,cv::Scalar(0,0,255),3);
    cv::circle(interfaz, cv::Point(centro_scoreC,linea_accion_media),radio_balon,cv::Scalar(0,0,255),3);
    cv::circle(interfaz, cv::Point(centro_scoreD,linea_accion_media),radio_balon,cv::Scalar(0,0,255),3);

    uchar *dataroi1=NULL,*dataroi2=NULL,*dataroi3=NULL;

    if ((yroi1 != -1)&&(xroi1 != -1)){
        cv::Mat roi1(interfaz,cv::Rect(xroi1,yroi1,w_roi,((h-yroi1)>=h_roi) ? h_roi : h-yroi1));
        dataroi1 = roi1.data;
    }
    if ((yroi2 != -1)&&(xroi2 != -1)){
        cv::Mat roi2(interfaz,cv::Rect(xroi2,yroi2,w_roi,((h-yroi2)>=h_roi) ? h_roi : h-yroi2));
        dataroi2 = roi2.data;
    }
    if ((yroi3 != -1)&&(xroi3 != -1)){
        cv::Mat roi3(interfaz,cv::Rect(xroi3,yroi3,w_roi,((h-yroi3)>=h_roi) ? h_roi : h-yroi3));
        dataroi3 = roi3.data;
    }



    cv::resize(balon,balon,cv::Size(w_roi,h_roi));


    uchar *databalon = balon.data;
    int j, channels=3;
    rows=h_roi;
    cols=w_roi;
    int stepbalon=balon.step;
    int stepfondo=interfaz.step;

    for (i = 0;i< rows;i++){
        for (j=0;j<cols;j++){
            if ((i+yroi1 >= barrapuntaje+3)&&(i+yroi1 < h-1)&&((yroi1 != -1)&&(xroi1 != -1))){
                if (((int)databalon[i*stepbalon+j*channels]>=220)&&((int)databalon[i*stepbalon+j*channels+1]>=220)&&((int)databalon[i*stepbalon+j*channels+2]>=220)){
                    dataroi1[i*stepfondo+j*channels] = (uchar) satur((double)dataroi1[i*stepfondo+j*channels]*1.0 + (double)databalon[i*stepbalon+j*channels]*0.0);
                    dataroi1[i*stepfondo+j*channels+1] = (uchar) satur((double)dataroi1[i*stepfondo+j*channels+1]*1.0 + (double)databalon[i*stepbalon+j*channels+1]*0.0);
                    dataroi1[i*stepfondo+j*channels+2] = (uchar) satur((double)dataroi1[i*stepfondo+j*channels+2]*1.0 + (double)databalon[i*stepbalon+j*channels+2]*0.0);
                }
                else{
                    dataroi1[i*stepfondo+j*channels] = (uchar) satur((double)dataroi1[i*stepfondo+j*channels]*0.0 + (double)databalon[i*stepbalon+j*channels]*1.0);
                    dataroi1[i*stepfondo+j*channels+1] = (uchar) satur((double)dataroi1[i*stepfondo+j*channels+1]*0.0 + (double)databalon[i*stepbalon+j*channels+1]*1.0);
                    dataroi1[i*stepfondo+j*channels+2] = (uchar) satur((double)dataroi1[i*stepfondo+j*channels+2]*0.0 + (double)databalon[i*stepbalon+j*channels+2]*1.0);
                }
            }
            if ((i+yroi2 >= barrapuntaje+3)&&(i+yroi2 < h-1)&&((yroi2 != -1)&&(xroi2 != -1))){
                if (((int)databalon[i*stepbalon+j*channels]>=220)&&((int)databalon[i*stepbalon+j*channels+1]>=220)&&((int)databalon[i*stepbalon+j*channels+2]>=220)){
                    dataroi2[i*stepfondo+j*channels] = (uchar) satur((double)dataroi2[i*stepfondo+j*channels]*1.0 + (double)databalon[i*stepbalon+j*channels]*0.0);
                    dataroi2[i*stepfondo+j*channels+1] = (uchar) satur((double)dataroi2[i*stepfondo+j*channels+1]*1.0 + (double)databalon[i*stepbalon+j*channels+1]*0.0);
                    dataroi2[i*stepfondo+j*channels+2] = (uchar) satur((double)dataroi2[i*stepfondo+j*channels+2]*1.0 + (double)databalon[i*stepbalon+j*channels+2]*0.0);
                }
                else{
                    dataroi2[i*stepfondo+j*channels] = (uchar) satur((double)dataroi2[i*stepfondo+j*channels]*0.0 + (double)databalon[i*stepbalon+j*channels]*1.0);
                    dataroi2[i*stepfondo+j*channels+1] = (uchar) satur((double)dataroi2[i*stepfondo+j*channels+1]*0.0 + (double)databalon[i*stepbalon+j*channels+1]*1.0);
                    dataroi2[i*stepfondo+j*channels+2] = (uchar) satur((double)dataroi2[i*stepfondo+j*channels+2]*0.0 + (double)databalon[i*stepbalon+j*channels+2]*1.0);
                }
            }
            if ((i+yroi3 >= barrapuntaje+3)&&(i+yroi3 < h-1)&&((yroi3 != -1)&&(xroi3 != -1))){
                if (((int)databalon[i*stepbalon+j*channels]>=220)&&((int)databalon[i*stepbalon+j*channels+1]>=220)&&((int)databalon[i*stepbalon+j*channels+2]>=220)){
                    dataroi3[i*stepfondo+j*channels] = (uchar) satur((double)dataroi3[i*stepfondo+j*channels]*1.0 + (double)databalon[i*stepbalon+j*channels]*0.0);
                    dataroi3[i*stepfondo+j*channels+1] = (uchar) satur((double)dataroi3[i*stepfondo+j*channels+1]*1.0 + (double)databalon[i*stepbalon+j*channels+1]*0.0);
                    dataroi3[i*stepfondo+j*channels+2] = (uchar) satur((double)dataroi3[i*stepfondo+j*channels+2]*1.0 + (double)databalon[i*stepbalon+j*channels+2]*0.0);
                }
                else{
                    dataroi3[i*stepfondo+j*channels] = (uchar) satur((double)dataroi3[i*stepfondo+j*channels]*0.0 + (double)databalon[i*stepbalon+j*channels]*1.0);
                    dataroi3[i*stepfondo+j*channels+1] = (uchar) satur((double)dataroi3[i*stepfondo+j*channels+1]*0.0 + (double)databalon[i*stepbalon+j*channels+1]*1.0);
                    dataroi3[i*stepfondo+j*channels+2] = (uchar) satur((double)dataroi3[i*stepfondo+j*channels+2]*0.0 + (double)databalon[i*stepbalon+j*channels+2]*1.0);
                }
            }

        }
    }


    //emit interfazLista();

}


double Screen::satur(double d){
    if (d > 255.0) return 255.0;
    return d;
}

int Screen::insatur(int i){
    if (i < 0) return 0;
    return i;
}

QImage  Screen::cvMatToQImage( const cv::Mat &inMat )
   {
      switch ( inMat.type() )
      {
         // 8-bit, 4 channel
         case CV_8UC4:
         {
            QImage image( inMat.data, inMat.cols, inMat.rows, inMat.step, QImage::Format_RGB32 );

            return image;
         }

         // 8-bit, 3 channel
         case CV_8UC3:
         {
            QImage image( inMat.data, inMat.cols, inMat.rows, inMat.step, QImage::Format_RGB888 );

            return image.rgbSwapped();
         }

         // 8-bit, 1 channel
         case CV_8UC1:
         {
            static QVector<QRgb>  sColorTable;

            // only create our color table once
            if ( sColorTable.isEmpty() )
            {
               for ( int i = 0; i < 256; ++i )
                  sColorTable.push_back( qRgb( i, i, i ) );
            }

            QImage image( inMat.data, inMat.cols, inMat.rows, inMat.step, QImage::Format_Indexed8 );

            image.setColorTable( sColorTable );

            return image;
         }

         default:
            qWarning() << "ASM::cvMatToQImage() - cv::Mat image type not handled in switch:" << inMat.type();
            break;
      }

      return QImage();
   }

void Screen::on_actionSalir_triggered()
{
    SALIR=1;
}
void Screen::pantalla(){
    Screen::setGeometry(0,0,w,h);
    ui->label->setGeometry(0,0,w,h);
}
