

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <my_global.h>
#include <WinSock2.h>
#include <mysql.h>

#pragma comment(lib,"libmysql.lib")

#define MYSQLUSER "root" //id
#define MYSQLPASSWORD "mysql_p@ssw0rd" //password
#define MYSQLIP "localhost"

void loadmysql(char*, MYSQL*);

// �����Լ�
int main(void) 
{

	MYSQL* cons = mysql_init(NULL);//mysql ���� �ʱ�ȭ
	MYSQL_RES* res;
	MYSQL_ROW row;
	int fields;
	
	loadmysql(MYSQLIP, cons);//mysql �ε�
	printf("\n");
	
	//������ �ҷ���
	mysql_query(cons, "use shopdb;");//shopdb ���� ����
	mysql_query(cons, "SELECT * From membertbl;"); //membertable ������ ���� ;�� �Ἥ �� �� ���� ��Ÿ��
	res = mysql_store_result(cons); //���� �� ���� �� ������� ������,����� ��� row���� �� ���� ����. /��, res�� ROW������ ����
	fields = mysql_num_fields(res); //������� �ʵ� ���� ��ȯ. / ��, fields�� �� �ʵ��� ����(�� ROW�� ����)�� ����(�� �ٿ� 3���� �׸��̶� 3����)
	

	//������ ������ ���
	while (row = mysql_fetch_row(res)) { 
		//��� ROW���� ���� result���� ���� ROW���� ����(mysql_fetch_row)
		//�� �����ͼ� �Ѹ��� ���� ����
		for (int i = 0; i < fields; i++) { //�ʵ� ���� ��ŭ ���
			printf("%s\t", row[i]);
			//if (i < fields) printf("\t");
		}
		printf("\n");
	}

	printf("\n");
	mysql_query(cons, "DELETE FROM membertbl WHERE memberID = 'Han';"); // membertable���� ID�� Han �� ��� ����
	mysql_free_result(res); //res �ʱ�ȭ, �Ͻ������� ���� �ʱ�ȭ
	mysql_close(cons); //���� ���๮ ����
    
		//printf("MySQL info is %s\n",mysql_get_client_info());
	system("pause");
	return EXIT_SUCCESS;
}


void loadmysql(char mysql[], MYSQL* cons) {

	if (cons == NULL) { //cons�� �ʱ�ȭ�� ��������
		fprintf(stderr, "%s\n", mysql_error(cons));//���� ����Ʈ,printf("%s")�� ����
		Sleep(1000); //���μ����� 1�ʵ��� ���(ms�� ������)
		exit(1);
	}

	if (mysql_real_connect(cons, mysql, MYSQLUSER, MYSQLPASSWORD, NULL, 0, NULL, 0) != NULL) {
		//mysql ������ ���Ἲ���ϸ� 0 �ƴϸ� �ٸ� �� ��ȯ
		fprintf(stdout,"���� ����\n");
		mysql_set_character_set(cons, "euckr");//MYSQL ���ڸ� ����. ���� ���ϸ� �ѱ� ©��.
	}

	else {
		fprintf(stderr, "���� ���� : %s\n", mysql_error(cons));//���� �޼��� ���
		getchar();
	}
}