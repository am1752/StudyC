/*
  filename - main.c
  version - 1.0
  description - 기본 메인 함수,전처리학습
  --------------------------------------------------------------------------------
  first created - 2020.02.10
  writer - Lee Chae Eun.
*/

#include <stdio.h>
#include <stdlib.h>
#include "student.h"



// 메인함수
int main(void) 
{
    /*double radius, area;

    printf("반지름을 입력하세요(10 이하) : ");
    scanf_s("%lf", &radius);
    area = PI * radius * radius;
    if (area > LIMIT) { ERR_PRN; }
    else printf("원의 면적 : %.2lf (%s)\n", area, MSG);
    
    int a = 10, b = 20;
    double x = 11.2, y = 20.3;

    int res = SUM(a, b);
    double res1 = MUL(x, y);

    printf("%d\n", res);
    printf("%.1lf\n", res1);
    res = 30 / MUL(2, 5);

    printf("%d\n", res);

    SWAP(a, b);

    printf("%d %d\n", a, b);
    

    int a1, a2;
    NAME_CAT(a, 1) = 10;
    NAME_CAT(a, 2) = 20;

    PRINT_EXP(a1 + a2);
    PRINT_EXP(a1 - a2);
    */

    int max;

#if VER >=6
    printf("버전 %d입니다.\n", VER);
#endif

#ifdef BIT16
    max = 32767;
#else
    max = 21247483647;
#endif

    printf("int형 변수의 최댓값 : %d\n", max);

	system("pause");
	return EXIT_SUCCESS;
}

void my_print(void) {
    printf("임시 출력 함수\n");
}