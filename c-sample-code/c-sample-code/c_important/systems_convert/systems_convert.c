#include <stdio.h>
#include <string.h>
#include <math.h>
#include "systems_convert.h"

//二进制转10进制
double BintoDec(char *data)
{
    int n=0;
    int length;
    length = strlen(data);
    printf("length=%d\n",length);
    int num[10] = {0},sum = 0;
    for(int j=0;j<length;j++){
        num[j] = data[j] - '0';
        double a;
        a = pow(2,(length-j-1));
        printf("2^(%d)=%f\n",length-j-1,a);
        printf("num[%d] = %d\n",j,num[j]);
        sum = sum + num[j]*a;
        printf("sum = %d\n",sum);
    }

    return sum;
}