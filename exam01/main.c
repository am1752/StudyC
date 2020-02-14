/*
  filename - main.c
  version - 1.0
  description - �⺻ ���� �Լ�, �˻�
  --------------------------------------------------------------------------------
  first created - 2020.02.14
  writer - Lee Chae Eun.
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define _MAX 100

int cnt = 0;

typedef struct {
    int number; //���Թ�ȣ
    char name[30];
    char phonenumber[30];
    char email[30];
} namecard[_MAX];

namecard na;

//��ȣ����
int selcet() {
    int n;

    printf("1. �Է�\n");
    printf("2. ����\n");
    printf("3. ����\n");
    printf("4. ��ü���\n");
    printf("5. �˻�\n");
    printf("6. ����\n");

    printf("��ȣ�� �Է��ϼ��� (1~6) :  ");
    scanf_s("%d", &n);

    return n;
}

//�ش� �̸��� �ִ��� Ȯ��
int check(int n) {
    for (int i = 0; i < cnt; i++) {
        if (n == na[i].name) return i;
    }
    return -1;
}

//ī�� ���� �Է�
void input__business_card() {
    printf("�̸� ��ȭ��ȣ �̸����� �Է��ϼ���. : ");
    scanf_s("%s", na[cnt].name, sizeof(na[cnt].name));
    scanf_s("%s", na[cnt].phonenumber, sizeof(na[cnt].phonenumber));
    scanf_s("%s", na[cnt].email, sizeof(na[cnt].email));
    na[cnt].number = cnt + 1;
    cnt++;
}

//��ü ���
void show_all_cards() {
    for (int i = 0; i < cnt; i++) {
        printf("%d. %s : %s , %s\n", na[i].number, na[i].name, na[i].phonenumber, na[i].email);
    }
}

//�ش� ��ȣ ã��
void search_business_card(int num) {
    num--;
    if (num > cnt) {
        printf("�ش� ������ �����ϴ�.\n\n");
        return;
    }
    printf("%d. %s : %s , %s\n", na[num].number, na[num].name, na[num].phonenumber, na[num].email);
}

//�ش� ��ȣ ����
void edit_business_card() {
    int num;
    printf("������ ������ ���� ��ȣ�� �Է��ϼ��� : ");
    scanf_s("%d", &num);
    
    num--;
    printf("������ ����ȣ�� �̸����� �Է��ϼ��� : ");
    scanf_s("%s", na[num].phonenumber, sizeof(na[num].phonenumber));
    scanf_s("%s", na[num].email, sizeof(na[num].email));


}



// �����Լ�
int main(void) 
{
    int n,num;

    while (1) {
        n = selcet();
        if (n == 6) break;
        switch (n) {
            case 1 :
                input__business_card();
                break;
            case 2:
                edit_business_card();
                break;
            case 4:
                show_all_cards();
                break;
            case 5:
                printf("ã�� ��ȣ�� �Է��ϼ���. : ");
                scanf_s("%d", &num);
                search_business_card(num);
        }
    }

	system("pause");
	return EXIT_SUCCESS;
}