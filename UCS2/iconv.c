#include <stdio.h>
#include <stdlib.h>
#include <iconv.h>
#include <string.h>
#include <errno.h>

int main() {
    char input[20]; // 存放输入的汉字
    char output[40];  // 存放转换后的结果
    size_t inlen, outlen;  // 输入和输出字符的长度

    // 获取终端输入
    printf("请输入汉字：\n");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = 0; // 移除fgets获取的换行符

    inlen = strlen(input) * 3;  // 输入字符的最大长度
    outlen = inlen * 2;  // 输出字符的最大长度

    // 创建转换描述符
    iconv_t cd = iconv_open("UCS-2LE", "UTF-8");  // UCS-2LE表示UCS-2 Little Endian
    if (cd == (iconv_t)-1) {
        perror("iconv_open");
        exit(1);
    }

    // 进行转换
    char *inbuf = input;
    char *outbuf = output;
    if (iconv(cd, &inbuf, &inlen, &outbuf, &outlen) == (size_t)-1) {
        if (errno == EILSEQ) {
            fprintf(stderr, "iconv: Invalid multibyte sequence\n");
        } else if (errno == EINVAL) {
            fprintf(stderr, "iconv: Incomplete multibyte sequence\n");
        } else if (errno == E2BIG) {
            fprintf(stderr, "iconv: Output buffer is too small\n");
        } else {
            perror("iconv");
        }
        exit(1);
    }

    // 关闭转换描述符
    iconv_close(cd);

    // 输出转换结果
    for (int i = 0; i < outlen; i += 2) {
        printf("0x%02X%02X ", (unsigned char)output[i+1], (unsigned char)output[i]);  // 以16进制形式输出UCS-2编码
    }
    printf("\n");
    
    return 0;
}
