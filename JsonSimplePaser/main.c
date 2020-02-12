/*
  filename - main.c
  version - 1.0
  description - 기본 메인 함수,json
  --------------------------------------------------------------------------------
  first created - 2020.02.12
  writer - Lee Chae Eun.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

//토큰은 자신이 원하는 형식으로 구조로 만들어진 것

typedef enum _TOKEN_TYPE { //토큰 종류 열거형
    TOKEN_STRING,
    TOKEN_NUMBER
} TOKEN_TYPE;

typedef struct _TOKEN { //토큰 구조체
    TOKEN_TYPE type; //토큰 종류
    union { //두 종류 중 한 종류만 저장할 것이므로 공용체로 만듦
        char* string; 
        double number;
    };
     bool isArray; //현재 토큰이 배열인지 표시
} TOKEN;

#define TOEKN_COUNT 20 //토큰의 최대 개수

typedef struct _JSON { //JSON 구조체
    TOKEN tokens[TOEKN_COUNT]; //토큰 배열
} JSON;

/* 참고하기
fseek(file, 0L, SEEK_SET)  // 파일의 처음으로 갑니다.
fseek(file, 0L, SEEK_CUR) // 현재의 위치에 머무릅니다.
fseek(file, 0L, SEEK_END) // 파일의 마지막으로 갑니다.
*/

//파일을 읽어서 내용을 반환
char* readFile(char* filename,int * readSize){
    FILE* fp = fopen(filename, "rb");
    if (fp == NULL) return NULL;
    int size; 
    char* buffer;
   

    
    fseek(fp, 0, SEEK_END); //파일 크기 구하기
    size = ftell(fp); // 현재 파일 포인터의 위치를 이용해 파일의 크기
    fseek(fp, 0, SEEK_SET);
    buffer = calloc(1, size + 1); //파일 크기 + NULL 공간만큼 메모리 할당하고 0으로 초기화


    //읽은버퍼 처리로직 작성
    if (fread(buffer, size, 1, fp) < 1) { //파일 내용 읽기
        *readSize = 0;
        fclose(fp);
        free(buffer);
        return NULL;
    }
    
    *readSize = size; //파일 크기 넘겨줌
    fclose(fp);
    return buffer;

}

//JSON 파싱 함수
void parseJSON(char* doc, int size, JSON* json) {
    int toeknIndex = 0;  // 토큰 인덱스
    int pos = 0; // 문자 검색 위치를 저장하는 변수
    if (doc[pos] != '{') return; //문서의 시작이 {인지 검사
    pos++; //다음 문자로

    while (pos < size) { //문자 크기만큼 반복
        
        switch (doc[pos]) //문자의 종류에 따라 분기
        {
        case '"': 
            { //문자가 "이면 문자열
                //switch-case 함수 내에서 변수 선언할려면 case내에 {} 해줘야함

                char* begin = doc + pos + 1; //문자열 시작 위치, 맨 앞의 "를 제외하기 위해 +1 
                char* end = strchr(begin, '"'); //문자의 끝위치 구함 (마지막위치가 "이면 end에 문자열끝에서 +1 저장 아니면 NULL 저장)
                //strchar(대상문자열,검색문자열)
                if (end == NULL) break; //"가 없으면 잘못된 문법이므로 종료

                int stringLength = end - begin; //문자열의 실제 크기는 끝위치 - 시작위치
                json->tokens[toeknIndex].type = TOKEN_STRING; //토큰 배열에 문자열 저장
                json->tokens[toeknIndex].string = calloc(1, stringLength + 1); //문자열 크기만큼 동적할당
                memcpy(json->tokens[toeknIndex].string, begin, stringLength); // 토근문자열에 문자열 복사(시작점부터 크기까지 복사)
                //메모리 값 복사 (memcpy) <- 속도 빠름 (저장되는 공간인 문자열, 복사될 문자 ,크기)
                toeknIndex++; //토큰 인덱스 증가
                pos = pos + stringLength + 1; //현재 위치 + 문자열길이 + "(+1)
            
            }
            break;
        }
        pos++; //다음 문자로
    }
}

//JSON 메모리 해제
void freeJSON(JSON* json) {
    for (int i = 0; i < TOEKN_COUNT; i++) { //토크 개수(20) 만큼 반복
        if (json->tokens[i].type == TOKEN_STRING) { //토큰 종류가 문자열이면
            free(json->tokens[i].string); //동적 메모리 해제
        }
    }
}


// 메인함수
int main(void) 
{
    int size;
    char* doc = readFile("example.json", &size); //readfile(파일이름,사이즈) 파일 읽어오기
    if (doc == NULL) return EXIT_FAILURE; //
    JSON json = { 0, }; //JSON 구조체 변수 선언 및 초기화
    parseJSON(doc, size, &json); //JSON 문서 파싱
    //JSON 문서 분석(파일 읽어오는 변수,크기,제이슨 구조체 변수 주소값)

    int i = 0;
    while (true) {
        if (json.tokens[i].string == 0) break; // 다 출력되면 멈춤
        printf("%s : %s\n", json.tokens[i].string, json.tokens[i + 1].string); //한 줄에 두개씩 있으므로 두 개씩 출력
        i += 2; //두 개씩 출력하므로 2씩 증가
    }

    freeJSON(&json); //json에 할당된 동적 메모리 해제
    free(doc); // 문서 동적 메모리 해제

	system("pause");
	return EXIT_SUCCESS;
}