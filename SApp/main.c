/*
  filename - main.c
  version - 1.0
  description - �⺻ ���� �Լ�,����
  --------------------------------------------------------------------------------
  first created - 2020.02.13
  writer - Lee Chae Eun.
*/

/*
1.�л� 3���� �б޿��� ���� ���� ���� ������ ���� ������ �Է� ���� ��,  �� ���� ���հ� ����� ����ϴ� ���α׷��� �ۼ��Ͻÿ�. 
���� ����, ����, ���� ������ ����� �ϴ� ����ü student_t �� �����Ѵ�. 
�л��� 3���̹Ƿ� student_t Ÿ���� ���� 3��, Ȥ�� �迭�� �����Ͽ�, �ش� ������ ������ �Է¹޴´�. 
�� ������ ������ ���ϴ� �Լ��� ���� �ۼ��Ͽ� ���հ� ����� ���� �� �̸� ����Ѵ�.
*/


#include <stdio.h>
#include <stdlib.h>




// �����Լ�
int main(void) 
{
    int s[3][3];

    
    //char subject[3][100] = { "����","����","����" };

    //�Է��ϰ� �� ���� ����
    for (int i = 0; i < 3; i++) {
        printf("���� ���� ���� ������ �� �� �Է��ϼ��� : ");
        scanf_s("%d %d %d", &a[i].k, &a[i].e, &a[i].m);
       
        
        
    }
    
  
    //�� ���� ���
    printf("     ���� ���� ����\n");
    for (int i = 0; i < 3; i++) {
        printf("%d���� ",i+1);
        for (int j = 0; j < 3; j++) {
            printf("%3d ", s[i][j]);
        }
        printf("\n");
    }


    //���� ���
    int ss[3];
    printf("����  ");
    for (int i = 0; i < 3; i++) {
        ss[i] = sum(i, &s);
        printf("%3d ",ss[i]);
    }
    printf("\n");


    //��� ���
    printf("���  ");
    for (int i = 0; i < 3; i++) {
        printf("%3.1lf ", avg(i, ss[i]));
    }
    printf("\n");
	system("pause");
	return EXIT_SUCCESS;
}