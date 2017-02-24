//#include "stdafx.h"     GNU GCC 5.1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()  
{
	char s[250], num[3];
	int f = 10;
	s[0] = '\0';
	for (f; f <= 99; ++f)
	{
		itoa(f, num, 10);
		strcat(s, num);
	}
	num[0] = '\0';
	int k;
	scanf("%d", &k);
	printf("%c\n", s[k - 1]);
	char c;
	scanf("%c", &c);
  return 0;
}

