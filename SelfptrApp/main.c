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

struct list {
    int num;
    struct list* next;//�ڱ����� 
};

// �����Լ�
int main(void) 
{
    struct list a = { 40,15}, b = { 20,10 }, c = { 30,400 };
    struct list* head = &a, * current;

    a.next = &b;
    b.next = &c;

    printf("head -> num : %d\n", head->num);
    printf("head -> next -> num : %d\n", head->next->num);

    printf("list all : ");
    current = head;

    while(current != NULL) {
        printf("%d ", current->num);
        current = current->next;
    }
    printf("\n");

	system("pause");
	return EXIT_SUCCESS;
}