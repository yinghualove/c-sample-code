// swap big endian to little endian
#include <stdio.h>
#include <stdint.h>
#include <arpa/inet.h>
#include <endian.h>
#define a 0x4001
#define c 0x40014002
#define e 0x4001400240034004
#define VUINT32LE(a)	((a) & 0xFF),(((a)>>8) & 0xFF),(((a)>>16) & 0xFF),(((a)>>24) & 0xFF)


// uint16_t htons(uint16_t hostshort); /* host to network short */

// uint32_t htonl(uint32_t hostlong); /* host to network long */

// uint16_t ntohs(uint16_t netshort); /*network to host short */

// uint32_t ntohs(uint32_t netlong); /*network to host short */

void swap_16()
{

    printf("a=%04X\n", a);
    uint16_t b = ((0x00ff & a) << 8) | ((0xff00 & a) >> 8);
    printf("b=%04X\n", b);
}

void swap_16_point(char *buf ){
    char *p,*q;
    uint8_t w;
    p = &buf[0];
    q = &buf[1];
    w = *q;
    *q = *p;
    *p = w;
    printf("buf[0] = %02x,buf[1]=%02x\n",buf[0],buf[1]);

    
}

int swap_32()
{
    printf("c=%08X\n", c);
    uint32_t d = ((0x000000ff & c) << 24) |
                 ((0x0000ff00 & c) << 8) |
                 ((0x00ff0000 & c) >> 8) |
                 ((0xff000000 & c) >> 24);
    printf("d=%08X\n", d);
}

void swap_64()
{

    unsigned long long u64_host, u64_net;
    u64_host = 0x4001400240034004;
    unsigned int u32_host_h, u32_host_l;

    u32_host_l = u64_host & 0xffffffff;
    printf("u32_host_l = %016x\n",u32_host_l);

    u32_host_h = (u64_host >> 32) & 0xffffffff;
    printf("u32_host_h = %016x\n",u32_host_h);


    u64_net = htonl(u32_host_l);
    printf("u64_net = %16llx\n",u64_net);
    u64_net = (u64_net << 32) | htonl(u32_host_h);
    printf("u64_net = %16llx\n",u64_net);


    printf("htonll : %016llx\n", u64_net);
}

//根据联合体的特性:联合中所有成员引用的是内存中相同的位置，其长度为最长成员的长度

typedef struct {
	unsigned int u32_h;
	unsigned int u32_l;
}Int64_t;
 
typedef union {
	unsigned long long u64;
	Int64_t st64;
}Convert64_t;
 
void swap_64_uion(){ 
unsigned long long u64_host, u64_net;
Convert64_t box_in, box_out;
 
box_in.u64 = u64_host;
box_out.st64.u32_h = htonl(box_in.st64.u32_l);
box_out.st64.u32_l = htonl(box_in.st64.u32_h);
u64_net = box_out.u64;
 
printf("htonll : %016llx\n", u64_net);
}

//使用指针进行交换
void swap_64_point(){

}

int main(int argc, char **argv)
{
    printf("c = %02X\n",c);
    uint32_t i = htole32(c);
    printf("i = %02X\n",i);
    printf("d = %d\n",VUINT32LE(c));

    char *buf;
    swap_16_point(buf);
    return 0;
}
