/*
    *等比求和
    *公式：sum = 
*/

#include <stdio.h>
#include <stdlib.h>

int Arithmetic_Sum(int a1,int n,int d)
{
    int sum;
    sum = n*a1 + n*(n-1)*d/2;
    return sum;
}

int main(int argc,char **argv)
{
    int a1,n,d;     //a1为数列首项，d为数列公差
    if(argc = 4)
    {
        a1 = atoi(argv[1]);
        n = atoi(argv[2]);
        d = atoi(argv[3]);
        printf("sum = %d\n",Arithmetic_Sum(a1,n,d));
    }
    return 0;
}