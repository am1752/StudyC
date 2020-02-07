/*
  filename - main.c
  version - 1.0
  description - 기본 메인 함수
  --------------------------------------------------------------------------------
  first created - 2020.02.06
  writer - Lee Chae Eun.
*/

#include <stdio.h>
#include <stdlib.h>
/*
void swap_ptr(char** ppa, char** ppb) {
    char* pt;
    pt = *ppa;
    *ppa = *ppb;
    *ppb = pt;
}

// 메인함수
int main(void) 
{
    char* pa = "success";
    char* pb = "failure";

    printf("pa -> %s, pb => %s\n", pa, pb);
    swap_ptr(&pa, &pb);
    printf("pa -> %s, pb => %s\n", pa, pb);

 

	system("pause");
	return EXIT_SUCCESS;
}
*/
void print_ary(int(*pa)[4]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%5d", pa[i][j]);
        }
        printf("\n");
    }
}

void main() {
    int ary[3][4] = { {1,2,3,4},{5,6,7,8},{9,10,11,12} };
    print_ary(ary);


}