/*
  filename - main.c
  version - 1.0
  description - 기본 메인 함수, 검색2
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
    int number; //명함번호
    char name[30];
    char phonenumber[30];
    char email[30];
} namecard[_MAX];

namecard na;

//번호선택
int selcet() {
    int n;

    printf("\n1. 입력\n");
    printf("2. 수정\n");
    printf("3. 삭제\n");
    printf("4. 전체출력\n");
    printf("5. 검색\n");
    printf("6. 종료\n");

    printf("번호를 입력하세요 (1~6) :  ");
    scanf_s("%d", &n);

    printf("\n");

    return n;
}

//위치 바꾸기
void setting(int num) {
    for (int i = num; i < cnt; i++) {
        na[i] = na[i + 1];
        na[i].number;
    }
    cnt--;
}

//이미 있는 이름인지 확인
int check(char name[]) {
    for (int i = 0; i < cnt; i++) {
        if (strcmp(name, na[i].name) == 0) {
            index = i;
            return 0;
        }
    }
    return 1;
}


//동명이인 확인
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

//여러 동명이인 있을 경우 찾기 
int ssame(char name[], char num[]) {
    for (int i = 0; i < cnt; i++) {
        if (strcmp(name, na[i].name) == 0 && strcmp(num, na[i].phonenumber) == 0) {
            printf("같은 번호가 있습니다.\n\n");
            return 1;
        }
    }
    return 0;
}


//카드 정보 입력
void input__business_card() {
    char name[10], phonenumber[20],email[20];
    printf("이름 전화번호 이메일을 입력하세요. : ");
    
    if (cnt >= 100) {
        printf("메모리 공간이 부족합니다.\n");
        return 0;
    }
    
    scanf_s("%s", name, sizeof(name));
    scanf_s("%s", phonenumber, sizeof(phonenumber));
    scanf_s("%s", email, sizeof(email));

    if (check(name) == 1) {//동명이이인이 아닌경우
        strcpy(na[cnt].name, name);
        strcpy(na[cnt].phonenumber, phonenumber);
        strcpy(na[cnt].email, email);
        na[cnt].number = k ++;
        cnt++;

    }
    else {
        if (strcmp(na[index].phonenumber, phonenumber) == 0) {//같은 정보 다시 입력
            printf("이미 등록된 정보입니다. \n\n");
            }
        else {
            printf("동명이인이 있습니다!!!\n\n");
            if (chk(name) == 0) {//같은 이름이 처음 나온경우
                strcpy(same[ii], name);
                ii++;
                strcpy(na[cnt].name, name);
                strcpy(na[cnt].phonenumber, phonenumber);
                strcpy(na[cnt].email, email);
                na[cnt].number = k++;
                cnt++;
            }
            else {//해당이름이 이미 동명이인인 경우
                if (ssame(name, phonenumber) == 0) {
                    strcpy(na[cnt].name, name);
                    strcpy(na[cnt].phonenumber, phonenumber);
                    strcpy(na[cnt].email, email);
                    na[cnt].number = k++;
                    cnt++;
                }
                else {
                    printf("이미 등록된 정보입니다. \n\n");
                }
            }

        }

    }
}

//전체 출력
void show_all_cards() {
    for (int i = 0; i < cnt; i++) {
        printf("%d. %s : %s , %s\n", na[i].number, na[i].name, na[i].phonenumber, na[i].email);
    }
    printf("\n");
}

//해당 번호 찾기
void search_business_card(int num) {
    for (int i = 0; i < cnt; i++) {
        if (num == na[i].number) {
            printf("%d. %s : %s , %s\n", na[i].number, na[i].name, na[i].phonenumber, na[i].email);
            return;
        }
    }
    printf("해당 정보가 없습니다.\n\n");
    
}

//해당 번호 수정
void edit_business_card() {
    int num;
    printf("수정할 정보의 명함 번호를 입력하세요 : ");
    scanf_s("%d", &num);
    
    for (int i = 0; i < cnt; i++) {
        if (num == na[i].number) {
            printf("수정할 폰번호와 이메일을 입력하세요 : ");
            scanf_s("%s", na[i].phonenumber, sizeof(na[i].phonenumber));
            scanf_s("%s", na[i].email, sizeof(na[i].email));
            return;
        }
    }
    
    printf("해당 정보가 없습니다.\n\n");


}

//해당 번호 삭제
void delete_business_card() {
    int num;
    show_all_cards();
    printf("삭제할 명함 번호를 입력해주세요 : ");
    scanf_s("%d", &num);
    
    for (int i = 0; i <= cnt; i++) {
        if (num == na[i].number) {
            setting(i);
            return;
        }
    }

    printf("해당 정보가 없습니다.\n\n");


    
    

}

// 메인함수
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
                printf("찾을 번호를 입력하세요. : ");
                scanf_s("%d", &num);
                search_business_card(num);
                break;
            }
            default:
                printf("다시 입력하세요.");
                break;
        }
    }
    
    fp = fopen("card_data.txt", "wb");
    fwrite(na, sizeof(na), 1, fp);
    fclose(fp);

    system("pause");
    return EXIT_SUCCESS;
}