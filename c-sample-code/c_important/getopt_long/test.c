#include <stdio.h>
#include <string.h>
#include <getopt.h>
#include <stdlib.h>
#include <malloc.h>

#define MAX_LEN 100

struct option cmd_options[]={
    {"help",no_argument,NULL,'h'},
    {"device",required_argument,NULL,'d'},
    {"mode",required_argument,NULL,'m'},
    {"baudrate",required_argument,NULL,'b'},
    {"Databits",required_argument,NULL,'D'},
    {"parity",required_argument,NULL,'p'},
    {"stopbits",required_argument,NULL,'s'},
    {"options",required_argument,NULL,'o'},
    {"command",required_argument,NULL,'c'},
    {NULL,0,NULL,0}
};

void test(int argc,char **argv)
{
    char *ch;
    ch = (char *)malloc(sizeof(MAX_LEN));
    while(1)
    {
        int opt = getopt_long(argc,argv,"hd:c:",cmd_options,NULL);
        if(opt<0)
            break;
        switch(opt)
        {
            case 'h':
            {
                printf("help\n");
                break;
            }
            case 'd':
            {
                printf("DEVICE\n");
                break;
            }
            case 'c':
            {
                printf("opt_0 = %s\n",argv[optind-1]);
                printf("opt_1 = %s\n",argv[optind]);
                printf("opt_2 = %s\n",argv[optind+1]);
                break;
            }
            default:
            {
                printf("input failure\n");
                break;
            }
        }
    }
}


int main(int argc,char **argv)
{
    test(argc,argv);

    return 0;
}
