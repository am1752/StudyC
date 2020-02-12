/*
  filename - main.c
  version - 1.0
  description - �⺻ ���� �Լ�,parson ��뿹��
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

    rootValue = json_parse_file("package.json"); // json ���� �ε� , �ʱ�ȭ
    rootObject = json_value_get_object(rootValue); //JSON_VALUE���� JSON_OBJECT ȹ��

    /*���*/
    //��ü���� Ű�� �ش��ϴ� ���ڿ� ����
    printf("name : %s\n", json_object_get_string(rootObject, "name"));

    printf("version : %s\n", json_object_get_string(rootObject, "version"));
    //json_object_get_string=> ���� Ű���� �����Ͽ�, value���� ���ڿ��� �����Ͽ� ���
    printf("repo : %s\n", json_object_get_string(rootObject, "repo"));

    printf("description : %s\n", json_object_get_string(rootObject, "description"));

    printf("keywords : [\n");
    //��ü���� Ű�� �ش��ϴ� �迭�� ������
    JSON_Array* array = json_object_get_array(rootObject, "keywords");

    for (int i = 0; i < json_object_get_count(array); i++) {
        printf("  %s\n", json_array_get_string(array, i));
    }
    printf("]\n");

    printf("temp : %.1lf\n", json_object_get_number(rootObject, "temp")); //json_object_get_number => ���� Ű ���� �����Ͽ� value�� ���ڰ� ���� 

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

    /* �ʱ�ȭ */
    rootValue = json_value_init_object(); // Json_Value ���� �� �ʱ�ȭ
    rootObject = json_value_get_object(rootValue); // JSON_Value���� Json_Object�� ����
    

    /* ���� ���� �ڵ� // ��� */
    //���ڿ� ����
    json_object_set_string(rootObject, "Title", "InterStellar");//��ü�� Ű �߰�
    

    //���� ����
    json_object_set_number(rootObject, "Year", 2014);
    json_object_set_number(rootObject, "Runtime", 169);

    //���ڿ� ����
    json_object_set_string(rootObject, "Genre", "Sci-Fi");
    json_object_set_string(rootObject, "Director", "Christopher Nolan");

    
    /* ���� - �迭 ��� �ڵ� */

    //�迭 ����
    json_object_set_value(rootObject, "Actors", json_value_init_array());

    //��ü���� �迭 �����͸� ������
    JSON_Array* actors = json_object_get_array(rootObject, "Actors");

    //�迭�� ���ڿ� ��� �߰�
    json_array_append_string(actors, "Matthew McConaughey");
    json_array_append_string(actors, "Anne Hathaway");
    json_array_append_string(actors, "Michael Caine");
    json_array_append_string(actors, "Jessica Chastain");
    json_array_append_string(actors, "Casey Affleck");

    /*���� - �Ҹ�, �Ǽ��� ���� */


    //��ü�� Ű�� �߰��ϰ� ���� ����
    json_object_set_number(rootObject, "imddRating", 8.6);

    //��ü�� Ű�� �߰��ϰ� �� Ÿ�� ����
    json_object_set_boolean(rootObject, "KoreaRelease", 1);

    
    /*���� �� ����*/

    //Json_Value�� ����� �б� ���� ���ڿ�(pretty)�� ���� �� ���Ͽ� ����
    json_serialize_to_file_pretty(rootValue, "saved.json");

    /* ���� */
    json_value_free(rootValue);


}

// �����Լ�
int main(void) 
{
    write_json();
    
	system("pause");
	return EXIT_SUCCESS;
}