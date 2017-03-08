//#include <QtGui/QApplication>
#include <QApplication>
#include "screen.h"
using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Screen w;
    w.show();
    return a.exec();
}
