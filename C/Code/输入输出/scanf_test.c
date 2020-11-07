/*
* 读入一个行字符串（可能包含空格），输出这个字符串中字符的数量
*/
#include <stdio.h>

int main() {
    char str[100] = {0};
    while (scanf("%[^\n]", str) != EOF) {
        getchar(); //吞掉字符流中的\n  
        // 正则表达式，[]为字符匹配集，[]里面标识的字符才能够被读入
        printf(" has %d chars!\n", printf("%s\n", str));
    }
    
    return 0;
}
