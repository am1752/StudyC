/*
  filename - main.c
  version - 1.0
  description - 기본 메인 함수/서버
  --------------------------------------------------------------------------------
  first created - 2020.02.07
  writer - Lee Chae Eun.
*/

#include <stdio.h>
//#include <stdlib.h>
#include <string.h>
//#include <windows.h>
#include <iostream>
#include <WinSock2.h>

using namespace std;

void ShowErrorMessage(char* message) {
    printf("오류 발생 : %s\n", message);
    return;
}

// 메인함수
int main(void)
{

    WSADATA wsaData;
    SOCKET seversocket, clientsocket;
    SOCKADDR_IN severaddress, clientaddress;

    int severport = 9876; //1~1024는 포트가 이미정해져있기 때문에 그 이상으로 정함
    char received[256]; // 주소값이 0~255

    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {//winsocket 초기화
        ShowErrorMessage("WSAStartup()");
    }

    seversocket = socket(PF_INET, SOCK_STREAM, 0);//TCP 소켓 생성

    if (seversocket == INVALID_SOCKET) ShowErrorMessage("socket()");

    memset(&severaddress, 0, sizeof(severaddress));
    severaddress.sin_family = AF_INET;
    severaddress.sin_addr.s_addr = htonl(INADDR_ANY);//4바이트 정수를 네트위크 바이트 형식으로
    severaddress.sin_port = htons(severport); //2바이트 정수를 네트워크 바이트 형식으로

    if (bind(seversocket, (SOCKADDR*)&severaddress, sizeof(severaddress)) == SOCKET_ERROR) {
        ShowErrorMessage("bind()");
    }
    printf("[현재 상태] bind()\n");

    if (listen(seversocket, 5) == SOCKET_ERROR) ShowErrorMessage("listen()");
    printf("[현재 상태] listen()\n");

    int sizeClinetAddress = sizeof(clientaddress);
    clientsocket = accept(seversocket, (SOCKADDR*)&clientaddress, &sizeClinetAddress);
    printf("[현재 accept()\n");

    if (clientsocket == INVALID_SOCKET) ShowErrorMessage("accept()");


    while (1) { //클라이언트의 메세지를 받아서 그대로 다시 전달
        int length = recv(clientsocket, received, sizeof(received), 0);
        received[length] = NULL;
        printf("[클라이언트 메세지] : %s\n", received);
        printf("[메세지 전송] : %s\n", received);

        if (strcmp(received, "[exit]") == 0) {
            send(clientsocket, received, sizeof(received) - 1, 0);
            printf("[서버 종료]\n");
            break;
        }
        send(clientsocket, received, sizeof(received) - 1, 0);
    }

    closesocket(clientsocket);
    closesocket(seversocket);
    WSACleanup();
    system("pause");
    return EXIT_SUCCESS;
}