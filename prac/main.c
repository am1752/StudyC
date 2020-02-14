/*
  filename - main.c
  version - 1.0
  description - �⺻ ���� �Լ�, ��������
  --------------------------------------------------------------------------------
  first created - 2020.02.14
  writer - Lee Chae Eun.
*/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SWAP(X,Y) {int Z = X; X = Y; Y = Z;}

bool chk(int n,int cnt,int *a) {
    for (int i = 0; i < cnt; i++) {
        if (n == a[i]) return false;
    }
    return true;
}



void input_nums(int* lottonums) {
    int n,cnt=0;

    while (1) {
        printf("��ȣ �Է� : ");
        scanf_s("%d", &n);
        if (cnt == 0) {
            lottonums[cnt] = n;
            cnt++;
            continue;
        }
        if (chk(n, cnt, lottonums)) {
            lottonums[cnt] = n;
            cnt++;
        }
        else printf("���� ��ȣ�� �ֽ��ϴ�.!\n");
        if (cnt == 6) break;
    }
    
}

void print_nums(int* lottonums) {
    printf("�ζ� ��ȣ : ");
    for (int i = 0; i < 6; i++) printf("%d ", lottonums[i]);
    printf("\n");
}


// �����Լ�
int main(void) 
{
    int lotto_nums[6];

    input_nums(lotto_nums);
    print_nums(lotto_nums);

    system("pause");
	return EXIT_SUCCESS;
}