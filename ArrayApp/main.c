/*
  filename - main.c
  version - 1.0
  description - �⺻ ���� �Լ�
  --------------------------------------------------------------------------------
  first created - 2020.02.01
  writer - Hugo MG Sung.
*/

#include <stdio.h>
#include <stdlib.h>

// �����Լ�
int main(void) 
{
    int score[3][4];
    int total;
    double avg;
    
    for (int i = 0; i < 3; i++) {
        printf("4������ ���� �Է� : ");
        for (int j = 0; j < 4; j++) {
            scanf_s("%d", &score[i][j]);  
        }
    }

    for (int i = 0; i < 3; i++) {
        total = 0;
        for (int j = 0; j < 4; j++) {        
            total += score[i][j];
        }
        avg = total / 4;
        printf("���� : %d, ��� : %.2lf\n", total, avg);
    }

	system("pause");
	return EXIT_SUCCESS;
}