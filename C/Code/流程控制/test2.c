/*
* 判断一个十进制的整数n，在base进制下，是否为回文数
*/
#include <stdio.h>

int rev_num(int n, int base) {
    if (n < 0) return 0;
    int x = n, temp = 0;
    while (x) {
        temp = temp * base + (x % base);
        x /= base;
    }
    return temp == n;
}

int main() {
    int n;
    scanf("%d", &n);
    printf("%s\n", rev_num(n, 10) ? "yes" : "no");
    int x = n, digit = 0;
    do {
        x /= 10;
        digit += 1;
    } while (x);
    printf("%d has %d digits\n", n, digit);

    return 0;
}