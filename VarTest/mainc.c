#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <float.h>

void main() {
	//type here
	short sh = SHRT_MAX;
	int in = INT_MAX;
	long ln = LONG_MAX;
	long long lln = LLONG_MAX;
	unsigned int ui = UINT_MAX;
	unsigned long lui = ULONG_MAX;
	unsigned long long llui = ULLONG_MAX;
	double dou = DBL_MAX;
	double fl = FLT_MAX;
	double ld = LDBL_MAX;
	
	printf("short �ִ밪 : %d\n", sh);
	printf("in �ִ밪 : %d\n", in);
	printf("ln �ִ밪 : %ld\n", ln);
	printf("lln �ִ밪 : %lld\n", lln);
	printf("unsinged int �ִ밪 : %u\n", ui);
	ui = -1;
	printf("unsinged int �ִ밪 : %u\n", ui);
	printf("unsinged long �ִ밪 : %lu\n", lui);
	printf("unsinged int �ִ밪 : %llu\n", llui);

	printf("double �ִ밪 : %lf\n", dou);
	printf("ld �ִ밪 : %lf\n", ld);
	printf("float �ִ밪 : %f\n", fl);



	system("pause");
}