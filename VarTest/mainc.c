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
	
	printf("short 최대값 : %d\n", sh);
	printf("in 최대값 : %d\n", in);
	printf("ln 최대값 : %ld\n", ln);
	printf("lln 최대값 : %lld\n", lln);
	printf("unsinged int 최대값 : %u\n", ui);
	ui = -1;
	printf("unsinged int 최대값 : %u\n", ui);
	printf("unsinged long 최대값 : %lu\n", lui);
	printf("unsinged int 최대값 : %llu\n", llui);

	printf("double 최대값 : %lf\n", dou);
	printf("ld 최대값 : %lf\n", ld);
	printf("float 최대값 : %f\n", fl);



	system("pause");
}