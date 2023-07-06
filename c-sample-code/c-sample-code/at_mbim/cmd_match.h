#ifndef _CMD_MATCH_H
#define _CMD_MATCH_H

#include <termios.h>
#define SERIALNAME_LEN 128
#define PORTNAME_LEN 128
#define MBIMOPTIONS_LEN 128


typedef struct _Serial_Attr {

    int               fd;        //串口文件描述符
    int               BaudRate;  //波特率
    int               DataBits;  //数据位
    char              Parity;    //奇偶校验位
    int               StopBits;  //停止位
    int               Max_Send_Len; //单次最大发送长度
    char              SerialName[SERIALNAME_LEN];  //串口名称
    struct termios    OldTermios;  //串口的原始属性
    struct termios    NewTermios;  //串口新的属性
    char              PortMode[PORTNAME_LEN];  //端口模式
    char              Portname[PORTNAME_LEN];  //端口名称
    char              mbim_options[MBIMOPTIONS_LEN];   //mbim操作集
}Serial_Attr;

typedef struct _Port_Attr{
    Serial_Attr      *serial_attr;
    char              PortMode[PORTNAME_LEN];  //端口模式
    char              Portname[PORTNAME_LEN];  //端口名称
    char              mbim_options[MBIMOPTIONS_LEN];   //mbim操作集       
}Port_Attr;

int cmd_match(int argc,char **argv);

#endif /*_CMD_MATCH_H*/