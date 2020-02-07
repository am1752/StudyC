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
#include <string.h>

int a[7];

int kk() {
    static int s = 0;
    s+=1;
    return s;
}


// 메인함수
int main(void) 
{
    register int a = 1;
    static int b = 1;
    auto c = 'A';

    //scanf("%d", a);
    printf("%d\n", sizeof(c));


	system("pause");
	return EXIT_SUCCESS;
}