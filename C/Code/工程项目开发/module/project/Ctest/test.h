/*--------------------------------------------------------
* Author             :Jiaq.yang
* Email              :thinklook1@outlook.com
* Create time        :2020-11-10 13:37
* Last modified      :2020-11-10 13:37
* Filename           :test.h
* Description        :
----------------------------------------------------------*/
#ifndef _TEST_H_
#define _TEST_H_

#include "linklist.h"
typedef void (*TestFuncT)();

typedef struct Function {
	TestFuncT func;
	const char *str;
	struct LinkNode p;
} Function;

struct Functioninfo {
	int total;
	int success;
};

extern struct Functioninfo Ctest_test_info;

#define COLOR(a,b) "\033[" #b "m" a "\033[0m"
#define COLOR_HL(a,b) "\033[1;" #b "m" a "\033[0m"

#define GREEN(a) COLOR(a,32)
#define RED(a) COLOR(a,31)
#define BLUE(a) COLOR(a,34)
#define YELLOW(a) COLOR(a,33)
#define PURPLE(a) COLOR(a,35)

#define GREEN_HL(a) COLOR_HL(a,32)
#define RED_HL(a) COLOR_HL(a,31)
#define BLUE_HL(a) COLOR_HL(a,34)
#define YELLOW_HL(a) COLOR_HL(a,33)
#define PURPLE_HL(a) COLOR_HL(a,35)

#define TEST(a,b)\
void a##_Ctest_##b();\
__attribute__((constructor))\
void add##_##a##_haizei_##b() {\
	add_function(a##_Ctest_##b, #a "." #b);\
	Ctest_test_info.success = 0;\
	Ctest_test_info.total = 0;\
}\
void a##_Ctest_##b()
#define Type(a) _Generic((a),\
	int : "%d",\
	double : "%lf",\
	float : "%f",\
	long long : "%lld",\
	const char *: "%s",\
	char * : "%s"\
)
#define P(a, color) {\
	char frm[100];\
	sprintf(frm, color("%s"), Type(a));\
	printf(frm, a);\
}

#define EXPECT(a,b,cmp) { \
	Ctest_test_info.total += 1;\
	__typeof(a) _a = (a);\
	__typeof(b) _b = (b);\
	printf(GREEN("[=========] "));\
	printf("%s %s %s  %s\n", #a, #cmp, #b, (a)cmp(b) ? GREEN("True"):RED("Flase"));\
	if (a cmp b) Ctest_test_info.success += 1;\
	else {\
		printf("\n");\
		printf(YELLOW_HL("\t%s:%d: failure\n"), __FILE__, __LINE__);\
		printf(YELLOW_HL("\t\texpect: " #a " " #cmp " " #b "\n\t\t" "actual :"));\
		P(_a, YELLOW_HL);\
		printf(YELLOW_HL(" vs "));\
		P(_b, YELLOW_HL);\
		printf("\n\n");\
	}\
}

#define EXPECT_EQ(a,b) EXPECT(a,b,==)
#define EXPECT_NE(a,b) EXPECT(a,b,!=)
#define EXPECT_LT(a,b) EXPECT(a,b,<)
#define EXPECT_LE(a,b) EXPECT(a,b,<=)
#define EXPECT_GT(a,b) EXPECT(a,b,>)
#define EXPECT_GE(a,b) EXPECT(a,b,>=)

int RUN_ALL_TESTS();
void add_function(TestFuncT, const char *);

#endif 
