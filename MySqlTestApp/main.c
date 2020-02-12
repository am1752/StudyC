

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

// 메인함수
int main(void) 
{

	MYSQL* cons = mysql_init(NULL);//mysql 연결 초기화
	MYSQL_RES* res;
	MYSQL_ROW row;
	int fields;
	
	loadmysql(MYSQLIP, cons);//mysql 로드
	printf("\n");
	
	//내용을 불러옴
	mysql_query(cons, "use shopdb;");//shopdb 내용 들고옴
	mysql_query(cons, "SELECT * From membertbl;"); //membertable 내용을 들고옴 ;을 써서 한 줄 끝을 나타냄
	res = mysql_store_result(cons); //쿼리 문 실행 후 결과값을 가져옴,결과의 모든 row들을 한 번에 얻음. /즉, res엔 ROW값들이 저장
	fields = mysql_num_fields(res); //결과값의 필드 갯수 반환. / 즉, fields엔 총 필드의 갯수(각 ROW의 갯수)가 저장(한 줄에 3개의 항목이라서 3저장)
	

	//가져온 값들을 출력
	while (row = mysql_fetch_row(res)) { 
		//결과 ROW들을 담은 result에서 다음 ROW들을 얻어옴(mysql_fetch_row)
		//값 가져와서 뿌리는 실제 로직
		for (int i = 0; i < fields; i++) { //필드 갯수 만큼 출력
			printf("%s\t", row[i]);
			//if (i < fields) printf("\t");
		}
		printf("\n");
	}

	printf("\n");
	mysql_query(cons, "DELETE FROM membertbl WHERE memberID = 'Han';"); // membertable에서 ID가 Han 인 사람 삭제
	mysql_free_result(res); //res 초기화, 일시적으로 값을 초기화
	mysql_close(cons); //쿼리 실행문 닫음
    
		//printf("MySQL info is %s\n",mysql_get_client_info());
	system("pause");
	return EXIT_SUCCESS;
}


void loadmysql(char mysql[], MYSQL* cons) {

	if (cons == NULL) { //cons가 초기화를 못했으면
		fprintf(stderr, "%s\n", mysql_error(cons));//에러 프린트,printf("%s")와 같음
		Sleep(1000); //프로세스를 1초동안 대기(ms가 단위임)
		exit(1);
	}

	if (mysql_real_connect(cons, mysql, MYSQLUSER, MYSQLPASSWORD, NULL, 0, NULL, 0) != NULL) {
		//mysql 서버로 연결성공하면 0 아니면 다른 수 반환
		fprintf(stdout,"접속 성공\n");
		mysql_set_character_set(cons, "euckr");//MYSQL 문자를 지정. 만약 안하면 한글 짤림.
	}

	else {
		fprintf(stderr, "연결 오류 : %s\n", mysql_error(cons));//에러 메세지 출력
		getchar();
	}
}