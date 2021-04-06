/*--------------------------------------------------------
* Author             :Jiaq.yang
* Email              :thinklook1@outlook.com
* Create time        :2020-11-08 15:46
* Last modified      :2020-11-08 15:46
* Filename           :test.c
* Description        :输出MAX中的最大值
----------------------------------------------------------*/
#include <stdio.h>

#define MAX(a,b) ({\
	__typeof(a) _a = (a);\
	__typeof(b) _b = (b);\
	_a > _b ? _a : _b;\
})

#define P(func) {\
	printf("%s = %d\n", #func, func);\
}
// #func将函数转换成字符串
int main() {
	int a = 7;
	P(MAX(2,3));
	P(5 + MAX(2,3));
	P(MAX(2, MAX(3,4)));
	P(MAX(2, 3>4?3:4));
	P(MAX(a++, 6));
	return 0;
}
