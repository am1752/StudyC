/*
  filename - main.c
  version - 1.0
  description - 기본 메인 함수
  --------------------------------------------------------------------------------
  first created - 2020.02.04
  writer - Lee Chae Eun.
*/

#include <stdio.h>
#include <stdlib.h>

void swap(int pa, int pb) {
    int temp;
    temp = pa;
    pa = pb;
    pb = temp;
}

// 메인함수

int main(void) 
{
    int a = 15, b = 24;
    swap(a, b);

    printf("a, b : %d, %d\n", a, b);
	system("pause");
	return EXIT_SUCCESS;
}