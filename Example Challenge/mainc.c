#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main() {
	double h;
	int w;
	printf("������(kg)�� Ű(cm) �Է� : ");
	scanf_s("%d%lf", &w, &h);
	h = 0.1*h;
	double bmi = w/(h*h);
	char a[100]="ǥ���Դϴ�";
	char b[100] = "ü�߰����� �ʿ��մϴ�";

	
	int c= ((bmi >= 20) && (bmi < 25));
	char res[100];
	(b) ? (strcpy(res,a)) : (strcpy(res,b));
	printf("%.1lf %.1lf\n", bmi, h*h);
	printf("%s\n", res);

	system("pause");
}