/*
  filename - main.c
  version - 1.0
  description - �⺻ ���� �Լ�/���� ���α׷�
  --------------------------------------------------------------------------------
  first created - 2020.02.03
  writer - Lee Chae Eun.
*/

#include <stdio.h>
#include <stdlib.h>

// �����Լ�
int main(void) 
{
    int a, b;
    char c;
    printf("��Ģ���� �Է�(����) : ");
    
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