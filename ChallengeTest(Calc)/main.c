/*
  filename - main.c
  version - 1.0
  description - 기본 메인 함수/계산기 프로그램
  --------------------------------------------------------------------------------
  first created - 2020.02.03
  writer - Lee Chae Eun.
*/

#include <stdio.h>
#include <stdlib.h>

// 메인함수
int main(void) 
{
    int a, b;
    char c;
    printf("사칙연산 입력(정수) : ");
    
    scanf_s("%d%c%d", &a, &c, &b);

    switch (c) {
        case '+':
            printf("%d %c %d = %d\n", a, c, b,a + b);
            break;
        case '-':
            printf("%d %c %d = %d\n", a, c, b,a - b);
            break;
        case '*':
            printf("%d %c %d = %d\n", a, c, b, a * b);
            break;
        case '/':
            printf("%d %c %d = %d\n", a, c, b, a / b);
            break;
        default:
            break;
    }
    


	system("pause");
	return EXIT_SUCCESS;
}