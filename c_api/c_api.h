#ifndef _C_API_H
#define _C_API_H

#include <stdio.h>
#include <err.h>
#include <stdlib.h>
#include <malloc.h>

#define MALLOC(p,TYPE,SIZE) \
    if(!(p) = (TYPE)malloc(SIZE)){\
        fprintf(stderr,"Insufficient_memory"); \
        exit(EXIT_FAILURE); \
    }

#endif _C_API_H