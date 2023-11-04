#include <stdio.h>
#include <stdint.h>
#include <locale.h>

void ucs2_decode(const uint8_t* encoded, size_t encoded_length) {
    setlocale(LC_CTYPE, ""); // 设置本地化环境

    for (size_t i = 0; i < encoded_length; i += 2) {
        uint16_t c = (encoded[i] << 8) | encoded[i+1]; // 合并两个字节为一个UCS2字符
        printf("%lc", c); // 打印UCS2字符
    }

    printf("\n");
}

int main() {
    const uint8_t encoded[] = {0x80, 0x66, 0x6E, 0x90, 0x1A, 0x00, 0x55, 0x00, 0x53, 0x00, 0x49, 0x00, 0x4D, 0x53, 0x61, 0x00, 0x20, 0x00, 0x56, 0x00, 0x32, 0x00, 0x2E, 0x00, 0x30, 0x00, 0x41, 0x00, 0x27};
    size_t encoded_length = sizeof(encoded);

    ucs2_decode(encoded, encoded_length);

    return 0;
}
