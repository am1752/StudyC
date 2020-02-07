/*
  filename - main.c
  version - 1.0
  description - 기본 메인 함수
  --------------------------------------------------------------------------------
  first created - 2020.02.04
  writer - Lee Chae Eun.
*/

#include <stdio.h>
#include <stdlib.h>

//점수 입력
void input_score(int a,int b,int c) {
    printf("국어, 영어, 수학 점수를 입력하세요 : ");
    scanf_s("%d%d%d", &a, &b, &c);
}

// 메인함수
int main(void) 
{
    int kor=0, eng = 0, mat = 0;
    input_score(kor, eng, mat);

    printf("%d %d %d", kor, eng, mat);
	return EXIT_SUCCESS;
}