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
	
	printf("���̿� Ű�� �Է��ϼ��� : ");
	scanf_s("%d%lf", &age, &height);
	printf("���̴� %d��, Ű�� %.1lfcm�Դϴ�.\n", age, height);
	*/

	char grade;
	char name[20];

	printf("���� : ");
	scanf_s("%c", &grade);
	printf("�̸� : ");
	scanf_s("%s", name,sizeof(name));
	scanf("%s", name);
	printf("%s�� ������ %c�Դϴ�. \n", name, grade);
	system("pause");
	
}