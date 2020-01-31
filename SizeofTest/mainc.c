#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <float.h>

void main() {
	int a = 10;
	double b = 3.4;
	long double c = LDBL_MAX;

	printf("int형 변수 크기 : %d\n", sizeof(a));
	printf("double형 변수 크기 : %d\n", sizeof(b));
	printf("정수형 상수의 크기 : %d\n", sizeof(10));
	printf("수식의 결괏값의 크기 : %d\n", sizeof(1.5 + 3.4));
	printf("char형 변수 크기 : %d\n", sizeof(char));
	printf("long double형 변수 크기 : %d\n", sizeof(c));
	system("pause");
}