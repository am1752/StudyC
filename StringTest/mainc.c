#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main() {
	//type here
	char fruit[20] = "strawberry";
	char jam[4] = "jam";
		
	printf("���� : %s\n", fruit);
	strcat(fruit, jam);
	printf("����´ : %s\n", fruit);

	strcpy(fruit, "watermelon");

	printf("�̹� ���� : %s\n", fruit);
}