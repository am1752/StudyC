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

// 메인함수
int main(void) 
{
    int score[3][4];
    int total;
    double avg;
    
    for (int i = 0; i < 3; i++) {
        printf("4과목의 성적 입력 : ");
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
        printf("총점 : %d, 평균 : %.2lf\n", total, avg);
    }

	system("pause");
	return EXIT_SUCCESS;
}