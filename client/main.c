/*
  filename - main.c
  version - 1.0
  description - 기본 메인 함수/클라이언트
  --------------------------------------------------------------------------------
  first created - 2020.02.10
  writer - LEE CHAE EUN.
*/
#define _WINSOCK_DEPRECATED_NO_WARNINGS //소켓관련 경고 해결
#include <stdio.h>
#include <stdlib.h>
#include <WinSock2.h>
#include <string.h>
#define MAX_BUFFER        1024
#define SERVER_IP        "127.0.0.1"

#pragma comment(lib, "ws2_32.lib")//accept등 통신 관련 함수불러오기 위해 씀

typedef struct SOCKETINFO
{
    WSAOVERLAPPED overlapped;
    WSABUF dataBuffer;
    int receiveBytes;
    int sendBytes;
}SO;

void ShowErrorMessage(char* message) {
    printf("오류 발생 : %s\n", message);
    return;
}


// 메인함수
int main(void) 
{
    WSADATA wsaData;
    SOCKET  clientsocket;
    SOCKADDR_IN severaddress;

    int severport = 9896; //1~1024는 포트가 이미정해져있기 때문에 그 이상으로 정함
    char received[256]; // 주소값이 0~255
    char *sent;

    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {//winsocket 초기화
        ShowErrorMessage("WSAStartup()");
    }

    clientsocket = socket(PF_INET, SOCK_STREAM, 0);//TCP 소켓 생성

    if (clientsocket == INVALID_SOCKET) ShowErrorMessage("socket()");

    memset(&severaddress, 0, sizeof(severaddress));
    severaddress.sin_family = AF_INET;
    severaddress.sin_addr.s_addr = inet_addr("127.0.0.1");//문자열 IP를 네트워크 바이트 형식으로
    severaddress.sin_port = htons(severport); //2바이트 정수를 네트워크 바이트 형식으로

    if (connect(clientsocket, (SOCKADDR*)&severaddress, sizeof(severaddress)) == SOCKET_ERROR) {//서버와 연결 실패시 에러메세지 출력
        ShowErrorMessage("connect()");
    }
    printf("[현재 상태] connect()\n"); //연결상태 출력
        
    SO* socketInfo;

    while (1) { //반복적으로 서버로 메세지를 전송하고 에코 메세지 전달 받음
        printf("[메세지 전송] : ");

        char messageBuffer[MAX_BUFFER];
        int i, bufferLen;
        for (i = 0; 1; i++)
        {
            messageBuffer[i] = getchar();
            if (messageBuffer[i] == '\n')

            {
                messageBuffer[i++] = '\0';
                break;
            }
        }//메세지 입력

        if (strcmp(messageBuffer, "[exit]") == 0) break; //통신 종료
        bufferLen = i;

        socketInfo = (struct SOCKETINFO*)malloc(sizeof(struct SOCKETINFO));//소켓 동적할당

        //메모리의 시작점부터 연속된 범위를 바이트로 모두 사용
        memset((void*)socketInfo, 0, sizeof(struct SOCKETINFO));//의 내용을 다 읽어들임



        socketInfo->dataBuffer.len = bufferLen; //버퍼에 길이 저장

        socketInfo->dataBuffer.buf = messageBuffer; //버퍼에 내용저장

        // 3-1. 데이터 쓰기
        int sendBytes = send(clientsocket, messageBuffer, bufferLen, 0);//입력 메세지 전달
        if (sendBytes > 0)
        {
            printf("[클라이언트 메세지] : %s \n", messageBuffer); //클라이언트 메세지 출력
            // 3-2. 데이터 읽기
            int receiveBytes = recv(clientsocket, messageBuffer, MAX_BUFFER, 0);
            if (receiveBytes > 0)
            {
                printf("[서버 메세지] : %s\n* Enter Message\n->", messageBuffer);
            }
        }


        //printf("[서버 메세지] : %s\n", received);
    }

    closesocket(clientsocket);


    WSACleanup();
    system("pause");
    return EXIT_SUCCESS;
}