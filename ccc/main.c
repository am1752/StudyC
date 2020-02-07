/*
  filename - main.c
  version - 1.0
  description - 기본 메인 함수
  --------------------------------------------------------------------------------
  first created - 2020.02.05
  writer  Lee Chae Eun.
*/


#include <stdio.h>
#include <stdlib.h>
//#include <minwindef.h>
#include<Windows.h>
//#include <WinSock2.h>
//#include<fileapi.h>
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
int gethostname(char* name, int namelen);
//실패 시 : -1(SOCKET_ERROR)반환
//호스트 엔트리를 얻어오는 함수
struct hostent* gethostbyname(const char* name);
//호스트 엔트리 구조체
struct  hostent {
    char* h_name;           // 호스트 이름
    char** h_aliases;       // 호스트 별칭 목록
    short   h_addrtype;         //하드웨어 타입, IPv4는 PF_INET
    short   h_length;           //하드웨어 주소 길이
    char** h_addr_list;     //하드웨어 주소 목록
};

#pragma comment(lib,"ws2_32")
IN_ADDR GetDefaultMyIP();
int main()
{
    WSADATA wsadata;
    WSAStartup(MAKEWORD(2, 2), &wsadata);
    IN_ADDR addr;

    addr = GetDefaultMyIP();//디폴트 IPv4 주소 얻어오기
    printf("%s\n", inet_ntoa(addr));//IPv4 주소를 문자열로 출력

    WSACleanup();
    return 0;
}

IN_ADDR GetDefaultMyIP()
{
    char localhostname[MAX_PATH];
    IN_ADDR addr = { 0, };

    if (gethostname(localhostname, MAX_PATH) == SOCKET_ERROR)//호스트 이름 얻어오기
    {
        return addr;
    }
    HOSTENT* ptr = gethostbyname(localhostname);//호스트 엔트리 얻어오기
    while (ptr && ptr->h_name)
    {
        if (ptr->h_addrtype == PF_INET)//IPv4 주소 타입일 때
        {
            memcpy(&addr, ptr->h_addr_list[0], ptr->h_length);//메모리 복사
            break;//반복문 탈출
        }
        ptr++;
    }
    return addr;
}