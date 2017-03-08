#include "sec.h"
#include <stdlib.h>

SEC::SEC()
{
    sec_prox = ((rand() % 2) == 0) ? 0 : 2;
    flag = 1;
    sec_actual = sec_prox;
}

void SEC::sec_generator(){
    if (flag){
        num=(rand() % 5)+1;
        sec_actual = sec_prox;
        //if (sec_actual == 0) sec_actual = 2;
        //else if (sec_actual == 2) sec_actual = 0;
        flag = 0;
    }

    if ((num == 0)&&(sec_actual != 1)){
        flag = 1;
        if (sec_actual == 0) sec_prox = 2;
        if (sec_actual == 2) sec_prox = 0;
        sec_actual = 1;
    }
    else {
        num--;
    }
}
