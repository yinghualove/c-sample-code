#ifndef _AT_PROCS_H
#define _AT_PROCS_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <termios.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/select.h>
#include <errno.h>
#include <fcntl.h>
#include "cmd_match.h"

int SerialPort_Open(Serial_Attr *attr);
int SerialPort_Close(Serial_Attr *attr);
int SerialPort_init(Serial_Attr *attr);
int SerialPort_send(Serial_Attr *attr,char *sbuf,int sbuf_len);
int SerialPort_recv(Serial_Attr *attr,char *rbuf,int rbuf_len,int timeout);

#endif /*_AT_PROCS_H*/