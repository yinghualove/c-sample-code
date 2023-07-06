#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include "systems_convert.h"

#define MAX_DATA 1024

int main(int argc,char **argv)
{
    char *data;
    int length;
    int ret;
    data = (char *)malloc(sizeof(MAX_DATA));
    memset(data,0,sizeof(data));
    printf("input data:\n");
    scanf("%s",data);
    length = strlen(data);
    ret = BintoDec(data);
    printf("ret = %d\n",ret);

    return 0;
}