#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main() {
	//type here
	/*int age;
	double height;
	
	printf("나이와 키를 입력하세요 : ");
	scanf_s("%d%lf", &age, &height);
	printf("나이는 %d살, 키는 %.1lfcm입니다.\n", age, height);
	*/

	char grade;
	char name[20];

	printf("학점 : ");
	scanf_s("%c", &grade);
	printf("이름 : ");
	scanf_s("%s", name,sizeof(name));
	scanf("%s", name);
	printf("%s의 학점은 %c입니다. \n", name, grade);
	system("pause");
	
}