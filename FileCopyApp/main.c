/*
  filename - main.c
  version - 1.0
  description - 기본 메인 함수,파일카피
  --------------------------------------------------------------------------------
  first created - 2020.02.10
  writer - Lee Chae Eun.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 메인함수
int main(void)
{
    FILE* ifp, * ofp;
    char name[20];
    int kor, eng, mat;
    int total;
    double avg;
    int res;

    ifp = fopen("aaa.txt", "r");

    if (ifp == NULL) {
        printf("파일 열기 실패\n");
        return 1;
    }

    ofp = fopen("bbb.txt", "w");

    if (ofp == NULL) {
        printf("파일 생성 실패\n");
        return 1;
    }

    while (1) {
        res = fscanf(ifp, "%s%d%d%d", name, &kor, &eng, &mat);
        if (res == EOF) break;
        total = kor + eng + mat;
        avg = total / 3.0;
        fprintf(ofp, "%s%5d%7.1lf\n", name, total, avg);
    }

    fclose(ifp);
    fclose(ofp);

	system("pause");
	return EXIT_SUCCESS;
}