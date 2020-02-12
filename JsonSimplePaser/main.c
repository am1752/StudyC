/*
  filename - main.c
  version - 1.0
  description - �⺻ ���� �Լ�,json
  --------------------------------------------------------------------------------
  first created - 2020.02.12
  writer - Lee Chae Eun.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

//��ū�� �ڽ��� ���ϴ� �������� ������ ������� ��

typedef enum _TOKEN_TYPE { //��ū ���� ������
    TOKEN_STRING,
    TOKEN_NUMBER
} TOKEN_TYPE;

typedef struct _TOKEN { //��ū ����ü
    TOKEN_TYPE type; //��ū ����
    union { //�� ���� �� �� ������ ������ ���̹Ƿ� ����ü�� ����
        char* string; 
        double number;
    };
     bool isArray; //���� ��ū�� �迭���� ǥ��
} TOKEN;

#define TOEKN_COUNT 20 //��ū�� �ִ� ����

typedef struct _JSON { //JSON ����ü
    TOKEN tokens[TOEKN_COUNT]; //��ū �迭
} JSON;

/* �����ϱ�
fseek(file, 0L, SEEK_SET)  // ������ ó������ ���ϴ�.
fseek(file, 0L, SEEK_CUR) // ������ ��ġ�� �ӹ����ϴ�.
fseek(file, 0L, SEEK_END) // ������ ���������� ���ϴ�.
*/

//������ �о ������ ��ȯ
char* readFile(char* filename,int * readSize){
    FILE* fp = fopen(filename, "rb");
    if (fp == NULL) return NULL;
    int size; 
    char* buffer;
   

    
    fseek(fp, 0, SEEK_END); //���� ũ�� ���ϱ�
    size = ftell(fp); // ���� ���� �������� ��ġ�� �̿��� ������ ũ��
    fseek(fp, 0, SEEK_SET);
    buffer = calloc(1, size + 1); //���� ũ�� + NULL ������ŭ �޸� �Ҵ��ϰ� 0���� �ʱ�ȭ


    //�������� ó������ �ۼ�
    if (fread(buffer, size, 1, fp) < 1) { //���� ���� �б�
        *readSize = 0;
        fclose(fp);
        free(buffer);
        return NULL;
    }
    
    *readSize = size; //���� ũ�� �Ѱ���
    fclose(fp);
    return buffer;

}

//JSON �Ľ� �Լ�
void parseJSON(char* doc, int size, JSON* json) {
    int toeknIndex = 0;  // ��ū �ε���
    int pos = 0; // ���� �˻� ��ġ�� �����ϴ� ����
    if (doc[pos] != '{') return; //������ ������ {���� �˻�
    pos++; //���� ���ڷ�

    while (pos < size) { //���� ũ�⸸ŭ �ݺ�
        
        switch (doc[pos]) //������ ������ ���� �б�
        {
        case '"': 
            { //���ڰ� "�̸� ���ڿ�
                //switch-case �Լ� ������ ���� �����ҷ��� case���� {} �������

                char* begin = doc + pos + 1; //���ڿ� ���� ��ġ, �� ���� "�� �����ϱ� ���� +1 
                char* end = strchr(begin, '"'); //������ ����ġ ���� (��������ġ�� "�̸� end�� ���ڿ������� +1 ���� �ƴϸ� NULL ����)
                //strchar(����ڿ�,�˻����ڿ�)
                if (end == NULL) break; //"�� ������ �߸��� �����̹Ƿ� ����

                int stringLength = end - begin; //���ڿ��� ���� ũ��� ����ġ - ������ġ
                json->tokens[toeknIndex].type = TOKEN_STRING; //��ū �迭�� ���ڿ� ����
                json->tokens[toeknIndex].string = calloc(1, stringLength + 1); //���ڿ� ũ�⸸ŭ �����Ҵ�
                memcpy(json->tokens[toeknIndex].string, begin, stringLength); // ��ٹ��ڿ��� ���ڿ� ����(���������� ũ����� ����)
                //�޸� �� ���� (memcpy) <- �ӵ� ���� (����Ǵ� ������ ���ڿ�, ����� ���� ,ũ��)
                toeknIndex++; //��ū �ε��� ����
                pos = pos + stringLength + 1; //���� ��ġ + ���ڿ����� + "(+1)
            
            }
            break;
        }
        pos++; //���� ���ڷ�
    }
}

//JSON �޸� ����
void freeJSON(JSON* json) {
    for (int i = 0; i < TOEKN_COUNT; i++) { //��ũ ����(20) ��ŭ �ݺ�
        if (json->tokens[i].type == TOKEN_STRING) { //��ū ������ ���ڿ��̸�
            free(json->tokens[i].string); //���� �޸� ����
        }
    }
}


// �����Լ�
int main(void) 
{
    int size;
    char* doc = readFile("example.json", &size); //readfile(�����̸�,������) ���� �о����
    if (doc == NULL) return EXIT_FAILURE; //
    JSON json = { 0, }; //JSON ����ü ���� ���� �� �ʱ�ȭ
    parseJSON(doc, size, &json); //JSON ���� �Ľ�
    //JSON ���� �м�(���� �о���� ����,ũ��,���̽� ����ü ���� �ּҰ�)

    int i = 0;
    while (true) {
        if (json.tokens[i].string == 0) break; // �� ��µǸ� ����
        printf("%s : %s\n", json.tokens[i].string, json.tokens[i + 1].string); //�� �ٿ� �ΰ��� �����Ƿ� �� ���� ���
        i += 2; //�� ���� ����ϹǷ� 2�� ����
    }

    freeJSON(&json); //json�� �Ҵ�� ���� �޸� ����
    free(doc); // ���� ���� �޸� ����

	system("pause");
	return EXIT_SUCCESS;
}