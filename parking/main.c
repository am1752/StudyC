/*
  filename - main.c
  version - 1.0
  description - 기본 메인 함수
  --------------------------------------------------------------------------------
  first created - 2020.02.04.
  writer - Lee Chae Eun.
*/

#include <stdio.h>
#include <stdlib.h>

int space[4][3][6]; //주차현황 지정차량있는 곳은 -1로 표시
int res[4][11]; // 지정차량 번호 저장
int park[4] = { 0,10,10,10 }; //층 별 주차 가능 자리 초기화
int x, y;


//주자창 번호 초기 설정
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

//예약 여부 확인
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

//주차 상황 출력
void output(int num) {
    for (int i = 1; i <= 2; i++) {
        for (int j = 1; j <= 5; j++) {
            
            if (space[num][i][j] == -1) printf("[resv ] ");
            else printf("[%4d ] ", space[num][i][j]);

        }
        printf("\n\n");
    }
}

//기본 내용 출력
void print() {
    printf("1. 주차\n");
    printf("2. 출차\n");
    printf("3. 지정차량 등록\n");
    printf("4. 주차현황 등록\n");
    printf("0. 취소\n\n");

    printf("> 번호선택 : ");
}


//주차관리
void parking() {
    int n,num;
    printf("> 차번 입력(숫자 4자리) : ");
    scanf_s("%d", &n);
    
    if (n < 999 || n>9999) return;

    if (check(n)==0) {//지정등록 여부 확인
        printf("@지정 차량 : B%d층 %d번에 주차하였습니다.\n\n", x, y);
        if (y <= 5) space[x][1][y] = n;
        else space[x][2][y - 5] = n;
        return;
    }

    else {
        printf("@주차 가능 공간 : B1층[%d대] B2층[%d대] B3층[%d대]\n", park[1], park[2], park[3]);
        int i = 1;


        while (1) {
            printf("[B%d층]=========================\n\n", i);
            
            output(i);

            printf(">주차 번호 입력 (다른층 0, 취소 -1) : ");
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

//출차 관리
void outparking() {
    int num;
    printf("> 차번입력(숫자 4자리) : ");
    scanf_s("%d", &num);

    if (num < 999 || num>9999) return;

    if (check(num)==0) {
        if (y <= 5) space[x][1][y] = -1;
        else space[x][2][y - 5] = -1;
        printf("@출차 되었습니다.\n\n");
        return;
    }

    for (int i = 1; i <= 3; i++) {
        for (int j = 1; j <= 2; j++) {
            for (int k = 1; k <= 5; k++) {
                if (space[i][j][k] == num) {
                    //printf("%d\n", num);
                    if (j == 1) space[i][j][k] = k;
                    else space[i][j][k] = k + 5;
                    printf("@출차 되었습니다.\n\n");
                    park[i]++;
                    return;
                }
            }
        }
    }
    printf("@ 해당 차량이 없습니다\n\n");
   
}

void reg() {
    int f, n,num;
    while (1) {
        printf("> 층과 번호 입력(종료 0) : ");
        scanf_s("%d", &f);
        if (f == 0) return;
        scanf_s("%d", &n);
        printf("> 등록차량 번호 입력 : ");
        scanf_s("%d", &num);

        park[f]--;
        res[f][n] = num;
        if (n <= 5) space[f][1][n] = -1;
        else space[f][2][n - 5] = -1;

        printf("@ 등록되었습니다.\n\n");

    }
}

// 메인함수
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
                printf("[B%d층]=========================\n\n", i);
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