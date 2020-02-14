/*
  filename - main.c
  version - 1.0
  description - �⺻ ���� �Լ�,����
  --------------------------------------------------------------------------------
  first created - 2020.02.13
  writer - Lee Chae Eun.
*/

/*
������ �������� ��ȯ�ϴ� �Լ��� �ۼ��Ͻÿ�.
�Լ� �Է� : 0-100 ������ ���� (����)
�Լ� ��ȯ�� : ����
A : 90-100
B : 70-89
C : 60-69
D : 50-59
F : 0-39

*/

#include <stdio.h>
#include <stdlib.h>

//���� ��ȯ
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




// �����Լ�
int main(void) 
{
    int s;
	printf("�Լ� �Է� : 0-100 ������ ���� (����) ");
    scanf_s("%d", &s);
    if (s < 0 || s>100) return;
    printf("%c\n", score(s));
	system("pause");
	return EXIT_SUCCESS;
}