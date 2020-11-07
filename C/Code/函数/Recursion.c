#include <stdio.h>

int value(int num) {
    if (num == 1) return 1;
    return num * value(num - 1);
}   

int main() {
    int num;
    while (scanf("%d", &num) != EOF) {
        printf("fac(%d) = %d\n", num, value(num));
    }
    
    return 0;
}