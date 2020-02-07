/*
  filename - main.c
  version - 1.0
  description - 기본 메인 함수
  --------------------------------------------------------------------------------
  first created - 2020.02.01
  writer - Hugo MG Sung.
*/

#include <stdio.h>
#include <stdlib.h>

void input_Ary(double* pa, int size);
double find_max(double* pa, int size);

// 메인함수
int main(void) 
{
    double ary[5];
    double max;
    int size = sizeof(ary) / sizeof(ary[0]);
    
    input_Ary(ary, size);
    max = find_max(ary, size);
    printf("배열의 최댓값 : %.1lf\n", max);
	system("pause");
	return EXIT_SUCCESS;
}

void input_Ary(double* pa, int size) {
    printf("%d개의 실수값 입력 : ", size);
    for (int i = 0; i < size; i++) {
        scanf_s("%lf", pa + i);
    }

}

double find_max(double* pa, int size) {
    double max=pa[0];

    for (int i = 1; i < size; i++) {
        if (pa[i] > max) {
            max = pa[i];
        }
    }
    return max;
}