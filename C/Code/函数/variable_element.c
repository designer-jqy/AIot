/*
* 变参函数
*/
#include <stdio.h>
#include <inttypes.h> // INT32_MIN 的头文件
#include <stdarg.h>   // va族的头文件

int max_int(int n, ...) {
    int ans = INT32_MIN;
    va_list arg;                     // 定义一个代表参数列表的变量
    va_start(arg, n);                // 初始化参数列表
    while (n--) {
        int temp = va_arg(arg, int); // va_arg为宏定义
        if (temp > ans) ans = temp;
    }
    va_end(arg);                     // 销毁参数列表
    return ans;
}

int main() {

    printf("%d\n",max_int(3,1,5,8));
    printf("%d\n",max_int(5,2,6,8,10,15));
    printf("%d\n",max_int(5,1,2,5,6,8,10));

    return 0;
}