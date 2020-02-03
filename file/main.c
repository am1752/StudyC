/*
  filename - main.c
  version - 1.0
  description - 기본 메인 함수
  --------------------------------------------------------------------------------
  first created - 2020.02.03
  writer - Lee Chae Eun
*/
#pragma warning (disable : 4996)
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <io.h>
#include <Windows.h>
#include <string.h>
#include <conio.h>
#include<malloc.h>

char file_path[_MAX_PATH] = "D:\\documents\\";
intptr_t handle;
struct _finddata_t fd;
char n[1000][_MAX_FNAME];


int check(char *name,int cnt) {
    for (int i = 0; i <= cnt; i++) {
        if (strcmp(n[i], name) == 0) return 0;
    }
    return 1;
}


int main(void)
{      
    int result = 1;
    int cnt = 0;
    FILE *a;
    char buffer[10000];
    while (1) {
        if (kbhit()) {
            if (getch() == 'a') break;
        }

        
        if ((handle = _findfirst("d:\\documents\\*.txt", &fd)) == -1L) {
            continue;
        }
        
        else {
            do {
                char path[_MAX_PATH]="";
                strcpy(path, file_path);
                strcat(path, fd.name);
                if (check(fd.name, cnt) ==1)
                {
                    
                    strcpy(n[cnt++], fd.name);
                    a = fopen(path, "r+");
                    if (fgets(buffer, sizeof(buffer), a) != NULL) {
                        printf("%s\n", buffer);
                    }
                    //printf("%s\n", fd.name);
                    
                }
                
                
            } while (_findnext(handle, &fd) != -1);
            
           }
        
        _findclose(handle);
            
        }
    return 0;
}
