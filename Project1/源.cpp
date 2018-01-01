#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
bool prime(int n)
{
	int k = (int)(sqrt(n));
	bool ans = true;
	if (n == 1)
		return false;
	if (n == 2 || n == 3)
		return true;
	for (int i = 2; i <= k; i++)
	{
		if (n%i == 0)
		{
			ans = false;
		}
	}
	return ans;
}
bool zns(int n)
{
	if (prime(n) && (prime((n + 1) / 2)))
		return true;
	else
		return false;
}
int main()
{
	int n;
	scanf("%d", &n);
	while (n--)
	{
		int a, b, count = 0;
		scanf("%d%d", &a, &b);
		if (a == b)
		{
			if (zns(a))
			{
				printf("1\n");
				continue;
			}
			else
			{
				printf("0\n");
				continue;
			}
		}
		for (int i = a; i <= b; i++)
		{
			if (zns(i))
				count++;
		}
		printf("%d\n", count);
	}
	return 0;
}
