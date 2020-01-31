#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int kor, eng, mat;
int total() {
	int sum = kor + eng + mat;
	return sum;
}

double average(int sum) {
	double avr=sum / 3;
	return avr;

}

void print() {
	printf("          ====성적표====        \n");
	printf("---------------------------------\n");
	printf("  국어  영어  수학  총점  평균\n");
	printf("%6d%6d%6d%6d%6.1lf\n", kor, eng, mat, total(), average(total()));
	printf("---------------------------------\n");
}
void main() {
	//type here
	scanf_s("%d %d %d", &kor, &eng, &mat);

	print();
	
	system("pause");
}