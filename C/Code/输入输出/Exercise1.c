/*
* printf函数
*/
#include <stdio.h>

#define swap(a,b) {\
    __typeof(a) __temp = a;\
    a = b; b = __temp;\
}

int main() {
    int n;
    char str[100] = {0}, temp[100] = {0}, *p = str, *q = temp;
    scanf("%d", &n);   // stdin
    // printf("%d\n", n); // stdout EOF=-1
    sprintf(str,"%d.%d.%d.%d", 192, 168, 1, 2); // 向字符串打印值，常用于：字符串的拼接
    printf("%s\n", str);
    if (n & 1) {
        sprintf(q, "(%s)", p);
        swap(p, q);
    }
    if (n & 2) {
        sprintf(q, "[%s]", p);
        swap(p, q);
    }
    if (n & 4) {
        sprintf(q, "{%s}", p);
        swap(p, q);
    }
    printf("%s\n", p);
    FILE *fout = fopen("output", "w");
    // fprintf(fout, "str = %s\n", p); // 向文件中打印值
    fprintf(stdout, "stdout = %s\n", p);
    fprintf(stderr, "stderr = %s\n", p);
    // > 为标准错误输出重定向
    // ./a.out > output进行标准输出重定向时，stderr的输出会在屏幕，不会重定向进文件


    return 0;
}