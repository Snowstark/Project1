/*���������һ���㽭��ҵ��ѧ��acm������������һ����ͨ���ĳ��򣬺��ѹ���*/
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