/*
  filename - main.c
  version - 1.0
  description - 기본 메인 함수, 검색
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
    int number; //명함번호
    char name[30];
    char phonenumber[30];
    char email[30];
} namecard[_MAX];

namecard na;

//번호선택
int selcet() {
    int n;

    printf("1. 입력\n");
    printf("2. 수정\n");
    printf("3. 삭제\n");
    printf("4. 전체출력\n");
    printf("5. 검색\n");
    printf("6. 종료\n");

    printf("번호를 입력하세요 (1~6) :  ");
    scanf_s("%d", &n);

    return n;
}

//해당 이름이 있는지 확인
int check(int n) {
    for (int i = 0; i < cnt; i++) {
        if (n == na[i].name) return i;
    }
    return -1;
}

//카드 정보 입력
void input__business_card() {
    printf("이름 전화번호 이메일을 입력하세요. : ");
    scanf_s("%s", na[cnt].name, sizeof(na[cnt].name));
    scanf_s("%s", na[cnt].phonenumber, sizeof(na[cnt].phonenumber));
    scanf_s("%s", na[cnt].email, sizeof(na[cnt].email));
    na[cnt].number = cnt + 1;
    cnt++;
}

//전체 출력
void show_all_cards() {
    for (int i = 0; i < cnt; i++) {
        printf("%d. %s : %s , %s\n", na[i].number, na[i].name, na[i].phonenumber, na[i].email);
    }
}

//해당 번호 찾기
void search_business_card(int num) {
    num--;
    if (num > cnt) {
        printf("해당 정보가 없습니다.\n\n");
        return;
    }
    printf("%d. %s : %s , %s\n", na[num].number, na[num].name, na[num].phonenumber, na[num].email);
}

//해당 번호 수정
void edit_business_card() {
    int num;
    printf("수정할 정보의 명함 번호를 입력하세요 : ");
    scanf_s("%d", &num);
    
    num--;
    printf("수정할 폰번호와 이메일을 입력하세요 : ");
    scanf_s("%s", na[num].phonenumber, sizeof(na[num].phonenumber));
    scanf_s("%s", na[num].email, sizeof(na[num].email));


}



// 메인함수
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
                printf("찾을 번호를 입력하세요. : ");
                scanf_s("%d", &num);
                search_business_card(num);
        }
    }

	system("pause");
	return EXIT_SUCCESS;
}