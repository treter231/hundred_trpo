#include <stdio.h>
#include <stdlib.h>
#include "check.h"

int check(int Num, int Count){
    if(Num>=1&&Num<=10&&Num<=Count){
        return 1;
    }else{
        return 0;
    }
}
