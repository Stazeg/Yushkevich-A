#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>
//#define float long double 

float sinT(float x, float e, float sinC, int *cnt)
{
	const int N = 150000000;
	int m = -1, i = 2;
	*cnt = i;
	float ans = x, prev = x, LastF = 1;
	for (i = 2; i < N; ++i)
	{
		prev = prev * x / (LastF + 1) * x / (LastF + 2);
		LastF += 2;
		ans += (m * prev);
		m *= -1;
		if (fabs(ans - sinC) - e <= 0)
			break;
	}
	*cnt = i;
	return ans;
}

void change(float *x)
{
	const float PI = acos(-1);
	int m;
	if (*x > PI)    m = -2;
	else     m = 2;
	while ((*x > PI) || (*x < -PI))
		*x += (m * PI);
}

int main()
{
	float x, e, sT, sC;
	int n;
	scanf("%f %f", &x, &e);
    change(&x);
	sC = sin(x);
	printf("%.25f\n", sC);
	sT = sinT(x, e, sC, &n);
	printf("%.25f\n", sT);
	printf("N = %d\n", n);
	//system("pause");
    return 0;
}

