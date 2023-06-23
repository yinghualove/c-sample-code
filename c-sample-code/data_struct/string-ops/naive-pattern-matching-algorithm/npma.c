/*
 *朴素模式匹配算法
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
 *返回字符串T在主串S中第pos个字符之后的位置，若不存在，则返回值为0
 *T非空，1<=pos<=strlength(S)
 */
int npma(char *S, char *T, int pos)
{
    int i = pos;       //i用于主串S中当前位置下标，若pos不为0，则从pos位置开始匹配
    int j = 0;         //用于子串T中当前位置下标值

    while (i <= strlen(S) && j <= strlen(T)) //若i小于S长度且j小于T的长度时循环
    {
        if (S[i] == T[j]) //两字母相等则继续
        {
            ++i;
            ++j;
        }
        else             //指针后退重新开始匹配
        {
            i = i - j + 1;   //i回退到上次匹配首位的下一位
            j = 0;           //j回退到子串T的首位
        }
    }
    if (j > strlen(T))   
        return i - strlen(T);
    else
        return 0;
}

int main(int argc, char **argv)
{
    char str_S[] = "goodgoogle";
    char str_T[] = "google";
    int ret;
    printf("str_s = %s\n", str_S);
    printf("str_t = %s\n", str_T);

    ret = npma(str_S, str_T, 0);
    printf("the pos=%d\n", ret);
    return 0;
}