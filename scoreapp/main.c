/*
  filename - main.c
  version - 1.0
  description - 기본 메인 함수,학점
  --------------------------------------------------------------------------------
  first created - 2020.02.13
  writer - Lee Chae Eun.
*/

/*
점수를 학점으로 변환하는 함수를 작성하시오.
함수 입력 : 0-100 사이의 점수 (정수)
함수 반환값 : 학점
A : 90-100
B : 70-89
C : 60-69
D : 50-59
F : 0-39

*/

#include <stdio.h>
#include <stdlib.h>

//학점 반환
char score(int s) {
    switch (s / 10) {
        case 10:
        case 9:
            return 'A';
        case 8:
        case 7:
            return 'B';
        case 6:
            return 'C';
        case 5:
            return 'D';
        default:
            return 'F';
    }
}




// 메인함수
int main(void) 
{
    int s;
	printf("함수 입력 : 0-100 사이의 점수 (정수) ");
    scanf_s("%d", &s);
    if (s < 0 || s>100) return;
    printf("%c\n", score(s));
	system("pause");
	return EXIT_SUCCESS;
}