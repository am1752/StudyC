/*
  filename - main.c
  version - 1.0
  description - 기본 메인 함수,배수
  --------------------------------------------------------------------------------
  first created - 2020.02.13
  writer - lee chae eun
*/

/*
1부터 300사이의 숫자(정수) 중에서 3의 공배수(3,6,9,12,..)들의 총합을 출력하는 프로그램을 작성하시오. (for문 사용)

*/

#include <stdio.h>
#include <stdlib.h>

// 메인함수
int main(void) 
{
    int s = 0;

    for (int i = 3; i <= 300; i += 3) s += i;

    printf("%d\n", s);

	system("pause");
	return EXIT_SUCCESS;
}