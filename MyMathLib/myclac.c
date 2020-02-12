#include<stdio.h>
#include<stdlib.h>
#include "myclac.h"

//#pragma comment(lib,"MyMathLib.lib")

#ifdef __cplusplus
extern "C" {
#endif

	_declspec(dllexport) int int_add(int a, int b) {
		return a + b;
	}

	_declspec(dllexport) int int_multi(int a, int b) {
		return a * b;
	}
#ifdef __cplusplus
}
#endif

