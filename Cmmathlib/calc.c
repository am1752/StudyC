/*
  filename - calc.c
  version - 1.0
  description - 라이브러리 함수
  --------------------------------------------------------------------------------
  first created - 2020.02.11
  writer - Lee Chae Eun.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "calc.h"

int get_total(int* data, int size) {
    int Res = 0;

    for (int i = 0; i < size; i++) {
        Res += data[i];
    }

    return Res;
}
