/*
  filename - main.c
  version - 1.0
  description - 라이브러리 함수
  --------------------------------------------------------------------------------
  first created - 2020.02.11
  writer - Lee Chae Eun.
*/


#include <stdio.h>
#include <stdlib.h>
#include "calc.h"

// 메인함수
int main(void) 
{
    puts("┌───────────────┐");
    puts("│정적 라이브러리│");
    puts("└───────────────┘");
    
    int data[] = { 10,20,30,40,50,60,70,80,90,100 };
    int result = get_total(data, 10);

    printf("Result is %d\n", result);
    
    system("pause");
	return EXIT_SUCCESS;
}