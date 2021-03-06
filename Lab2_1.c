#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
int n;

void info(void)
{
	/*printf("Чтобы ввести число, используйте (new N).\n Чтобы вывести число в системе счисления с основанием M[2..16], используйте (to M).\n");
	printf("Чтобы вывести число в системе счисления с основанием M(8/10/16), используйте (output M).\n");
	printf("Чтобы вывести обратное число, используйте inverse.\n Чтобы завершить программу, используйте exit.\n");
	*/
}

char sign(int digit)
{
	if (digit <= 9)    return (char)48 + digit;
	else    return (char)65 + digit - 10;
}

int input(void)
{
	int base;
	char s[80], c;
	memset(s, 0, sizeof(0));
	scanf("%s", s);
	switch ((int)s[0])
	{
		case 110:      /*new N*/
		{
			scanf("%d", &n);
			return 1;
		}
		case 111:       /*output N (hex/dec/oct)*/
		{
			scanf("%d", &base);
			switch (base)
			{
				case 8:
				{
					printf("%o\n", n);
					break;
				}	
				case 10:
				{
					printf("%d\n", n);
					break;
				}
				case 16:
				{
					printf("%X\n", n);
					break;
				}
				default:
				{
					printf("wrong input\n");
					break;
				}
			}	
			return 1;
		}
		case 105:       /*output 1 / N*/
		{
			printf("%f\n", (float)1 / n);
			return 1;
		}
		case 104:       /*help*/
		{
			printf("ver 1.00.0\nAlexandr Yushkevich\n");
			return 1;
		}
		case 101:       /*exit*/
		{
			return 0;
		}
		case 116:       /*to N(M). M[2..16]*/
		{
			int base, len = 0, i, temp = n;
			char signS;
			scanf("%d", &base);
			memset(s, 0, sizeof(s));
			do
			{
				i = temp % base;
				temp /= base;
				char signS = sign(i);
				strcat(s, &signS);
				++len;
				s[len] = '\0';
			} while (temp != 0);
			for (--len; len >= 0; --len)
				putchar(s[len]);
			printf("\n");
			return 1;
		}
		default:
		{
			printf("wrong input\n");
			return 1;
		}
	}
}

int main()  /*2.1.30*/
{
	info();
	while (input() != 0);
	return 0;
}
