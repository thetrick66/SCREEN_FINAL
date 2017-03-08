#include "modb.h"
#include "recb.h"
//#include <iostream>
#include <opencv/cv.h>
#include <opencv/highgui.h>
ModB::ModB()
{
    flag_bote=0;
    pies=390;
}
void ModB::getBote(int y){
    if (y>=pies){
        flag_bote=1;
    }
    else{flag_bote=0;}
}
