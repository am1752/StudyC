/*
  filename - main.c
  version - 1.0
  description - 기본 메인 함수,전화번호부
  --------------------------------------------------------------------------------
  first created - 2020.02.07
  writer - LEE CHAE EUN.
*/

#include <stdio.h>
#include <stdlib.h>
#define _MAX 30

typedef struct {
    char name[10];
    int cnt;
    char number[20];
}phonebook[_MAX];

phonebook phone;

void InputPhoneData(int count) {
    phone[count].cnt = count;
    scanf("%s", phone[count].name);
    scanf("%s", phone[count].number);
}

void ShowAllData(int count) {
    //InputPhoneData(count);
    for (int i = 0; i < count; i++) {
        printf("%d. %s : %s\n", phone[i].cnt+1, phone[i].name, phone[i].number);
    }
    printf("\n");
}

// 메인함수
int main(void) 
{
    int cnt = 0;

    for (int i = 0; i < 5; i++) {
        InputPhoneData(i);
    }
	

	system("pause");
	return EXIT_SUCCESS;
}