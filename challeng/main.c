/*
  filename - main.c
  version - 1.0
  description - 기본 메인 함수/포인터 도전예제
  --------------------------------------------------------------------------------
  first created - 2020.02.04
  writer - Lee Chae Eun.
*/

#include <stdio.h>
#include <stdlib.h>

void swap(double* pa, double* pb) {
    double temp;
    temp = *pa;
    *pa = *pb;
    *pb = temp;
}

void line_up(double* maxp, double* midp, double* minp) {
    if (*midp < * minp) swap(midp, minp);
    if (*maxp < * midp) swap(maxp, midp);
    if (*midp < * minp) swap(minp, midp);
    
}

// 메인함수
int main(void) 
{
    double max, mid, min;
    printf("실수값 3개 입력 : ");
    scanf("%lf%lf%lf", &max, &mid, &min);
    line_up(&max, &mid, &min);
    printf("정렬된 후 출력 : %.lf %.lf %.lf\n", max, mid, min);
	system("pause");
	return EXIT_SUCCESS;
}