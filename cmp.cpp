#include "cmp.h"
#include <opencv/cv.h>
#include <opencv/highgui.h>
using namespace cv;
using namespace std;

CMP::CMP()
{
    ptj='A';
}
void CMP::comparar(int flag_cuando, int flag_sec,int flag_pos, int flag_bote){
    if(flag_cuando && flag_bote){
        if (flag_pos==flag_sec){
            ptj='o';//se asigna ptj por buen bote
        }
        else ptj='x';
        }
    else ptj='x';
}
