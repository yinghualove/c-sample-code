#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <string.h>
#include <malloc.h>

#include "cmd_match.h"
#include "at_thread.h"

struct option cmd_options[]={
    {"help",no_argument,NULL,'h'},
    {"device",required_argument,NULL,'d'},
    {"mode",required_argument,NULL,'m'},
    {"baudrate",required_argument,NULL,'b'},
    {"Databits",required_argument,NULL,'D'},
    {"parity",required_argument,NULL,'p'},
    {"stopbits",required_argument,NULL,'s'},
    {"options",required_argument,NULL,'o'},
    {NULL,0,NULL,0}
};

//帮助信息
void help_information(){
    printf("\t-b   Set BaudRate\n");
    printf("\t-d   Set Databits\n");
    printf("\t-p   Set Parity,0 for no parity,1 for Odd parity,2 for Evev parity\n");
    printf("\t-s   Set StopBits\n");
    printf("\t-d   Set the device name of the port you want to use\n");
    printf("\t-m   Set the device mode of the port you want to use\n");
    printf("\t-o   Set mbim options\n");
    printf("\t     Ctrl + c to exit the program\n");
    printf("\n\tIf you do not specify parameters,The default parameters of the program are as follows:\n");
    printf("\tBaudRate: 1115200\n\tDatabits: 8bits\n\tParity:   no parity\n\tStopBits: 1bits\n");
}

int cmd_match(int argc,char **argv){
    Serial_Attr *attr;
    int ch;
    attr = (Serial_Attr*)malloc(sizeof(Serial_Attr));
    memset(attr,0,sizeof(Serial_Attr));
    
    while((ch = getopt_long(argc,argv,"hm:b:d:p:s:n:o:",cmd_options,NULL)) != -1)
    {
        switch(ch)
        {
            case 'h':
                help_information();
                return 0;
            case 'm':
                //attr->PortMode = optarg;
                strncpy(attr->PortMode,optarg,PORTNAME_LEN);

                printf("port mode = %s\n",attr->PortMode);
                break;


            case 'b':
                attr->BaudRate = atoi(optarg);
                break;

            case 'D':
                attr->DataBits = atoi(optarg);
                break;

            case 'p':
                attr->Parity = optarg[0];
                break;

            case 's':
                attr->StopBits = atoi(optarg);
                break;

            case 'd':
                printf("bbbbbbbbbbbbbb\n");

                strncpy(attr->Portname,optarg,PORTNAME_LEN);
                strncpy(attr->SerialName,optarg,SERIALNAME_LEN);
                printf("aaaaaaaaaaaaaaa\n");
                break;
            case 'o':
                strncpy(attr->mbim_options,optarg,MBIMOPTIONS_LEN);
                break;
                
        }
    }
     
    if(strlen(attr->Portname) == 0)
    {
        printf("Parameter warning:\n");
        printf("\tAt least need to enter the serial port name,You can specify the serial port name with -d.\n");
        return 0;
    }
    printf("------------------\n");
    if(strncmp("at",attr->PortMode,2)==0)
        create_at_thread(attr);
}

