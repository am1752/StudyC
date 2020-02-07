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
#include <string.h>
#include <malloc.h>

int a[5][6];
// 메인함수
int main(void) 
{
    /*char* animal[4];
  

    animal[0] = "elephant";
    animal[1] = "tiger";
    animal[2] = "cat";
    animal[3] = "dog";

    for (int i = 0; i < 4; i++) printf("%s\n", animal[i]);
    */
    /*
    int ary1[4] = { 1,2,3,4 };
    int ary2[4] = { 5,6,7,8 };
    int ary3[4] = { 9,10,11,12 };
    int* pary[3] = { ary1,ary2,ary3 };

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%5d", pary[i][j]);
        }
        printf("\n");
    }
    */

    
    /*
    
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 5; j++) {
            a[i][j] = (i + 1) * (j + 1);
            a[i][5] += a[i][j];
            a[4][j] += a[i][j];
            a[4][5] += a[i][j];
        }
    }

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 6; j++) {
            printf("%3d ", a[i][j]);
        }
        printf("\n");
    }
    */

    int a[4] = { 1,2,3,4 };
    int c = sizeof(a) / sizeof(a[0]);

    printf("%d\n",c);

    for (int i = 0; i < c; i++) printf("%d ", a[i]);
    printf("\n");
    for (int i = 0; i < 4; i++) printf("%d ", a[i]);
    system("pause");
    printf("\n");
	return EXIT_SUCCESS;
}