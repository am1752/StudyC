/*
  filename - main.c
  version - 1.0
  description - 기본 메인 함수/클라이언트
  --------------------------------------------------------------------------------
  first created - 2020.02.10
  writer - LEE CHAE EUN.
*/

#define _WINSOCK_DEPRECATED_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <WinSock2.h>
#include <string.h>

#define MAX_BUFFER        1024
#define SERVER_IP        "127.0.0.1"

#pragma comment(lib, "ws2_32.lib")

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

    int severport = 9876; //1~1024는 포트가 이미정해져있기 때문에 그 이상으로 정함
    char received[256]; // 주소값이 0~255
    char sent[MAX_BUFFER];
    char* buffer;

    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {//winsocket 초기화
        ShowErrorMessage("WSAStartup()");
    }

    clientsocket = socket(PF_INET, SOCK_STREAM, 0);//TCP 소켓 생성

    if (clientsocket == INVALID_SOCKET) ShowErrorMessage("socket()");

    memset(&severaddress, 0, sizeof(severaddress));
    severaddress.sin_family = AF_INET;
    severaddress.sin_addr.s_addr = inet_addr("127.0.0.1");//문자열 IP를 네트워크 바이트 형식으로
    severaddress.sin_port = htons(severport); //2바이트 정수를 네트워크 바이트 형식으로

    if (connect(clientsocket, (SOCKADDR*)&severaddress, sizeof(severaddress)) == SOCKET_ERROR) {
        ShowErrorMessage("connect()");
    }
    printf("[현재 상태] connect()\n");


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
        }

        if (strcmp(messageBuffer, "[exit]") == 0) break;
        bufferLen = i;

        socketInfo = (struct SOCKETINFO*)malloc(sizeof(struct SOCKETINFO));
        memset((void*)socketInfo, 0, sizeof(struct SOCKETINFO));

        socketInfo->dataBuffer.len = bufferLen;

        socketInfo->dataBuffer.buf = messageBuffer;

        // 3-1. 데이터 쓰기
        int sendBytes = send(clientsocket, messageBuffer, bufferLen, 0);
        if (sendBytes > 0)
        {
            printf("[클라이언트 메세지] : %s \n", messageBuffer);
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
