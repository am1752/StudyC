#include<stdio.h>
//static int c = 1;
double average(int a, int b) {
	int tot;
	double avg;
	
	tot = a + b;
	
	avg = tot / 2.0;
	//printf("%d\n",tot);
	return avg;
}
void input_data(int *a, int *b) {
	printf("�� ���� �Է� : ");
	scanf_s("%d%d", a, b);
}