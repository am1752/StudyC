/*
  filename - main.c
  version - 1.0
  description - �⺻ ���� �Լ�,��ȭ��ȣ��
  --------------------------------------------------------------------------------
  first created - 2020.02.07
  writer - LEE CHAE EUN.
*/

#include <stdio.h>
#include <stdlib.h>
#define _MAX 30

typedef struct _phonebook{
    char name[10];
    int cnt;
    char number[20];
}phonebook[_MAX];

phonebook phone;
char naa[_MAX][20];
//int na[_MAX][_MAX];
int index = 0; //ã�� ��ȣ�� �ε���
int ii = 0;//���������� �ε��� ��ȣ(��, ���������� �̸�����)

//�޴� ����
int output() {
    int n;
    printf("------------- �޴� --------------\n");
    printf("1. ��ȭ��ȣ �Է�\n");
    printf("2. ��ȭ��ȣ ��ü ���\n");
    printf("3. ��ȭ��ȣ �˻�\n");
    printf("4. ��ȭ��ȣ ����\n");
    printf("5. ��ȭ��ȣ ����\n");
    printf("6. ����\n");
    printf("---------------------------------\n");
    printf("����>>  �����ϼ��� : ");
    scanf_s("%d", &n);
    return n;
}


//�̸� �ִ��� Ȯ��
int check(char name[],int cnt) {
    for (int i = 0; i < cnt; i++) {
        if (strcmp(name, phone[i].name) == 0) {
            index = i;
            return 0;
        }
    }
    return 1;
}

//���� �ϰ� �� ĭ�� ������
void kk(int cnt) {
    //printf("%d %d\n", cnt, index);
    for (int i = index; i < cnt; i++) {
        phone[i] = phone[i+1];
        phone[i].cnt--;
    }
}

//�������� Ȯ��
int chk(char name[]) {
    
    //printf("%d\n", ii);
    if (ii == 0) {
        //strcmp(naa[0], name);
        return 0;
    }
    for (int i = 0; i <= ii; i++) {
        //printf("%s %s\n", naa[i], name);
        if (strcmp(naa[i], name) == 0) {
            return 1;
        }
    }
    return 0;
}

//�������� �� �� ���ϴ� ��ȣ ���� �� ����
void same(char name[],char num[],int cnt,int nn) {//nn�� 0�� ��� ����,1�� ��� ��ȭ
    for (int i = 0; i < cnt; i++) {
        if (strcmp(name, phone[i].name) == 0 && strcmp(num, phone[i].number) == 0) {
            //printf("%s %s %d\n", phone[i].name, phone[i].number, i);
            index = i;
            if (nn == 0) {
                kk(cnt);
                return;
            }
            else if (nn == 1) return;
        }
    }
    printf("�Էµ� ������ �����ϴ�.\n\n");
}

//��ȣ �Է�
int InputPhoneData(int count) {
    char name[10], num[20];
    if (count >= 30) {
        printf("�޸� ������ �����մϴ�.\n");
        return 0;
    }
    printf("%d��° ��ȣ�Դϴ�.\n",count+1);
    printf("�̸��� ��ȭ��ȣ�� �Է��ϼ���. : ");
    phone[count].cnt = count;
    scanf_s("%s",name ,sizeof(name));
    scanf_s("%s", num,sizeof(num));

    if (check(name,count)==1) {//������������ �ƴѰ��
        strcpy(phone[count].name, name);
        strcpy(phone[count].number, num);
        return 1;
    }
    else {
        if (strcmp(phone[index].number, num) == 0) {//���� ���� �ٽ� �Է�
            printf("�̹� ��ϵ� �����Դϴ�. \n\n");
            return 0;
        }
        else {
            printf("���������� �ֽ��ϴ�!!!\n\n");
            if (chk(name) == 0) {//���� �̸��� ó�� ���°��
                strcpy(naa[ii], name);
                ii++;
                //printf("%d %s\n", ii, naa[ii]);
                
                strcpy(phone[count].name, name);
                strcpy(phone[count].number, num);
                return 1;
            }
            else {//�ش��̸��� �̹� ���������� ���
                //printf("%d %s", ii, naa[ii]);
                strcpy(phone[count].name, name);
                strcpy(phone[count].number, num);
                return 1;
            }
            
        }
        
    }
    
}

