/*
  filename - main.c
  version - 1.0
  description - 기본 메인 함수
  --------------------------------------------------------------------------------
  first created - 2020.02.01
  writer - Hugo MG Sung.
*/

/*
자기참조 구조체 (명칭 NODE) 를 통해서 연결 리스트를 만들고, 데이터는 실수를 담을 수 있도록 한다. 여기서 insertNode() 함수로 제일마지막에 새 NODE 를 추가, 
deleteNode(int index)로 원하는 위치의 값을 삭제하게 한다.
각 작업 후 노드의 갯수만큼 데이터를 출력하는 함수 printNode()를 구현한다

*/

#include <stdio.h>
#include <stdlib.h>

int cnt = 0;
struct NODE {    
    struct NODE* next;  
    struct NODE* prev;
    double data;             
};
struct NODE* head;
struct NODE* tail;

void add(struct NODE* node, double da)    
{
    struct NODE* curr = node;
    struct NODE* tmp = malloc(sizeof(struct NODE));
    tmp->data = da;
    tmp->next = NULL;
    if (cnt == 0) {
        head = tmp;
        return;
    }

    while (curr->next != NULL)
    {
        curr = curr->next;
    }
    curr->next = tmp;
            
}


void del(struct NODE* node, int data)
{
    struct NODE* c = node;
    struct NODE* tmp;
    int i = 1;
    if (cnt < data) return;
    
    for (int i = 0; i < data-1; i++) {
        c = c->next;
    }
    
    if (((c->next)->next) != NULL) {
        tmp = c->next;
        (c->next) = c->next->next;
        free(tmp);
    }
    else {
        free(tmp);
        return;
    }    
}


void  print(struct NODE* curr){
    
    while (curr != NULL)               
    {
        printf("%.1lf\n", curr->data);    
        curr = curr->next;       
    }
}

// 메인함수
int main(void) 
{   
    int n,nn;
    double num;
    tail = malloc(sizeof(struct NODE));
    
        
    while (1) {
        printf("1. 삽입\n");
        printf("2. 삭제\n");
        printf("3. 종료\n");
        printf("번호를 선택해주세요 : ");
        scanf_s("%d", &n);
        if (n == 3) break;

        switch (n) {
        case 1:
            printf("추가할 값을 입력하세요 : ");
            scanf_s("%lf", &num);
            add(head,num);
            cnt++;
            break;
        case 2:
            printf("삭제할 번호를 입력하세요 : ");
            scanf_s("%d", &nn);
            del(head,nn);
            cnt--;
            break;
        }
    }

    print(head);
    free(head);   
    

	system("pause");
	return EXIT_SUCCESS;
}