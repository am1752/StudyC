/*
  filename - main.c
  version - 1.0
  description - �⺻ ���� �Լ�/sysinfo
  --------------------------------------------------------------------------------
  first created - 2020.02.05
  writer - Lee Chae Eun.
*/

//#include <WinSock2.h>
#include <Windows.h>
#include <stdio.h>
#include <malloc.h>
#include<string.h>
#include<sysinfoapi.h>
#include<tchar.h>
#include<time.h>
//#include<regex>
#include<sys/stat.h>
#include<sys/types.h>
#include<io.h>
#include<conio.h>
#include <winnt.rh>


#define DIV 1024
#define WIDTH 7

LPSYSTEMTIME lpSystemTime;
LPSYSTEM_INFO a;
//GetSystemInfo(a);
//#include <regex>

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

#pragma comment(lib,"ws2_32")

//IP �ּ�
IN_ADDR GetDefaultMyIP()
{
    char localhostname[MAX_PATH];
    int* a;
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
//������ �̸�

//os ����
void osinfo() {
    LPWIN32_FIND_DATAW a;  
    

}
//�޸�
void me() {
    MEMORYSTATUSEX statex;

    statex.dwLength = sizeof(statex);

    GlobalMemoryStatusEx(&statex);

    _tprintf(TEXT("There is  %*ld percent of memory in use.\n"),
        WIDTH, statex.dwMemoryLoad);
    _tprintf(TEXT("There are %*I64d total KB of physical memory.\n"),
        WIDTH, statex.ullTotalPhys / DIV);
    _tprintf(TEXT("There are %*I64d free  KB of physical memory.\n"),
        WIDTH, statex.ullAvailPhys / DIV);
    _tprintf(TEXT("There are %*I64d total KB of paging file.\n"),
        WIDTH, statex.ullTotalPageFile / DIV);
    _tprintf(TEXT("There are %*I64d free  KB of paging file.\n"),
        WIDTH, statex.ullAvailPageFile / DIV);
    _tprintf(TEXT("There are %*I64d total KB of virtual memory.\n"),
        WIDTH, statex.ullTotalVirtual / DIV);
    _tprintf(TEXT("There are %*I64d free  KB of virtual memory.\n"),
        WIDTH, statex.ullAvailVirtual / DIV);

    // Show the amount of extended memory available.

    _tprintf(TEXT("There are %*I64d free  KB of extended memory.\n"),
        WIDTH, statex.ullAvailExtendedVirtual / DIV);
}


void na() {
    //������ �̸��� host dlfma
    TCHAR buffer[256] = TEXT("");
    TCHAR szDescription[8][32] = {
        TEXT("NetBIOS"),
        TEXT("DNS hostname"),
        TEXT("DNS domain"),
        TEXT("DNS fully-qualified"),
        TEXT("Physical NetBIOS"),
        TEXT("Physical DNS hostname"),
        TEXT("Physical DNS domain"),
        TEXT("Physical DNS fully-qualified") };
    int cnf = 0;
    DWORD dwSize = sizeof(buffer);

    for (cnf = 1; cnf < 2; cnf++)
    {
        if (!GetComputerNameEx((COMPUTER_NAME_FORMAT)cnf, buffer, &dwSize))
        {
            _tprintf(TEXT("GetComputerNameEx failed (%d)\n"), GetLastError());
            return;
        }
        else _tprintf(TEXT("%s: %s\n"), szDescription[cnf], buffer);

        dwSize = _countof(buffer);
        ZeroMemory(buffer, dwSize);
    }
}

//ip
void ip() {
    WSADATA wsadata;
    WSAStartup(MAKEWORD(2, 2), &wsadata);
    IN_ADDR addr;

    addr = GetDefaultMyIP();//����Ʈ IPv4 �ּ� ������
    printf("%s\n", inet_ntoa(addr));//IPv4 �ּҸ� ���ڿ��� ���

    WSACleanup();
}

void version() {
    //���� ������ ����
    DWORD dwVersion = 0;
    DWORD dwMajorVersion = 0;
    DWORD dwMinorVersion = 0;
    DWORD dwBuild = 0;

    dwVersion = GetVersion();

    // Get the Windows version.

    dwMajorVersion = (DWORD)(LOBYTE(LOWORD(dwVersion)));
    dwMinorVersion = (DWORD)(HIBYTE(LOWORD(dwVersion)));

    // Get the build number.

    if (dwVersion < 0x80000000)
        dwBuild = (DWORD)(HIWORD(dwVersion));

    printf("Version is %d.%d (%d)\n",
        dwMajorVersion,
        dwMinorVersion,
        dwBuild);
}

void ti() {
    //�ð� ���
    SYSTEMTIME lst;

    GetLocalTime(&lst);
    


    printf("�ý��� ��Ʈ �ð� : %4d-%02d-%02d, %02d:%02d:%02d",
        lst.wYear, lst.wMonth, lst.wDay, lst.wHour, lst.wMinute, lst.wSecond);

    printf("\n");
}

struct _finddata_t fd;

int isFileOrDir()
{
    if (fd.attrib & _A_SUBDIR)
        return 0; // ���丮�� 0 ��ȯ
    else
        return 1; // �׹��� ���� "�����ϴ� ����"�̱⿡ 1 ��ȯ

}

void FileSearch(char file_path[],char name[])
{
    intptr_t handle;
    int check = 0;
    char file_path2[_MAX_PATH];
    char n[_MAX_FNAME];

    strcat(file_path, "\\");
    strcpy(file_path2, file_path);
    strcat(file_path, "*");

    if ((handle = _findfirst(file_path, &fd)) == -1)
    {
        return;
    }
    

    while (_findnext(handle, &fd) == 0)
    {
        char file_pt[_MAX_PATH];
        strcpy(file_pt, file_path2);
        strcat(file_pt, fd.name);

        check = isFileOrDir();    //�������� ���丮 ���� �ĺ�

        if (check == 0 && fd.name[0] != '.')
        {
            FileSearch(file_pt,n);    //���� ���丮 �˻� ����Լ�
        }
        else if (check == 1 && fd.size != 0 && fd.name[0] != '.',strcmp(name,fd.name)==0)
        {
            printf("���ϸ� : %s, ũ��:%d\n", file_pt, fd.size);
        }
    }
    _findclose(handle);
}

/*void k(HKEY root, char* key,char path[]) {
    HKEY hkey;
    TCHAR key[512];
    TCHAR value[512];
    DWORD keysize = 512;
    DWORD valuesize = 512;
    int i = 0;
    int result = 0;

    //������Ʈ�� ����
    result = RegOpenKeyEx(root, key, NULL, KEY_ALL_ACCESS, &hkey);

    if (result != ERROR_SUCCESS) {
        return;
    }

    for (i = 0, result = ERROR_SUCCESS; result == ERROR_SUCCESS; i++) {
        keysize = 512;
        valuesize = 512;

        //������Ʈ�� ���� ����
        RegEnumValue(hkey, i, key, &keysize, NULL, NULL,
            (unsigned char*)value, &valuesize);

        //������Ʈ�� Ű, �� ���
        printf("%s : %s", key, value);
    }

    RegCloseKey(hkey);;
}*/

int main()
{
    char file_path[_MAX_PATH] = "c:";

    na();
    
    
    ip();
    
    ti();
    

    version();
    //osinfo();
    me();
    //FileSearch(file_path,"windows");
    //k("SYSTEM//HardwareConfig//Current//BIOSVendor");
    
    
 
}







