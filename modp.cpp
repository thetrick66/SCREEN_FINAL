#include "modp.h"
//#include <iostream>
#include <opencv/cv.h>
#include <opencv/highgui.h>
ModP::ModP(int W)
{
    Flag_P=0;
    this->W=W;

}

void ModP::ubicar(int x){
    if (x<=W/3){
        Flag_P=0;
    }
    else if(x>W/3 && x<=2*W/3){
        Flag_P=1;
    }
    else{
        Flag_P=2;
    }
}
