/*-------------------------------------------------------------
数组是展开的函数
二分查找
--------------------------------------------------------------*/
// #include <stdio.h>

// int f(int x) {
//     return x * x;
// }

// int binary_search(int (*arr)(int), int n, int target) {
//     int head = 0, tail = n - 1, mid;
//     while (head <= tail) {
//         mid = (tail + head) >> 1;
//         // if (arr[mid] == target) return mid;
//         // else if (arr[mid] < target) head = mid + 1;
//         // else tail = mid - 1;
//         if (arr(mid) == target) return mid;
//         else if (arr(mid) < target) head = mid + 1;
//         else tail = mid - 1;
//     }

//     return -1;
// }

// int main() {
//     // int arr[10];
//     // for (int i = 0; i < 10; i++) {
//     //     arr[i] = i*i;
//     // }
//     int target;
//     while (~scanf("%d", &target)) {
//         int temp = binary_search(f, 10, target);
//         printf("%d * %d = %d\n", temp, temp, temp * temp);
//     }

//     return 0;
// }
/*-------------------------------------------------------------
实现sqrt函数
--------------------------------------------------------------*/
#include <stdio.h>
#include <math.h>

double f(double target) {
    return target * target;
}

double binary_search(double(*f)(double), double target) {
    double head = 0, tail = target, mid;
    if (target < 1.0) tail = 1.0;                           
    // 为应对sqrt(0.01) = 0.1，所以前面的tail = target在该情况下会失效
    #define EPOL 1e-7
    while (tail - head > EPOL) {
        mid = (tail + head) / 2.0;
        if (f(mid) < target) head = mid;
        else tail = mid;
    }
    #undef EPOL
    return head;
}

int main() {
    double target;
    while (~scanf("%lf", &target)) {
        double temp = binary_search(f, target);
        printf("sqrt(%g) = %g\n", target, sqrt(target));
        printf("my_sqrt(%g) = %g\n", target, temp);
    }

    return 0;
}