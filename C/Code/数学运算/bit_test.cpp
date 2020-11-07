#include <stdio.h>

int main() {
    int a = 7, b = 3, c;
    
    a += 7;// a = a + 7;
    int *p = &a;
    (*p)--;// a--
    printf("a = %d, b = %d\n", a, b);
    a ^= b;
    b ^= a;
    a ^= b;
    printf("swap : a = %d, b = %d\n", a, b);
    

    return 0;
}
