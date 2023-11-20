#include <stdio.h>
#include <openssl/evp.h>
#include <openssl/rand.h>
#include <string.h>

int pbkdf2_hmac_sha256(const char *password, const unsigned char *salt, int iterations, int keylen,unsigned char *out)
{
    return PKCS5_PBKDF2_HMAC(password, -1, salt, 32, iterations, EVP_sha256(), keylen, out);
}

int main()
{
    const char *password = "12345678";
    unsigned char salt[32];  // 生成一个随机的盐，长度为32字节
    memset(salt,0,strlen(salt));
    //RAND_bytes(salt, 32);
    int iterations = 1000;  // 迭代次数
    int keylen = 32;  // 生成密钥的长度，单位为字节
    unsigned char out[keylen];  // 存放生成的密钥

    if (pbkdf2_hmac_sha256(password, salt, iterations, keylen, out) != 1)
    {
        printf("Error in PBKDF2 generation\n");
        return 1;
    }

    printf("Generated Key (hex): ");
    for (int i = 0; i < keylen; i++)
    {
        printf("%02X", out[i]);
    }
    printf("\n");

    return 0;
}
