/*
  filename - main.c
  version - 1.0
  description - �⺻ ���� �Լ�,��ó���н�
  --------------------------------------------------------------------------------
  first created - 2020.02.10
  writer - Lee Chae Eun.
*/

#include <stdio.h>
#include <stdlib.h>
#include "student.h"



// �����Լ�
int main(void) 
{
    /*double radius, area;

    printf("�������� �Է��ϼ���(10 ����) : ");
    scanf_s("%lf", &radius);
    area = PI * radius * radius;
    if (area > LIMIT) { ERR_PRN; }
    else printf("���� ���� : %.2lf (%s)\n", area, MSG);
    
    int a = 10, b = 20;
    double x = 11.2, y = 20.3;

    int res = SUM(a, b);
    double res1 = MUL(x, y);

    printf("%d\n", res);
    printf("%.1lf\n", res1);
    res = 30 / MUL(2, 5);

    printf("%d\n", res);

    SWAP(a, b);

    printf("%d %d\n", a, b);
    

    int a1, a2;
    NAME_CAT(a, 1) = 10;
    NAME_CAT(a, 2) = 20;

    PRINT_EXP(a1 + a2);
    PRINT_EXP(a1 - a2);
    */

    int max;

#if VER >=6
    printf("���� %d�Դϴ�.\n", VER);
#endif

#ifdef BIT16
    max = 32767;
#else
    max = 21247483647;
#endif

    printf("int�� ������ �ִ� : %d\n", max);

	system("pause");
	return EXIT_SUCCESS;
}

void my_print(void) {
    printf("�ӽ� ��� �Լ�\n");
}