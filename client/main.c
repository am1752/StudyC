/*
  filename - main.c
  version - 1.0
  description - �⺻ ���� �Լ�/Ŭ���̾�Ʈ
  --------------------------------------------------------------------------------
  first created - 2020.02.10
  writer - LEE CHAE EUN.
*/
#define _WINSOCK_DEPRECATED_NO_WARNINGS //���ϰ��� ��� �ذ�
#include <stdio.h>
#include <stdlib.h>
#include <WinSock2.h>
#include <string.h>
#define MAX_BUFFER        1024
#define SERVER_IP        "127.0.0.1"

#pragma comment(lib, "ws2_32.lib")//accept�� ��� ���� �Լ��ҷ����� ���� ��

typedef struct SOCKETINFO
{
    WSAOVERLAPPED overlapped;
    WSABUF dataBuffer;
    int receiveBytes;
    int sendBytes;
}SO;

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

    if (connect(clientsocket, (SOCKADDR*)&severaddress, sizeof(severaddress)) == SOCKET_ERROR) {//������ ���� ���н� �����޼��� ���
        ShowErrorMessage("connect()");
    }
    printf("[���� ����] connect()\n"); //������� ���
        
    SO* socketInfo;

    while (1) { //�ݺ������� ������ �޼����� �����ϰ� ���� �޼��� ���� ����
        printf("[�޼��� ����] : ");

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
        }//�޼��� �Է�

        if (strcmp(messageBuffer, "[exit]") == 0) break; //��� ����
        bufferLen = i;

        socketInfo = (struct SOCKETINFO*)malloc(sizeof(struct SOCKETINFO));//���� �����Ҵ�

        //�޸��� ���������� ���ӵ� ������ ����Ʈ�� ��� ���
        memset((void*)socketInfo, 0, sizeof(struct SOCKETINFO));//�� ������ �� �о����



        socketInfo->dataBuffer.len = bufferLen; //���ۿ� ���� ����

        socketInfo->dataBuffer.buf = messageBuffer; //���ۿ� ��������

        // 3-1. ������ ����
        int sendBytes = send(clientsocket, messageBuffer, bufferLen, 0);//�Է� �޼��� ����
        if (sendBytes > 0)
        {
            printf("[Ŭ���̾�Ʈ �޼���] : %s \n", messageBuffer); //Ŭ���̾�Ʈ �޼��� ���
            // 3-2. ������ �б�
            int receiveBytes = recv(clientsocket, messageBuffer, MAX_BUFFER, 0);
            if (receiveBytes > 0)
            {
                printf("[���� �޼���] : %s\n* Enter Message\n->", messageBuffer);
            }
        }


        //printf("[���� �޼���] : %s\n", received);
    }

    closesocket(clientsocket);


    WSACleanup();
    system("pause");
    return EXIT_SUCCESS;
}