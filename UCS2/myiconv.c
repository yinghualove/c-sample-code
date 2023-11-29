#include <stdio.h>
#include <stdlib.h>
#include <iconv.h>
#include <string.h>
#include <errno.h>
#include <stdbool.h>
#include "assert_coding.h"


#define INPUT_MAX_LEN 200

int encoding()
{
     char *input; // 存放输入的汉字
    char *output;  // 存放转换后的结果
    char coding[10];  //存放编码格式
    size_t inlen, outlen;  // 输入和输出字符的长度
    
    input = (char *)malloc(INPUT_MAX_LEN);
    memset(input,0,strlen(input));
    memset(coding,0,strlen(coding));

    // 获取终端输入
    printf("input chinese:\n"); 
    scanf("%s",input);  

    inlen = strlen(input) ;  // 输入字符的最大长度
    printf("input size =%d\n",inlen);
    outlen = inlen * 3;  // 输出字符的最大长度
    output = (char *)malloc(outlen);
    memset(output,0,strlen(output));

    // 创建转换描述符
    iconv_t cd = iconv_open("UCS-2LE", "GBK");  // UCS-2LE表示UCS-2 Little Endian
    if (cd == (iconv_t)-1) {
        perror("iconv_open");
        exit(1);
    }

    // 进行转换
    char *inbuf = input;
    char *outbuf = output;
    if (iconv(cd, &inbuf, &inlen, &outbuf, &outlen) == (size_t)-1) {
        exit(1);
    }

    // 关闭转换描述符
    iconv_close(cd);

    // 输出转换结果
    printf("encoding result:0x");
    for (int i = 0; i < outlen/2; i += 2) {
        printf("%02X%02X", (unsigned char)output[i+1], (unsigned char)output[i]);  // 以16进制形式输出UCS-2编码
    }
    printf("\n");
    free(input);
    free(output);

    return true;
}

int decode()
{
    printf("TODO\n");
    return true;
}

int main()
{
    char options[20];
    memset(options,0,strlen(options));

    printf("input your option:\n");
    scanf("%s",&options);

    if(strncmp(options,"encoding",10) == 0)
        encoding();                          //执行编码
    if(strncmp(options,"decode",8) == 0)
        decode();                           //执行解码
    
    return 0;
}
