/*
  filename - main.c
  version - 1.0
  description - �⺻ ���� �Լ�/����
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
    printf("���� �߻� : %s\n", message);
    return;
}

// �����Լ�
int main(void)
{

    WSADATA wsaData;
    SOCKET seversocket, clientsocket;
    SOCKADDR_IN severaddress, clientaddress;

    int severport = 9876; //1~1024�� ��Ʈ�� �̹��������ֱ� ������ �� �̻����� ����
    char received[256]; // �ּҰ��� 0~255

    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {//winsocket �ʱ�ȭ
        ShowErrorMessage("WSAStartup()");
    }

    seversocket = socket(PF_INET, SOCK_STREAM, 0);//TCP ���� ����

    if (seversocket == INVALID_SOCKET) ShowErrorMessage("socket()");

    memset(&severaddress, 0, sizeof(severaddress));
    severaddress.sin_family = AF_INET;
    severaddress.sin_addr.s_addr = htonl(INADDR_ANY);//4����Ʈ ������ ��Ʈ��ũ ����Ʈ ��������
    severaddress.sin_port = htons(severport); //2����Ʈ ������ ��Ʈ��ũ ����Ʈ ��������

    if (bind(seversocket, (SOCKADDR*)&severaddress, sizeof(severaddress)) == SOCKET_ERROR) {
        ShowErrorMessage("bind()");
    }
    printf("[���� ����] bind()\n");

    if (listen(seversocket, 5) == SOCKET_ERROR) ShowErrorMessage("listen()");
    printf("[���� ����] listen()\n");

    int sizeClinetAddress = sizeof(clientaddress);
    clientsocket = accept(seversocket, (SOCKADDR*)&clientaddress, &sizeClinetAddress);
    printf("[���� accept()\n");

    if (clientsocket == INVALID_SOCKET) ShowErrorMessage("accept()");


    while (1) { //Ŭ���̾�Ʈ�� �޼����� �޾Ƽ� �״�� �ٽ� ����
        int length = recv(clientsocket, received, sizeof(received), 0);
        received[length] = NULL;
        printf("[Ŭ���̾�Ʈ �޼���] : %s\n", received);
        printf("[�޼��� ����] : %s\n", received);

        if (strcmp(received, "[exit]") == 0) {
            send(clientsocket, received, sizeof(received) - 1, 0);
            printf("[���� ����]\n");
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