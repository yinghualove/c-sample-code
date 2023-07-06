#include <stdio.h>
#include <stdlib.h>

int main(int argc,char **argv)
{
    int sn = atoi(argv[1]);
    switch(sn){
        case 1:
        printf("1\n");
        break;
        case 2:
        printf("2\n");
        break;
        case 3:
        case 4:
        case 5:
        printf("none\n");
        break;
        default:
        break;
    }

    return 0;
}