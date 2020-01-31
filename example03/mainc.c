#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main() {
	int kor=3.8, eng=4.4, mat=3.9;
	double s;
	double r;
	double k=3,e=5,m=4;
	double total = k + e + m;
	double av;

	s = kor + eng + mat;
	av = total/3;
	

	printf("%.1lf\n", av);
	
	int res = (total >= 10) && (av >= 4.0);

	printf("result : %d\n", res);

	system("pause");
}