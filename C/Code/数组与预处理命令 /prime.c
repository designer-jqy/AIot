/*--------------------------------------------------------------
静态数组的声明方式：
int a[100]
素数筛：
1.标记一个范围内的数字是否是合数，没有被标记的则为素数
2.算法的空间复杂度为O(N)，时间复杂度O(N*loglogN)
3.总体思想是用素数取标记掉不是素数的数字，例如我知道了i是素数，那么2*i、3*i、4*i...就都不是素数
---------------------------------------------------------------*/
// #include <stdio.h>

// #define max_n 100

// int prime[max_n+5];  // 当数组定义在函数外面的话，不需要自己初始话为0，系统自动会给其初始化为0
// void init() {
//     for (int i = 2; i <= max_n; i++) {
//         if(prime[i]) continue;
//         prime[++prime[0]] = i;                           // prime[0]为素数计数器
//         for (int j = i*2; j <= max_n; j+=i) {
//             prime[j] = 1;
//         }
//     }
//     return;
// }

// int main () {
//     init();
//     for (int i = 1; i <= prime[0]; i++) {
//         printf("%d\n", prime[i]);
//     }

//     return 0;
// }

/*--------------------------------------------------------------
任何一个数字N都可以写成素因子幂次连乘的形式，例如：12 = 2^2 * 3^1
线性筛：
1.标记一个范围内的数字是否是合数，没有被标记的则为素数
2.算法的空间复杂度为O(N)，时间复杂度O(N)
3.总体思想是用一个整数M去标记合数N，其中N和M具有如下性质
  1）N中最小的素数为p
  2）N可以表示成为p*M
  3）p一定小于等于M中最小的素因子
  4）利用M*P'（所有不大于M中最小素数的集合）标记N1、N2、N3...
  M最大，P最小
---------------------------------------------------------------*/
#include <stdio.h>
#define max_n 200000

int prime[max_n+5];

void init() {
    for (int i = 2; i <= max_n; i++) {
        if (!prime[i]) prime[++prime[0]] = i;
        for (int j = 1; j <= prime[0]; j++) {
            if (i * prime[j] > max_n) break;
            prime[i * prime[j]] = 1;
            if (i % prime[j] == 0) break;
        }
    }

    return;
}

int main() {
    init();
    printf("%d\n", prime[10001]);
    return 0;
}