#include "serial.h"
#include <stdio.h>

int mbim_serial_open(serial_t *serial){
    //serial_t *serial = (serial_t *)calloc(1,sizeof(serial_t));
    //memset(serial,0,sizeof(serial_t));
    char *devname = "/dev/ttyUSB4";
    strcpy(serial->SerialName,devname);
    printf("serial name=%s\n",serial->SerialName);
    long baudrate = 921600;
    char *conf = NULL;
    serial_open(serial, devname, baudrate, conf /*"8N1N"*/);
   
}

int mbim_serial_send(serial_t *serial){
    //serial_t *serial = (serial_t *)calloc(1,sizeof(serial_t));
    //memset(serial,0,sizeof(serial_t));
    char *sbuf = "AT";
    int sbuf_len = 120;
    serial_send(serial, sbuf, sbuf_len);
}

int mbim_serial_recv(serial_t *serial){
    char *rbuf;
    int rbuf_len = 512;
    int timeout = 0;
    serial_recv(serial->fd,rbuf,rbuf_len,timeout);
}
int mbim_serial_close(serial_t *serial){
    serial_close(serial);
}

int main(int arcg,char **argv){
    //struct serial_t *serial;
    serial_t *serial = (serial_t *)calloc(1,sizeof(serial_t));
    memset(serial,0,sizeof(serial_t));
    //serial->fd = mbim_serial_open(serial);
    mbim_serial_open(serial);
    mbim_serial_send(serial);
    mbim_serial_recv(serial);
    mbim_serial_close(serial);


    return 0;
}
