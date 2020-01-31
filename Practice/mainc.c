#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int total(int kor, int eng, int mat) {
	int sum = kor + eng + mat;
	return sum;
}

double average(int sum) {
	double avr=sum / 3;
	return avr;

}



void main() {
	//type here

	
	system("pause");
}