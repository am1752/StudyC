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

	printf("int�� ���� ũ�� : %d\n", sizeof(a));
	printf("double�� ���� ũ�� : %d\n", sizeof(b));
	printf("������ ����� ũ�� : %d\n", sizeof(10));
	printf("������ �ᱣ���� ũ�� : %d\n", sizeof(1.5 + 3.4));
	printf("char�� ���� ũ�� : %d\n", sizeof(char));
	printf("long double�� ���� ũ�� : %d\n", sizeof(c));
	system("pause");
}