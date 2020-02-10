/*
  filename - main.c
  version - 1.0
  description - �⺻ ���� �Լ�/Ŭ���̾�Ʈ
  --------------------------------------------------------------------------------
  first created - 2020.02.10
  writer - LEE CHAE EUN.
*/
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <WinSock2.h>
#include <string.h>

#pragma comment(lib, "ws2_32.lib")

void ShowErrorMessage(char* message) {
    printf("���� �߻� : %s\n", message);
    return;
}


// �����Լ�
int main(void) 
{
    WSADATA wsaData;
    SOCKET  clientsocket;
    SOCKADDR_IN severaddress;

    int severport = 9896; //1~1024�� ��Ʈ�� �̹��������ֱ� ������ �� �̻����� ����
    char received[256]; // �ּҰ��� 0~255
    char *sent;

    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {//winsocket �ʱ�ȭ
        ShowErrorMessage("WSAStartup()");
    }

    clientsocket = socket(PF_INET, SOCK_STREAM, 0);//TCP ���� ����

    if (clientsocket == INVALID_SOCKET) ShowErrorMessage("socket()");

    memset(&severaddress, 0, sizeof(severaddress));
    severaddress.sin_family = AF_INET;
    severaddress.sin_addr.s_addr = inet_addr("127.0.0.1");//���ڿ� IP�� ��Ʈ��ũ ����Ʈ ��������
    severaddress.sin_port = htons(severport); //2����Ʈ ������ ��Ʈ��ũ ����Ʈ ��������

    if (connect(clientsocket, (SOCKADDR*)&severaddress, sizeof(severaddress)) == SOCKET_ERROR) {
        ShowErrorMessage("connect()");
    }
    printf("[���� ����] connect()\n");
        

    while (1) { //�ݺ������� ������ �޼����� �����ϰ� ���� �޼��� ���� ����
        printf("[�޼��� ����] : ");
        sent = getchar();
        if (sent == "") continue; 
        send(clientsocket, &sent, sizeof(sent), 0);
        int length = recv(clientsocket, received, sizeof(received), 0);
        received[length] = NULL;
        if (strcmp(received, "[exit]") == 0) {
            printf("[��������]\n");
            break;
        }
        printf("[���� �޼���] : %s\n", received);
    }

    closesocket(clientsocket);
   
    WSACleanup();
    system("pause");
    return EXIT_SUCCESS;
}