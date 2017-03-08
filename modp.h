#ifndef MODP_H
#define MODP_H
//#include <iostream>
#include <opencv/cv.h>
#include <opencv/highgui.h>
class ModP
{
public:
    ModP(int W);
    int Flag_P;
    void ubicar(int x);
    int W;
};

#endif // MODP_H
