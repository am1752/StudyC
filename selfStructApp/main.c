/*
  filename - main.c
  version - 1.0
  description - �⺻ ���� �Լ�
  --------------------------------------------------------------------------------
  first created - 2020.02.01
  writer - Hugo MG Sung.
*/

/*
�ڱ����� ����ü (��Ī NODE) �� ���ؼ� ���� ����Ʈ�� �����, �����ʹ� �Ǽ��� ���� �� �ֵ��� �Ѵ�. ���⼭ insertNode() �Լ��� ���ϸ������� �� NODE �� �߰�, 
deleteNode(int index)�� ���ϴ� ��ġ�� ���� �����ϰ� �Ѵ�.
�� �۾� �� ����� ������ŭ �����͸� ����ϴ� �Լ� printNode()�� �����Ѵ�

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

// �����Լ�
int main(void) 
{   
    int n,nn;
    double num;
    tail = malloc(sizeof(struct NODE));
    
        
    while (1) {
        printf("1. ����\n");
        printf("2. ����\n");
        printf("3. ����\n");
        printf("��ȣ�� �������ּ��� : ");
        scanf_s("%d", &n);
        if (n == 3) break;

        switch (n) {
        case 1:
            printf("�߰��� ���� �Է��ϼ��� : ");
            scanf_s("%lf", &num);
            add(head,num);
            cnt++;
            break;
        case 2:
            printf("������ ��ȣ�� �Է��ϼ��� : ");
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