/*
  filename - main.c
  version - 1.0
  description - 기본 메인 함수,성적
  --------------------------------------------------------------------------------
  first created - 2020.02.13
  writer - Lee Chae Eun.
*/

/*
1.학생 3명의 학급에서 각각 국어 영어 수학의 시험 성적을 입력 받은 후,  각 과목 총합과 평균을 출력하는 프로그램을 작성하시오. 
먼저 국어, 영어, 수학 성적을 멤버로 하는 구조체 student_t 를 정의한다. 
학생이 3명이므로 student_t 타입의 변수 3개, 혹은 배열을 정의하여, 해당 변수에 성적을 입력받는다. 
각 과목의 총합을 구하는 함수를 각각 작성하여 총합과 평균을 구한 후 이를 출력한다.
*/


#include <stdio.h>
#include <stdlib.h>




// 메인함수
int main(void) 
{
    int s[3][3];

    
    //char subject[3][100] = { "국어","영어","수학" };

    //입력하고 각 점수 저장
    for (int i = 0; i < 3; i++) {
        printf("국어 영어 수학 점수를 각 각 입력하세요 : ");
        scanf_s("%d %d %d", &a[i].k, &a[i].e, &a[i].m);
       
        
        
    }
    
  
    //각 점수 출력
    printf("     국어 영어 수학\n");
    for (int i = 0; i < 3; i++) {
        printf("%d점수 ",i+1);
        for (int j = 0; j < 3; j++) {
            printf("%3d ", s[i][j]);
        }
        printf("\n");
    }


    //총점 출력
    int ss[3];
    printf("총점  ");
    for (int i = 0; i < 3; i++) {
        ss[i] = sum(i, &s);
        printf("%3d ",ss[i]);
    }
    printf("\n");


    //평균 출력
    printf("평균  ");
    for (int i = 0; i < 3; i++) {
        printf("%3.1lf ", avg(i, ss[i]));
    }
    printf("\n");
	system("pause");
	return EXIT_SUCCESS;
}