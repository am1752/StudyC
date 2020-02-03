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

// 메인함수
int main(void) 
{
    /* 복합대입 연산자
    int a = 10, b=20;
    int res = 2;

    a += 20;
    res *= (b + 10);

    printf("a= %d, b = %d\n", a, b);
    printf("res = %d\n", res);
    */
    /* 조건 연산자
    int a = 10, b = 20, res;

    res = (a > b) ? a : b;

    printf("큰 값 : %d\n", res);
    */
    /*연산자 3번
    int h, m, s;
    double time=3.76;

    h = (int)time;

    double t = time - h;

    t *= 3600;
    m = (int)t/60;
    s = (int)t%60;
    printf("%d %d %d", h,m,s);


	return EXIT_SUCCESS;
    */
    /*4장 2번
    int seats = 70;
    int audience = 65;
    double rate;

    rate = (double)audience / seats;
    rate *= 100;

    printf("입장률 : %.1lf%%\n", rate);
    */
}