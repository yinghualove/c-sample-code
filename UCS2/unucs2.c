#include <stdio.h>
#include <stdlib.h>
#include <iconv.h>
#include <string.h>

int main() {
    char *input = "世界";
    char output[10];  // 存放转换后的结果
    size_t inlen = strlen(input);
    printf("inlen=%ld\n",inlen);
    size_t outlen = sizeof(output);

    // 创建转换描述符
    iconv_t cd = iconv_open("UCS-2", "UTF-8");
    if (cd == (iconv_t)-1) {
        perror("iconv_open");
        exit(1);
    }

    // 进行转换
    char *inbuf = input;
    char *outbuf = output;
    if (iconv(cd, &inbuf, &inlen, &outbuf, &outlen) == (size_t)-1) {
        perror("iconv");
        exit(1);
    }

    // 关闭转换描述符
    iconv_close(cd);

    // 输出转换结果
    for (int i = 0; i < 4; i+=2) {
        printf("0x%02X%02X ", (unsigned char)output[i+1], (unsigned char)output[i]);       
    }
    printf("\n");
    
    return 0;
}
