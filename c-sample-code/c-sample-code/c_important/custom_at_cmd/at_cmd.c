#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char input[50]; // 定义输入字符串
    char* token;    // 定义分割字符串的指针
    int cid;        // 定义cid变量
    char apn[20];   // 定义apn变量，长度为20

    printf("Enter command (e.g. AT+FIIO=1,cmnet): ");
    fgets(input, sizeof(input), stdin); // 从命令行读取输入

    token = strtok(input, ","); // 使用逗号分割字符串
    cid = atoi(token + strlen("AT+FIIO=")); // 提取参数1并且转化为int类型
    token = strtok(NULL, ",");  // 继续分割字符串
    strcpy(apn, token);         // 复制可变参数到apn中

    printf("cid = %d\n", cid);
    printf("apn = %s\n", apn);

    return 0;
}