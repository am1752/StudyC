/*
  filename - main.c
  version - 1.0
  description - 기본 메인 함수 배열과 포인터
  --------------------------------------------------------------------------------
  first created - 2020.02.04
  writer - Lee Chae Eun.
*/

#include <stdio.h>
#include <stdlib.h>

void print_ary(int* pa);

// 메인함수
int main(void) 
{
    int ary[] = { 10,20,30,40,50 };
    int ary2[] = { 10,20,30,40,50,60,70 };
    int size = 0;
    print_ary(ary,sizeof(ary)/sizeof(int));
    print_ary(ary2, sizeof(ary2) / sizeof(ary2[0]));
	system("pause");
	return EXIT_SUCCESS;
}

//배열 출력 함수
void print_ary(int* pa,int size) {
    for (int i = 0; i < size; i++) {
        printf("%5d", *(pa + i));
    }
    printf("\n");
}