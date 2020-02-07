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
#define N 11
int d[N] = { 0,1,2,4 };

// 메인함수
int main(void) 
{
    int n;

    scanf_s("%d", &n);
       

    for (int i = 4; i <= n; i++) {
        d[i] = d[i - 1] + d[i - 2] + d[i - 3];
        d[i] %= 10007;
    }

    printf("%d\n", d[n] % 10007);
	system("pause");
	return EXIT_SUCCESS;
}