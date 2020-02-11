#pragma once

#define PI 3.141592
#define LIMIT 100.0
#define MSG "passed!"
#define ERR_PRN printf("¹üÀ§¸¦ ¹þ¾î³µ½À´Ï´Ù\n");
#define SUM(a,b) (a+b)
#define MUL(a,b) (a*b)
#define SWAP(a,b) {int c =a; a=b; b=c;}
#define PRINT_EXP(x) printf(#x " = %d\n",x);
#define NAME_CAT(x , y) (x ## y) 
#define VER 7
#define BIT16 16

struct student {
	int num;
	char name[20];
};

typedef struct student Student;

void my_print(void);