/*
  filename - main.c
  version - 1.0
  description - �⺻ ���� �Լ�
  --------------------------------------------------------------------------------
  first created - 2020.02.01
  writer - Hugo MG Sung.
*/


#include <stdio.h>
#include <stdlib.h>
#include <minwindef.h>
#include<Windows.h>
/*
typedef struct _SYSTEM_INFO {
    union {
        DWORD dwOemId;
        struct {
            WORD wProcessorArchitecture;
            WORD wReserved;
        } DUMMYSTRUCTNAME;
    } DUMMYUNIONNAME;
    DWORD     dwPageSize;
    LPVOID    lpMinimumApplicationAddress;
    LPVOID    lpMaximumApplicationAddress;
    DWORD_PTR dwActiveProcessorMask;
    DWORD     dwNumberOfProcessors;
    DWORD     dwProcessorType;
    DWORD     dwAllocationGranularity;
    WORD      wProcessorLevel;
    WORD      wProcessorRevision;
} SYSTEM_INFO, * LPSYSTEM_INFO;
*/

#include <WinSock2.h>
#include <Windows.h>
#include <stdio.h>

#pragma comment(lib,"ws2_32")
IN_ADDR GetDefaultMyIP();
int main()
{
    WSADATA wsadata;
    WSAStartup(MAKEWORD(2, 2), &wsadata);
    IN_ADDR addr;

    addr = GetDefaultMyIP();//����Ʈ IPv4 �ּ� ������
    printf("%s\n", inet_ntoa(addr));//IPv4 �ּҸ� ���ڿ��� ���

    WSACleanup();
    return 0;
}

IN_ADDR GetDefaultMyIP()
{
    char localhostname[MAX_PATH];
    IN_ADDR addr = { 0, };

    if (gethostname(localhostname, MAX_PATH) == SOCKET_ERROR)//ȣ��Ʈ �̸� ������
    {
        return addr;
    }
    HOSTENT* ptr = gethostbyname(localhostname);//ȣ��Ʈ ��Ʈ�� ������
    while (ptr && ptr->h_name)
    {
        if (ptr->h_addrtype == PF_INET)//IPv4 �ּ� Ÿ���� ��
        {
            memcpy(&addr, ptr->h_addr_list[0], ptr->h_length);//�޸� ����
            break;//�ݺ��� Ż��
        }
        ptr++;
    }
    return addr;
}