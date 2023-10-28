//题目：一个整数，它加上100后是一个完全平方数，再加上168又是一个完全平方数，请问该数是多少？
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(int argc,char **argv)
{
    long int num , sum1 , sum2;
    for(num = 1; num < 10000; num++)
    {
        sum1 = sqrt(num + 100);
        sum2 = sqrt(num + 100 + 168);
        if(sum1 * sum1 == num + 100 && sum2 * sum2 == num + 100 + 168)
            printf("该数是：%ld\n",num);
    }
    return 0;
}