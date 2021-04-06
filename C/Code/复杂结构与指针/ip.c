/*--------------------------------------------------------
* Author             :Jiaq.yang
* Email              :thinklook1@outlook.com
* Create time        :2020-11-09 09:58
* Last modified      :2020-11-09 09:58
* Filename           :ip.c
* Description        :
----------------------------------------------------------*/
#include <stdio.h>

union IP{
	struct {
		unsigned char a1;
		unsigned char a2;
		unsigned char a3;
		unsigned char a4;
	} ip;
	unsigned int num;
};

int is_little() {
	static int num = 1;
	return ((char *)(&num))[0];
}// 判断机器的大小端

int main(){
	printf("%d\n", is_little());
	union IP P;
	char str[100] = {0};
	int arr[4];
	while (~scanf("%s", str)) {
		sscanf(str, "%d.%d.%d.%d", arr, arr+1, arr+2, arr+3);
		P.ip.a1 = arr[3];
		P.ip.a2 = arr[2];
		P.ip.a3 = arr[1];
		P.ip.a4 = arr[0];
		printf("%u\n",P.num);
	}

	return 0;
}
