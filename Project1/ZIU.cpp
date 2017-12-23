/*今天参与了一下浙江工业大学的acm新生赛，其中一道不通过的程序，很难过。*/
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
	int v;
	scanf("%d", &v);
	for (int i = 0; i < v; i++)
	{
		int n, x, y, time;
		scanf("%d %d %d", &n, &x, &y);
		if (n < x)
		{
			time = 0;
		}
		else
		{
			time = 3 + (n - x) / y;
		}
		if ((double)(x / 3.0) <= y)
		{
			time = 3 * (n / x);
		}

		printf("%d\n", time);
	}
	return 0;
}