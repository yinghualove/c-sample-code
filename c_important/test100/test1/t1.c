// 题目：有1、2、3、4个数字，能组成多少个互不相同且无重复数字的三位数？都是多少？

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    int num[4] = {0};
    printf("input your num:\n");
    scanf("%d%d%d%d",&num[0],&num[1],&num[2],&num[3]);
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            for(int k = 0; k < 4; k++)
            {
                if(num[i] != num[j] && num[i] != num[k] && num[j] != num[k])
                {
                    int sum;
                    sum = num[i] * 100 + num[j] * 10 + num[k];
                    printf("三位数是:%d\n",sum);
                }
            }
        }
    }
    return 0;
}