/*
  filename - main.c
  version - 1.0
  description - �⺻ ���� �Լ�/������ ��������
  --------------------------------------------------------------------------------
  first created - 2020.02.04
  writer - Lee Chae Eun.
*/

#include <stdio.h>
#include <stdlib.h>

void swap(double* pa, double* pb) {
    double temp;
    temp = *pa;
    *pa = *pb;
    *pb = temp;
}

void line_up(double* maxp, double* midp, double* minp) {
    if (*midp < * minp) swap(midp, minp);
    if (*maxp < * midp) swap(maxp, midp);
    if (*midp < * minp) swap(minp, midp);
    
}

// �����Լ�
int main(void) 
{
    double max, mid, min;
    printf("�Ǽ��� 3�� �Է� : ");
    scanf("%lf%lf%lf", &max, &mid, &min);
    line_up(&max, &mid, &min);
    printf("���ĵ� �� ��� : %.lf %.lf %.lf\n", max, mid, min);
	system("pause");
	return EXIT_SUCCESS;
}