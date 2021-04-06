/*--------------------------------------------------------
* Author             :Jiaq.yang
* Email              :thinklook1@outlook.com
* Create time        :2020-11-09 14:27
* Last modified      :2020-11-09 14:27
* Filename           :pointer1.c
* Description        :
----------------------------------------------------------*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//#define offset(T, a) ({\
//	T temp;\
//	(char*)(&temp.a) - (char*)(&temp);\
//})

#define offset(T,a) (long)(&(((T *)(NULL))->a)) // 使用空地址 

void output(int argc, char *argv[], char ** env) {
	for (int i = 0; i < argc; i++) {
		printf("argv[%d] = %s\n", i, argv[i]);
	}
	for (int i = 0; env[i]; i++) {
		// printf("env[%d] = %s\n", i, env[i]);
		if(!strncmp(env[i], "USER=", 5)) {
			if(!strcmp(env[i]+5, "q7")) {
				printf("Welcome!\n");
			} else {
				printf("You are not the User!\n");
				exit(0);
			}
		}
	}
	return;
}

struct Data {
	int a;
	char b;
	double c;
};

int main(int argc, char *argv[], char **env) {
	output(argc, argv, env);
	return 0;
	int num = 0x0626364;
	printf("%s\n",(char *)(&num));
	printf("%ld\n", offset(struct Data, a));
	printf("%ld\n", offset(struct Data, b));
	printf("%ld\n", offset(struct Data, c));
	
	return 0;
}
