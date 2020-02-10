/*
  filename - main.c
  version - 1.0
  description - 기본 메인 함수,전화번호부
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
int index = 0; //찾는 번호의 인덱스
int ii = 0;//동명이인의 인덱스 번호(즉, 동명이인의 이름갯수)

//메뉴 선택
int output() {
    int n;
    printf("------------- 메뉴 --------------\n");
    printf("1. 전화번호 입력\n");
    printf("2. 전화번호 전체 출력\n");
    printf("3. 전화번호 검색\n");
    printf("4. 전화번호 삭제\n");
    printf("5. 전화번호 변경\n");
    printf("6. 종료\n");
    printf("---------------------------------\n");
    printf("선택>>  선택하세요 : ");
    scanf_s("%d", &n);
    return n;
}


//이름 있는지 확인
int check(char name[],int cnt) {
    for (int i = 0; i < cnt; i++) {
        if (strcmp(name, phone[i].name) == 0) {
            index = i;
            return 0;
        }
    }
    return 1;
}

//삭제 하고 한 칸씩 앞으로
void kk(int cnt) {
    //printf("%d %d\n", cnt, index);
    for (int i = index; i < cnt; i++) {
        phone[i] = phone[i+1];
        phone[i].cnt--;
    }
}

//동명이인 확인
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

//동명이인 일 때 원하는 번호 삭제 및 변경
void same(char name[],char num[],int cnt,int nn) {//nn이 0일 경우 삭제,1일 경우 변화
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
    printf("입력된 정보가 없습니다.\n\n");
}

//번호 입력
int InputPhoneData(int count) {
    char name[10], num[20];
    if (count >= 30) {
        printf("메모리 공간이 부족합니다.\n");
        return 0;
    }
    printf("%d번째 번호입니다.\n",count+1);
    printf("이름과 전화번호를 입력하세요. : ");
    phone[count].cnt = count;
    scanf_s("%s",name ,sizeof(name));
    scanf_s("%s", num,sizeof(num));

    if (check(name,count)==1) {//동명이이인이 아닌경우
        strcpy(phone[count].name, name);
        strcpy(phone[count].number, num);
        return 1;
    }
    else {
        if (strcmp(phone[index].number, num) == 0) {//같은 정보 다시 입력
            printf("이미 등록된 정보입니다. \n\n");
            return 0;
        }
        else {
            printf("동명이인이 있습니다!!!\n\n");
            if (chk(name) == 0) {//같은 이름이 처음 나온경우
                strcpy(naa[ii], name);
                ii++;
                //printf("%d %s\n", ii, naa[ii]);
                
                strcpy(phone[count].name, name);
                strcpy(phone[count].number, num);
                return 1;
            }
            else {//해당이름이 이미 동명이인인 경우
                //printf("%d %s", ii, naa[ii]);
                strcpy(phone[count].name, name);
                strcpy(phone[count].number, num);
                return 1;
            }
            
        }
        
    }
    
}

//모든 정보 출력
void ShowAllData(int count) {
    //InputPhoneData(count);
    for (int i = 0; i < count; i++) {
        printf("%d. %s : %s\n", phone[i].cnt+1, phone[i].name, phone[i].number);
    }
    printf("\n");
}

//해당 정보 출력
void SearchPhoneData(int cnt) {
    char name[10];
    printf("이름을 입력해주세요. : ");
    scanf_s("%s", name, sizeof(name));

    if (check(name, cnt) == 0) {
        if (chk(name) == 0) {
            printf("%s님의 번호는 %s 입니다.\n\n", phone[index].name, phone[index].number);
            return;
        }
        else {
            for (int i = 0; i < cnt; i++) {
                if (strcmp(name, phone[i].name) == 0) printf("%s님의 번호는 %s입니다.\n", name, phone[i].number);
            }
            return;
        }
        
    }
    printf("%s님의 번호가 입력되지 않았습니다.\n\n", name);
}

//해당 정보 삭제
int DeletePhoneData(int cnt) {
    char name[10];
    char nn[20];
    printf("이름을 입력해주세요 : ");
    scanf_s("%s", name,sizeof(name));
    if (check(name, cnt) == 0) {
        if (chk(name) == 0) {
            kk(cnt);
            printf("삭제 되었습니다.\n\n");
        }
        else {
            printf("동명이인이 있습니다.\n");
            printf("번호를 입력해주세요. : ");
            scanf_s("%s", nn, sizeof(nn));
            printf("삭제 되었습니다.\n\n");
            same(name, nn, cnt, 0);
        }
        return 1;
    }

    printf("주소록에 해당이름이 없습니다.\n\n");
    return 0;
}

//해당 정보 변경
void ChangePhoneData(int cnt) {
    char name[10];
    char num[20],pnum[20];
    printf("번호를 변경할 사람의 이름을 입력하세요 : ");
    scanf_s("%s", name,sizeof(name));

    if (check(name, cnt) == 0 && chk(name)== 0) {
        printf("변경할 번호를 입력하세요. : ");
        scanf_s("%s", num,sizeof(num));
        strcpy(phone[index].number, num);
    }

    else if (check(name, cnt) == 0 && chk(name) == 1) {
        printf("동명이인이 있습니다. \n");
        printf("예전 번호를 입력하세요 : ");
        scanf_s("%s", pnum, sizeof(pnum));
        same(name, pnum, cnt, 1);
        printf("\n");
        printf("변경할 번호를 입력하세요 : ");
        scanf_s("%s", num, sizeof(num));
        strcpy(phone[index].number, num);
        printf("성공적으로 변경되었습니다.\n\n");

    }
    else printf("해당하는 사람이 없습니다.\n");
}

// 메인함수
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
                printf("값을 다시 입력하세요. (1~6) ");
                break;
        }

    }

	system("pause");
	return EXIT_SUCCESS;
}