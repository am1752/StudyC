/*
  filename - main.c
  version - 1.0
  description - �⺻ ���� �Լ�,����ī��
  --------------------------------------------------------------------------------
  first created - 2020.02.10
  writer - Lee Chae Eun.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// �����Լ�
int main(void) 
{
    FILE* ifp, * ofp;
    char str[80];
    char* res;

    ifp = fopen("aa.txt", "r");
    if (ifp == NULL) {
        printf("���� ���� ����");
        return EXIT_FAILURE;
    }

    ofp = fopen("bb.txt", "w");
    if (ofp == NULL) {
        printf("���� ���� ����");
        return EXIT_FAILURE;
    }

    while (1) {
        res = fgets(str, sizeof(str), ifp);
        if (res == NULL) break;
        str[strlen(str) - 1] = '\0';
        fputs(str, ofp);
        fputs(" ", ofp);
    }

    fclose(ifp);
    fclose(ofp);

	system("pause");
	return EXIT_SUCCESS;
}