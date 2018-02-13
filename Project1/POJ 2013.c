#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

void print(int n)
{
	char s1[10], s2[10];

	scanf("%s", &s1);
	printf("%s\n", s1);
	if (--n)
	{
		scanf("%s\n", s2);
		if (--n)
		{
			print(n);
		}
		printf("%s\n", s2);
	}
}

int main()
{
	int num, t = 1;

	scanf("%d", &num);
	while (num != 0)
	{
		printf("SET %d\n", t);
		print(num);
		t++;
		scanf("%d", &num);
	}

	return 0;
}