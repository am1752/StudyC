/*
  filename - main.c
  version - 1.0
  description - �⺻ ���� �Լ�,����
  --------------------------------------------------------------------------------
  first created - 2020.02.11
  writer - Lee Chae Eun.
*/

#include <stdio.h>
#include <stdlib.h>
#include "sub.h"

void input_data(int*,int*);
double average(int, int);
//extern int c;
// �����Լ�
int main(void) 
{
    int a, b;
    double avg;

    input_data(&a, &b);
    avg = average(a, b);

    printf("%d��  %d�� ��� : %.1lf\n", a, b, avg);
    printf("%d\n", c);
	system("pause");
	return EXIT_SUCCESS;
}