/*--------------------------------------------------------
* Author             :Jiaq.yang
* Email              :thinklook1@outlook.com
* Create time        :2020-11-09 22:27
* Last modified      :2020-11-09 22:27
* Filename           :header1.c
* Description        :
----------------------------------------------------------*/
#include <stdio.h>
#include "header1.h"

void funcA(int n) {
	if(n == 0) return;
	printf("funcA = %d\n", n);
	funcB(--n);
	return;
}

void funcB(int n) {
	if(n == 0) return;
	printf("funcB = %d\n", n);
	funcA(--n);
	return;
}

