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
    FILE* fp;
    char str[20];

    fp = fopen("a.txt", "a+");

    if (fp == NULL) {
        printf("������ ������ ���߽��ϴ�.\n");
        return 1;
    }

    while (1) {
        printf("���� �̸� : ");
        scanf_s("%s", str,sizeof(str));
        if (strcmp(str, "end") == 0)  break;
        else if (strcmp(str, "list") == 0) {
            fseek(fp, 0, SEEK_SET);//0��°�� ó������ ����
            while (1) {
                fgets(str, sizeof(str), fp);//���Ͽ� �Է� ���� ����
                if (feof(fp))break;//���� ���� �����ϸ� ����
                printf("%s", str);//�Է¹��� ���� ȭ�� ���
            }
        }
        else fprintf(fp, "%s\n", str);//�Է��� ���� ���Ͽ� ���
    }
    fclose(fp);

	system("pause");
	return EXIT_SUCCESS;
}