#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int a[25][25] = { 0 };
int n, m, best = 0;

int read_case()
{
	int i, j;

	scanf("%d %d", &n,&m);
	if (n < 2 || n > 25 || m < 1 || m > 25)
	{
		printf("Error!\n");
		return 0;
	}
	for (int t = 0; t < m; t++)
	{
		scanf("%d %d", &i, &j);
		a[i][j] = 1;
	}

	return 1;
}

void visit(int i, int l)
{
	int j; 
	for (j = 0; j < n; j++)
	{
		if (a[i][j])
		{
			a[i][j] = a[j][i] = 0;
			visit(i, l + 1);
			a[i][j] = a[j][i] = 1;
		}
	}
	if (best < l)
	{
		best = l;
	}
}

void solve_case()
{
	int i = 0;
	for (i = 0; i < n; i++)
	{
		visit(i, 0);
	}

}

int main()
{
	int ans = 0;

	if (!read_case())
	{
		printf("Error!\n");
	}
	solve_case();
	printf("%d\n", best);
	getchar();
	getchar();
	return 0;
}
