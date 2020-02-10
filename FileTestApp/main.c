/*
  filename - main.c
  version - 1.0
  description - 기본 메인 함수
  --------------------------------------------------------------------------------
  first created - 2020.02.01
  writer - Hugo MG Sung.
*/

#include <stdio.h>
#include <stdlib.h>

// 메인함수
int main(void) 
{
    FILE* fp;
    char str[20];

    fp = fopen("a.txt", "a+");

    if (fp == NULL) {
        printf("파일을 만들지 못했습니다.\n");
        return 1;
    }

    while (1) {
        printf("과일 이름 : ");
        scanf_s("%s", str,sizeof(str));
        if (strcmp(str, "end") == 0)  break;
        else if (strcmp(str, "list") == 0) {
            fseek(fp, 0, SEEK_SET);//0번째를 처음으로 정함
            while (1) {
                fgets(str, sizeof(str), fp);//파일에 입력 값을 저장
                if (feof(fp))break;//파일 끝에 도달하면 멈춤
                printf("%s", str);//입력받은 파일 화면 출력
            }
        }
        else fprintf(fp, "%s\n", str);//입력한 과일 파일에 출력
    }
    fclose(fp);

	system("pause");
	return EXIT_SUCCESS;
}