/*
  filename - main.c
  version - 1.0
  description - 기본 메인 함수, 연습문제
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
        printf("번호 입력 : ");
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
        else printf("같은 번호가 있습니다.!\n");
        if (cnt == 6) break;
    }
    
}

void print_nums(int* lottonums) {
    printf("로또 번호 : ");
    for (int i = 0; i < 6; i++) printf("%d ", lottonums[i]);
    printf("\n");
}


// 메인함수
int main(void) 
{
    int lotto_nums[6];

    input_nums(lotto_nums);
    print_nums(lotto_nums);

    system("pause");
	return EXIT_SUCCESS;
}