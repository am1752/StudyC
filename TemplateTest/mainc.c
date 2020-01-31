#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>


void main() {
	//type here
	char b;
	/*
	printf("%d\n", 100);
	printf("%lf\n", 3.141592);
	printf("%.1lf\n", 3.141592);//소숫점 첫번째자리만 출력
	printf("%.10lf\n", 3.141592);
	printf("%.1lf + %.1lf = %.1lf\n", 10.2, 3.4, 10.2 + 3.4);

	printf("\n");
	printf("%.5lf\n", 1.5e-3);
	printf("%.1lf\n", 1e10);
	printf("%.7lf\n", 3.14e-5);
	printf("%le\n", 0.0000314);
	printf("%.1le\n", 0.0000314);
	*/
	printf("%d\n", sizeof(long long));
	int* a;
	a=malloc(sizeof(int) * 4);
	printf("%d\n", sizeof(a));
	free(a);
	printf("%d\n", sizeof(a));
	printf("%c\n", 'A');
	printf("%s\n", "ABC");
	printf("%c is sub of %s\n", 'a', "abc");
	printf("%c\n", 75);
	printf("%x\n", 26);
	system("pause");
}