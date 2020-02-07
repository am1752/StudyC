/*
  filename - main.c
  version - 1.0
  description - 기본 메인 함수/3차원 배열 학습
  --------------------------------------------------------------------------------
  first created - 2020.02.06
  writer - LEE CHAE EUN.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 메인함수
int main(void) 
{
    int a = 10;
    int* pi;
    int** ppi;

    pi = &a;
    ppi = &pi;

    printf("-------------------------------------------------------\n");
    printf(" %2s %10s %10s %10s %10s\n", "변수"," 변숫값", "& 연산"," * 연산 ","* *연산");
    printf("-------------------------------------------------------\n");
    printf("   a %10d %10p\n", a, &a);
    printf("  pi %10p %10p %10d\n", pi, &pi, *pi);
    printf(" ppi %10p %10p %10p %10d\n", ppi, &ppi, *ppi, **ppi);
    printf("-------------------------------------------------------\n");
    
	system("pause");
	return EXIT_SUCCESS;
}