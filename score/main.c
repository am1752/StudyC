/*
  filename - main.c
  version - 1.0
  description - �⺻ ���� �Լ�
  --------------------------------------------------------------------------------
  first created - 2020.02.04
  writer - Lee Chae Eun.
*/

#include <stdio.h>
#include <stdlib.h>

//���� �Է�
void input_score(int a,int b,int c) {
    printf("����, ����, ���� ������ �Է��ϼ��� : ");
    scanf_s("%d%d%d", &a, &b, &c);
}

// �����Լ�
int main(void) 
{
    int kor=0, eng = 0, mat = 0;
    input_score(kor, eng, mat);

    printf("%d %d %d", kor, eng, mat);
	return EXIT_SUCCESS;
}