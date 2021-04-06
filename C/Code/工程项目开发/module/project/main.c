/*--------------------------------------------------------
* Author             :Jiaq.yang
* Email              :thinklook1@outlook.com
* Create time        :2020-11-10 10:37
* Last modified      :2020-11-10 10:37
* Filename           :main.c
* Description        :
----------------------------------------------------------*/
#include <stdio.h>
#include "Ctest/test.h"

int add(int a, int b) {
	return a+b;
}

TEST(testfunc, add) {
	EXPECT_EQ(add(2,3),5);
	EXPECT_EQ(add(1,2),3);
	EXPECT_EQ(add(2,2),5);
	EXPECT_EQ(add(3,3),6);
	EXPECT_EQ(add(1,-1),0);
}

TEST(testfunc, add2) {
	EXPECT_EQ(add(2,-3),-1);
	EXPECT_EQ(add(5,3),8);
	EXPECT_EQ(add(6,2),8);
	EXPECT_EQ(add(5,2),8);
	EXPECT_EQ(add(3,3),5);
}

int main() {
	return RUN_ALL_TESTS();
}