//��� ���� ���
void ShowAllData(int count) {
    //InputPhoneData(count);
    for (int i = 0; i < count; i++) {
        printf("%d. %s : %s\n", phone[i].cnt+1, phone[i].name, phone[i].number);
    }
    printf("\n");
}

//�ش� ���� ���
void SearchPhoneData(int cnt) {
    char name[10];
    printf("�̸��� �Է����ּ���. : ");
    scanf_s("%s", name, sizeof(name));

    if (check(name, cnt) == 0) {
        if (chk(name) == 0) {
            printf("%s���� ��ȣ�� %s �Դϴ�.\n\n", phone[index].name, phone[index].number);
            return;
        }
        else {
            for (int i = 0; i < cnt; i++) {
                if (strcmp(name, phone[i].name) == 0) printf("%s���� ��ȣ�� %s�Դϴ�.\n", name, phone[i].number);
            }
            return;
        }
        
    }
    printf("%s���� ��ȣ�� �Էµ��� �ʾҽ��ϴ�.\n\n", name);
}

//�ش� ���� ����
int DeletePhoneData(int cnt) {
    char name[10];
    char nn[20];
    printf("�̸��� �Է����ּ��� : ");
    scanf_s("%s", name,sizeof(name));
    if (check(name, cnt) == 0) {
        if (chk(name) == 0) {
            kk(cnt);
            printf("���� �Ǿ����ϴ�.\n\n");
        }
        else {
            printf("���������� �ֽ��ϴ�.\n");
            printf("��ȣ�� �Է����ּ���. : ");
            scanf_s("%s", nn, sizeof(nn));
            printf("���� �Ǿ����ϴ�.\n\n");
            same(name, nn, cnt, 0);
        }
        return 1;
    }

    printf("�ּҷϿ� �ش��̸��� �����ϴ�.\n\n");
    return 0;
}

//�ش� ���� ����
void ChangePhoneData(int cnt) {
    char name[10];
    char num[20],pnum[20];
    printf("��ȣ�� ������ ����� �̸��� �Է��ϼ��� : ");
    scanf_s("%s", name,sizeof(name));

    if (check(name, cnt) == 0 && chk(name)== 0) {
        printf("������ ��ȣ�� �Է��ϼ���. : ");
        scanf_s("%s", num,sizeof(num));
        strcpy(phone[index].number, num);
    }

    else if (check(name, cnt) == 0 && chk(name) == 1) {
        printf("���������� �ֽ��ϴ�. \n");
        printf("���� ��ȣ�� �Է��ϼ��� : ");
        scanf_s("%s", pnum, sizeof(pnum));
        same(name, pnum, cnt, 1);
        printf("\n");
        printf("������ ��ȣ�� �Է��ϼ��� : ");
        scanf_s("%s", num, sizeof(num));
        strcpy(phone[index].number, num);
        printf("���������� ����Ǿ����ϴ�.\n\n");

    }
    else printf("�ش��ϴ� ����� �����ϴ�.\n");
}

// �����Լ�
int main(void) 
{
    int cnt = 0;
    int n;
    while (1) {
        n = output();
        printf("\n");
        if (n == 6) break;
        switch (n) {
            case 1:
                if (InputPhoneData(cnt) == 1) cnt++;
                break;
            case 2:
                ShowAllData(cnt);
                break;
            case 3:
                SearchPhoneData(cnt);
                break;
            case 4:
                if(DeletePhoneData(cnt)==1) cnt--;
                break;
            case 5:
                ChangePhoneData(cnt);
                break;
            default:
                printf("���� �ٽ� �Է��ϼ���. (1~6) ");
                break;
        }

    }

	system("pause");
	return EXIT_SUCCESS;
}