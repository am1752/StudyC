/*
  filename - main.c
  version - 1.0
  description - �⺻ ���� �Լ�, �˻�2
  --------------------------------------------------------------------------------
  first created - 2020.02.14
  writer - Lee Chae Eun.
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define _MAX 100

int k,cnt = 0,index;
int ii = 0;//same index
char same[_MAX][20];

FILE* fp,*ofp;


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

    printf("\n1. �Է�\n");
    printf("2. ����\n");
    printf("3. ����\n");
    printf("4. ��ü���\n");
    printf("5. �˻�\n");
    printf("6. ����\n");

    printf("��ȣ�� �Է��ϼ��� (1~6) :  ");
    scanf_s("%d", &n);

    printf("\n");

    return n;
}

//��ġ �ٲٱ�
void setting(int num) {
    for (int i = num; i < cnt; i++) {
        na[i] = na[i + 1];
        na[i].number;
    }
    cnt--;
}

//�̹� �ִ� �̸����� Ȯ��
int check(char name[]) {
    for (int i = 0; i < cnt; i++) {
        if (strcmp(name, na[i].name) == 0) {
            index = i;
            return 0;
        }
    }
    return 1;
}


//�������� Ȯ��
int chk(char name[]) {

    if (ii == 0) {
        return 0;
    }
    for (int i = 0; i <= ii; i++) {
        if (strcmp(same[i], name) == 0) {
            return 1;
        }
    }
    return 0;
}

//���� �������� ���� ��� ã�� 
int ssame(char name[], char num[]) {
    for (int i = 0; i < cnt; i++) {
        if (strcmp(name, na[i].name) == 0 && strcmp(num, na[i].phonenumber) == 0) {
            printf("���� ��ȣ�� �ֽ��ϴ�.\n\n");
            return 1;
        }
    }
    return 0;
}


//ī�� ���� �Է�
void input__business_card() {
    char name[10], phonenumber[20],email[20];
    printf("�̸� ��ȭ��ȣ �̸����� �Է��ϼ���. : ");
    
    if (cnt >= 100) {
        printf("�޸� ������ �����մϴ�.\n");
        return 0;
    }
    
    scanf_s("%s", name, sizeof(name));
    scanf_s("%s", phonenumber, sizeof(phonenumber));
    scanf_s("%s", email, sizeof(email));

    if (check(name) == 1) {//������������ �ƴѰ��
        strcpy(na[cnt].name, name);
        strcpy(na[cnt].phonenumber, phonenumber);
        strcpy(na[cnt].email, email);
        na[cnt].number = k ++;
        cnt++;

    }
    else {
        if (strcmp(na[index].phonenumber, phonenumber) == 0) {//���� ���� �ٽ� �Է�
            printf("�̹� ��ϵ� �����Դϴ�. \n\n");
            }
        else {
            printf("���������� �ֽ��ϴ�!!!\n\n");
            if (chk(name) == 0) {//���� �̸��� ó�� ���°��
                strcpy(same[ii], name);
                ii++;
                strcpy(na[cnt].name, name);
                strcpy(na[cnt].phonenumber, phonenumber);
                strcpy(na[cnt].email, email);
                na[cnt].number = k++;
                cnt++;
            }
            else {//�ش��̸��� �̹� ���������� ���
                if (ssame(name, phonenumber) == 0) {
                    strcpy(na[cnt].name, name);
                    strcpy(na[cnt].phonenumber, phonenumber);
                    strcpy(na[cnt].email, email);
                    na[cnt].number = k++;
                    cnt++;
                }
                else {
                    printf("�̹� ��ϵ� �����Դϴ�. \n\n");
                }
            }

        }

    }
}

//��ü ���
void show_all_cards() {
    for (int i = 0; i < cnt; i++) {
        printf("%d. %s : %s , %s\n", na[i].number, na[i].name, na[i].phonenumber, na[i].email);
    }
    printf("\n");
}

//�ش� ��ȣ ã��
void search_business_card(int num) {
    for (int i = 0; i < cnt; i++) {
        if (num == na[i].number) {
            printf("%d. %s : %s , %s\n", na[i].number, na[i].name, na[i].phonenumber, na[i].email);
            return;
        }
    }
    printf("�ش� ������ �����ϴ�.\n\n");
    
}

//�ش� ��ȣ ����
void edit_business_card() {
    int num;
    printf("������ ������ ���� ��ȣ�� �Է��ϼ��� : ");
    scanf_s("%d", &num);
    
    for (int i = 0; i < cnt; i++) {
        if (num == na[i].number) {
            printf("������ ����ȣ�� �̸����� �Է��ϼ��� : ");
            scanf_s("%s", na[i].phonenumber, sizeof(na[i].phonenumber));
            scanf_s("%s", na[i].email, sizeof(na[i].email));
            return;
        }
    }
    
    printf("�ش� ������ �����ϴ�.\n\n");


}

//�ش� ��ȣ ����
void delete_business_card() {
    int num;
    show_all_cards();
    printf("������ ���� ��ȣ�� �Է����ּ��� : ");
    scanf_s("%d", &num);
    
    for (int i = 0; i <= cnt; i++) {
        if (num == na[i].number) {
            setting(i);
            return;
        }
    }

    printf("�ش� ������ �����ϴ�.\n\n");


    
    

}

// �����Լ�
int main(void)
{
    int n;

    memset(&na, 0,sizeof(na));

    fp = fopen("card_data.txt", "rb");

    

    if (fp != NULL) {
        int i = 0;
        fread(na, sizeof(na), 1, fp);
        for (i = 0; i < _MAX; i++) {
            if (na[i].number == 0) break;
            cnt++;
        }
        k = na[cnt-1].number+1;
        //printf("%d", k);
    }
        


    while (1) {
        n = selcet();
        if (n == 6) break;
        switch (n) {
            case 1:
                input__business_card();
                break;
            case 2:
                edit_business_card();
                break;
            case 3:
                delete_business_card();
                break;
            case 4:
                show_all_cards();
                break;
            case 5: {
                int num;
                printf("ã�� ��ȣ�� �Է��ϼ���. : ");
                scanf_s("%d", &num);
                search_business_card(num);
                break;
            }
            default:
                printf("�ٽ� �Է��ϼ���.");
                break;
        }
    }
    
    fp = fopen("card_data.txt", "wb");
    fwrite(na, sizeof(na), 1, fp);
    fclose(fp);

    system("pause");
    return EXIT_SUCCESS;
}