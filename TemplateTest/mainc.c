#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main() {
	//type here
		
	printf("%d\n", 100);
	printf("%lf\n", 3.141592);
	printf("%.1lf\n", 3.141592);//소숫점 첫번째자리만 출력
	printf("%.10lf\n", 3.141592);
	printf("%.1lf + %.1lf = %.1lf\n", 10.2, 3.4, 10.2 + 3.4);
			
	system("pause");
}