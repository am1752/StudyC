/*
  filename - main.c
  version - 1.0
  description - �⺻ ���� �Լ�
  --------------------------------------------------------------------------------
  first created - 2020.02.04.
  writer - Lee Chae Eun.
*/

#include <stdio.h>
#include <stdlib.h>

int space[4][3][6]; //������Ȳ ���������ִ� ���� -1�� ǥ��
int res[4][11]; // �������� ��ȣ ����
int park[4] = { 0,10,10,10 }; //�� �� ���� ���� �ڸ� �ʱ�ȭ
int x, y;


//����â ��ȣ �ʱ� ����
void setting() {
    for (int i = 1; i <= 3; i++) {
        for (int j = 1; j <= 2; j++) {
            for (int k = 1; k <= 5; k++) {
                if (j == 1) space[i][j][k] = k;
                else space[i][j][k] = k+5;
            }
        }
    }
}

//���� ���� Ȯ��
int check(int num) {
    for (int i = 1; i <= 3; i++) {
        for (int j = 1; j <= 10; j++) {
            if (res[i][j] == num) {
                x = i;
                if (j <= 5) y = j;
                else y = j - 5;
                return 0;
            }
        }
    }
    return 1;
}

//���� ��Ȳ ���
void output(int num) {
    for (int i = 1; i <= 2; i++) {
        for (int j = 1; j <= 5; j++) {
            
            if (space[num][i][j] == -1) printf("[resv ] ");
            else printf("[%4d ] ", space[num][i][j]);

        }
        printf("\n\n");
    }
}

//�⺻ ���� ���
void print() {
    printf("1. ����\n");
    printf("2. ����\n");
    printf("3. �������� ���\n");
    printf("4. ������Ȳ ���\n");
    printf("0. ���\n\n");

    printf("> ��ȣ���� : ");
}


//��������
void parking() {
    int n,num;
    printf("> ���� �Է�(���� 4�ڸ�) : ");
    scanf_s("%d", &n);
    
    if (n < 999 || n>9999) return;

    if (check(n)==0) {//������� ���� Ȯ��
        printf("@���� ���� : B%d�� %d���� �����Ͽ����ϴ�.\n\n", x, y);
        if (y <= 5) space[x][1][y] = n;
        else space[x][2][y - 5] = n;
        return;
    }

    else {
        printf("@���� ���� ���� : B1��[%d��] B2��[%d��] B3��[%d��]\n", park[1], park[2], park[3]);
        int i = 1;


        while (1) {
            printf("[B%d��]=========================\n\n", i);
            
            output(i);

            printf(">���� ��ȣ �Է� (�ٸ��� 0, ��� -1) : ");
            scanf_s("%d", &num);
            printf("\n");

            if (num == 0) {
                if (i == 3) i -= 1;
                else i += 1;
                continue;
            }
            else if (num == -1) break;

            else {
                if (num <= 5) space[i][1][num] = n;
                else space[i][2][num - 5] = n;
                park[i]--;
                break;
            }
        }
    }
}

//���� ����
void outparking() {
    int num;
    printf("> �����Է�(���� 4�ڸ�) : ");
    scanf_s("%d", &num);

    if (num < 999 || num>9999) return;

    if (check(num)==0) {
        if (y <= 5) space[x][1][y] = -1;
        else space[x][2][y - 5] = -1;
        printf("@���� �Ǿ����ϴ�.\n\n");
        return;
    }

    for (int i = 1; i <= 3; i++) {
        for (int j = 1; j <= 2; j++) {
            for (int k = 1; k <= 5; k++) {
                if (space[i][j][k] == num) {
                    //printf("%d\n", num);
                    if (j == 1) space[i][j][k] = k;
                    else space[i][j][k] = k + 5;
                    printf("@���� �Ǿ����ϴ�.\n\n");
                    park[i]++;
                    return;
                }
            }
        }
    }
    printf("@ �ش� ������ �����ϴ�\n\n");
   
}

void reg() {
    int f, n,num;
    while (1) {
        printf("> ���� ��ȣ �Է�(���� 0) : ");
        scanf_s("%d", &f);
        if (f == 0) return;
        scanf_s("%d", &n);
        printf("> ������� ��ȣ �Է� : ");
        scanf_s("%d", &num);

        park[f]--;
        res[f][n] = num;
        if (n <= 5) space[f][1][n] = -1;
        else space[f][2][n - 5] = -1;

        printf("@ ��ϵǾ����ϴ�.\n\n");

    }
}

// �����Լ�
int main(void) 
{
    int n;
    setting();
   
    while (1) {
        print();
        scanf_s("%d", &n);

        if (n == 0) break;

        switch (n) {
        case 1:
            parking();
            break;
        case 2:
            outparking();
            break;
        case 3:
            reg();
            break;
        case 4:
            for (int i = 1; i <= 3; i++) {
                printf("[B%d��]=========================\n\n", i);
                output(i);
                printf("\n");
            }
        default:
            break;
        }

    }
	system("pause");
	return EXIT_SUCCESS;
}