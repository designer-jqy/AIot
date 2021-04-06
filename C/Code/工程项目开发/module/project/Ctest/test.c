/*--------------------------------------------------------
* Author             :Jiaq.yang
* Email              :thinklook1@outlook.com
* Create time        :2020-11-10 13:59
* Last modified      :2020-11-10 13:59
* Filename           :test.c
* Description        :
----------------------------------------------------------*/
#include "test.h"
#include "linklist.h"
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int func_cnt = 0;
Function func_head, *func_tail = &func_head;
struct Functioninfo Ctest_test_info;

int RUN_ALL_TESTS() {
	for (struct LinkNode *p = func_head.p.next; p; p = p->next) {
		Function *func = Head(p, Function, p);
		printf(GREEN("[===RUN===] ") RED_HL("%s\n"), func->str);
		Ctest_test_info.total = 0, Ctest_test_info.success = 0;
		func->func();
		double rate = 1.0 * Ctest_test_info.success / Ctest_test_info.total;
		rate *= 100.0;
		printf(PURPLE("[ "));
		if (fabs(rate - 100.0) < 1e-7) {
			printf(BLUE_HL("%6.2lf%%"), rate);
		} else {
			printf(RED_HL("%6.2lf%%"), rate);
		}
		printf(PURPLE(" ]") " total : %d sucess : %d\n",
			Ctest_test_info.total,
			Ctest_test_info.success
		);
	}

	return 0;
}

void add_function(TestFuncT func, const char *str) {
	Function *temp = (Function *)calloc(1, sizeof(Function));
	temp->func = func;
	temp->str = strdup(str);
	func_tail->p.next = &(temp->p);
	func_tail = temp;
	return;
}
