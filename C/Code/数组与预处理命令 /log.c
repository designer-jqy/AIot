/*--------------------------------------------------------
* Author             :Jiaq.yang
* Email              :thinklook1@outlook.com
* Create time        :2020-11-08 16:14
* Last modified      :2020-11-08 16:14
* Filename           :log.c
* Description        :输出log信息
----------------------------------------------------------*/
#include <stdio.h>

#ifdef DEBUG
#define log(frm, args...) {\
	printf("[%s : %s : %d] ", __FILE__, __func__, __LINE__);\
	printf(frm, ##args);\
}
#else
#define log(frm, args...)
#endif

int main() {
	int a = 123;
	log("%d\n", a);
	log("Hello world!\n");

	return 0;
}
