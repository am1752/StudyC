/*
  filename - main.c
  version - 1.0
  description - 기본 메인 함수,parson 사용예제
  --------------------------------------------------------------------------------
  first created - 2020.02.12
  writer - Lee Chae Eun.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parson.h"

void read_json(void) {
    JSON_Value* rootValue;
    JSON_Object* rootObject;

    rootValue = json_parse_file("package.json"); // json 파일 로드 , 초기화
    rootObject = json_value_get_object(rootValue); //JSON_VALUE에서 JSON_OBJECT 획득

    /*사용*/
    //객체에서 키에 해당하는 문자열 리턴
    printf("name : %s\n", json_object_get_string(rootObject, "name"));

    printf("version : %s\n", json_object_get_string(rootObject, "version"));
    //json_object_get_string=> 들고올 키값을 선택하여, value값을 문자열에 저장하여 출력
    printf("repo : %s\n", json_object_get_string(rootObject, "repo"));

    printf("description : %s\n", json_object_get_string(rootObject, "description"));

    printf("keywords : [\n");
    //객체에서 키에 해당하는 배열을 가져옴
    JSON_Array* array = json_object_get_array(rootObject, "keywords");

    for (int i = 0; i < json_object_get_count(array); i++) {
        printf("  %s\n", json_array_get_string(array, i));
    }
    printf("]\n");

    printf("temp : %.1lf\n", json_object_get_number(rootObject, "temp")); //json_object_get_number => 들고올 키 값을 선택하여 value의 숫자값 들고옴 

    printf("license : %s\n", json_object_get_string(rootObject, "license"));

    printf("src : [\n");
    array = json_object_get_array(rootObject, "src");
    for (int i = 0; i < json_object_get_count(array); i++) {
        printf("  %s \n", json_array_get_string(array, i));
    }
    printf("]\n");
}

void write_json() {
    JSON_Value* rootValue;
    JSON_Object* rootObject;

    /* 초기화 */
    rootValue = json_value_init_object(); // Json_Value 생성 및 초기화
    rootObject = json_value_get_object(rootValue); // JSON_Value에서 Json_Object를 얻음
    

    /* 쓰기 가능 코딩 // 사용 */
    //문자열 저장
    json_object_set_string(rootObject, "Title", "InterStellar");//객체에 키 추가
    

    //숫자 저장
    json_object_set_number(rootObject, "Year", 2014);
    json_object_set_number(rootObject, "Runtime", 169);

    //문자열 저장
    json_object_set_string(rootObject, "Genre", "Sci-Fi");
    json_object_set_string(rootObject, "Director", "Christopher Nolan");

    
    /* 쓰기 - 배열 기능 코딩 */

    //배열 생성
    json_object_set_value(rootObject, "Actors", json_value_init_array());

    //객체에서 배열 포인터를 가져옴
    JSON_Array* actors = json_object_get_array(rootObject, "Actors");

    //배열에 문자열 요소 추가
    json_array_append_string(actors, "Matthew McConaughey");
    json_array_append_string(actors, "Anne Hathaway");
    json_array_append_string(actors, "Michael Caine");
    json_array_append_string(actors, "Jessica Chastain");
    json_array_append_string(actors, "Casey Affleck");

    /*쓰기 - 불린, 실수형 가능 */


    //객체에 키를 추가하고 숫자 저장
    json_object_set_number(rootObject, "imddRating", 8.6);

    //객체에 키를 추가하고 불 타입 저장
    json_object_set_boolean(rootObject, "KoreaRelease", 1);

    
    /*저장 및 해제*/

    //Json_Value를 사람이 읽기 쉬운 문자열(pretty)로 만든 뒤 파일에 저장
    json_serialize_to_file_pretty(rootValue, "saved.json");

    /* 해제 */
    json_value_free(rootValue);


}

// 메인함수
int main(void) 
{
    write_json();
    
	system("pause");
	return EXIT_SUCCESS;
}