#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main() {
	double h;
	int w;
	printf("몸무게(kg)와 키(cm) 입력 : ");
	scanf_s("%d%lf", &w, &h);
	h = 0.1*h;
	double bmi = w/(h*h);
	char a[100]="표준입니다";
	char b[100] = "체중관리가 필요합니다";

	
	int c= ((bmi >= 20) && (bmi < 25));
	char res[100];
	(b) ? (strcpy(res,a)) : (strcpy(res,b));
	printf("%.1lf %.1lf\n", bmi, h*h);
	printf("%s\n", res);

	system("pause");
}