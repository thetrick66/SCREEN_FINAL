#ifndef FORM_H
#define FORM_H

#include <QWidget>
#include <QtMultimedia/QMediaPlayer>
#include <QtMultimediaWidgets/QVideoWidget>

namespace Ui {
class Form;
}

class Form : public QWidget
{
    Q_OBJECT

public:
    explicit Form(QWidget *parent = 0);
    ~Form();
    int accion;
    int w;
    int h;
    void pantalla();
    void imagen();
    void texto(int H_MIN, int H_MAX, int S_MIN, int S_MAX, int V_MIN, int V_MAX);
    QString H_MIN;
    QString H_MAX;
    QString S_MIN;
    QString S_MAX;
    QString V_MIN;
    QString V_MAX;
    QString final;
    void mostrar(QVideoWidget *videowidget);


public slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();

private slots:


    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();


    void on_pushButton_5_clicked();

private:
    Ui::Form *ui;
};

#endif // FORM_H
