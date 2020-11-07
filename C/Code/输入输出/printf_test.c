/*
* 使用printf函数，求解一个数字n的十进制标识的数字位数
*/
#include <stdio.h>

int main() {
    int n;
    while(scanf("%d", &n) != EOF) // 循环读入
    {
        printf("has %d digits\n", printf("%d", n));
    }
    
    return 0;
}