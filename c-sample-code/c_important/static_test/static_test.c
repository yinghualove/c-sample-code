#include <stdio.h>

static int num = 10;

void modify()
{
    printf("num = %d\n",num);
    num = 30;
    printf("num = %d\n",num);
}

int main(int argc,char **argv)
{
    printf("num-v1=%d\n",num);
    modify();
    printf("numv2=%d\n",num);
    return 0;
}