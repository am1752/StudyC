/*
  filename - main.c
  version - 1.0
  description - �⺻ ���� �Լ�,���
  --------------------------------------------------------------------------------
  first created - 2020.02.13
  writer - lee chae eun
*/

/*
1���� 300������ ����(����) �߿��� 3�� �����(3,6,9,12,..)���� ������ ����ϴ� ���α׷��� �ۼ��Ͻÿ�. (for�� ���)

*/

#include <stdio.h>
#include <stdlib.h>

// �����Լ�
int main(void) 
{
    int s = 0;

    for (int i = 3; i <= 300; i += 3) s += i;

    printf("%d\n", s);

	system("pause");
	return EXIT_SUCCESS;
}