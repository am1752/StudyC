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
    /*char ch;
    int in;
    double db;

    char* pc = &ch;
    int* pi = &in;
    double* pd = &db;

    printf("ch size : %u\n", sizeof(ch));
    printf("in size : %u\n", sizeof(in));
    printf("db size : %u\n", sizeof(db));

    printf("\n");

    printf("char * ������ ũ�� : %d\n", sizeof(pc));
    printf("int * ������ ũ�� : %d\n", sizeof(pi));
    printf("double * ������ ũ�� : %d\n", sizeof(pd));

    printf("\n");

    printf("char * ������ ������ ũ�� : %d\n", sizeof(*pc));
    printf("int * ������ ������ ũ�� : %d\n", sizeof(*pi));
    printf("double * ������ ������ ũ�� : %d\n", sizeof(*pd));

    printf("\n");
    */

    int a = 10;
    int* pa = &a;
    double* pb = pa;

    printf("a : %d\n", a);
    printf("*pa : %d\n", *pa);
    printf("*pb : %d\n", *pb);

    printf("\n");
    printf("&a : %d\n", &a);
    printf("pa : %d\n", pa);
    printf("pb : %d\n", pb);

    system("pause");

    return EXIT_SUCCESS;
}