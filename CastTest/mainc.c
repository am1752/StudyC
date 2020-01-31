#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
void main() {
	int a = 20, b = 3;
	double res;
	short sh;
	int in = INT_MAX;

	res = ((double)a) / ((double)b);
	
	printf("a = %d, b = %d\n", a, b);
	printf("a / b의 결과 : %.1lf\n", res);

	printf("\n");

	res = (double)(a / b);
	printf("a = %d, b = %d\n", a, b);
	printf("a / b의 결과 : %.1lf\n", res);

	a = (int)res;
	printf("(int) %.1lf의 결과 : %d\n", res, a);
	
	printf("\n");

	sh = in;
	printf("%d %d\n", sh, in);

	system("pause");
}