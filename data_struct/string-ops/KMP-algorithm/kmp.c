/*
 *KMP模式匹配算法
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
 *求模式串T的next函数修正值并存入数组nextval
*/
void get_nextval(char *T,int *nextval)
{
    int i,j;
    i=1;
    j=0;
    nextval[1] = 0;
    //printf("strlen(T) = %d\n",strlen(T));
    while(i < strlen(T)-1)            
    {
        if(j == 0 || T[i] == T[j])  //T[i]表示后缀的单个字符，T[j]表示前缀的单个字符
        {            
            ++i;
            ++j;
            if(T[i] != T[j])       //若当前字符与前缀字符不同
                nextval[i] = j;    //则当前的j为nextval在i的位置的值
            else    
                nextval[i] = nextval[j];  //如果与前缀字符相同，则将前缀字符的nextval值赋给nextval在i位置的值
        }
        else    
            j = nextval[j];  //若字符不相同，则j值回溯
       
    }
    // for(int k=1;k<strlen(T);k++)
    //     printf("nextval[%d] = %d\n",k,nextval[k]);
}

/*
 *返回子串T在主串S中第pos个字符之后的位置，若存在，则函数返回值为0
 *T非空，1<=pos<=strlen(S)
*/
int Index_KMP(char *S,char *T,int pos)
{
    int i = pos;  //i用于主串S中当前位置下标，若pos不为0，则从pos位置开始匹配
    int j = 0;    //用于子串T中当前位置下标值
    int next[255];  //定义一next数组
    get_nextval(T,next);    //对串T作分析，得到next数组
    while(i <= strlen(S) && j<= strlen(T))  //若i小于S的长度且j小于T的长度时，循环继续
    {
        if(j == 0 || S[i] == T[j])     //两字母相等则继续，与朴素算法增加了j=0判断
        {
            ++i;
            ++j;
        }
        else              //指针后退重新开始匹配
        {
            j = next[j];  //j退回合适的位置，i值不变
        }
    }
    if(j > strlen(T)-1)
        return i-strlen(T)+1;
    else
        return 0;
}

int main(int argc, char **argv)
{
    char str_S[] = "goodgoogle";
    char str_T[] = "google";
    int s_len = strlen(str_S);
    int t_len = strlen(str_T);
    char S[s_len+1],T[t_len+1];
    S[0] = s_len;
    T[0] = t_len;

    // 将字符串各个字符依次赋值给数组S的后续位置
    for (int i = 0; i < s_len; i++) {
        S[i+1] = str_S[i];
    }
    // 将字符串各个字符依次赋值给数组T的后续位置
    for (int i = 0; i < t_len; i++) {
        T[i+1] = str_T[i];
    } 

    //printf("str_T len = %d\n",t_len);
    int ret;
    ret = Index_KMP(S, T, 0);
    printf("the pos=%d\n", ret);
    return 0;
}