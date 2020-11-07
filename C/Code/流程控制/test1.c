#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int a, b, n, cnt = 0;
    srand(time(0)); // 是每次生成的随机数改变
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        int val = rand() % 100;  // 生成0-99的随机数
        // if (val & 2) {
        //     cnt++;
        // }
        cnt += (val & 1); // 判断val的奇偶性，奇数加1   判断偶数用cnt += !(val % 2) 和 cnt += !(val & 1);
        i && printf(" "); // 当i不为0时，才进行空格输出  或者 i == 0 || printf(" ");
        printf("%d", val);
    }
    printf("\n");
    printf("odd num: %d", cnt);

    scanf("%d%d", &a, &b);
    // if (a - b) {
    //     printf("Not equle!\n");
    // } else {
    //     printf("Equle!\n");
    // }
    printf("%s\n", (a-b) ? "not equle" : "equle");
    a = 0, b = 0;
    // ++a和a++的区别
    if((a++) && (b++)) {
        printf("true\n");
    } else {
        printf("false\n");
    }
    printf("a = %d, b = %d\n", a, b);
    // 输出false  a = 1, b = 0

    if((a++) || (b++)) {
        printf("true\n");
    } else {
        printf("false\n");
    }
    printf("a = %d, b = %d\n", a, b);
    // 输出true  a = 2, b = 0

    return 0;
}
