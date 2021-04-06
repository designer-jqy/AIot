/*--------------------------------------------------------
* Author             :Jiaq.yang
* Email              :thinklook1@outlook.com
* Create time        :2020-11-09 13:26
* Last modified      :2020-11-09 13:26
* Filename           :test.c
* Description        :
----------------------------------------------------------*/
#include <stdio.h>

#define P(func) {\
	printf("%s = %d\n", #func, func);\
}

struct Data {
	int x,y;
};

int main(){
	struct Data a[2];
	struct Data *p = a;
	a[0].x = a[0].y = 0;
	a[1].x = a[1].y = 1;
	P((p+1)->x);
	P((*(p+1)).x);
	P((a+1)->x);
	P((*(a+1)).x);
	P(p[1].x);
	return 0;
}
