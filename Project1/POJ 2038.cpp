#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
char pic[1000][1000];

void Fractal(int n, int x, int y)
{
	if (n == 1)
	{
		pic[x][y] = 'X';
	}
	else
	{
		int L = pow(3, n - 2);
		Fractal(n - 1, x, y);
		Fractal(n - 1, x + 2 * L, y);
		Fractal(n - 1, x + L, y + L);
		Fractal(n - 1, x, y + 2 * L);
		Fractal(n - 1, x + 2 * L, y + 2 * L);
	}
}

int main()
{
	int n;
	
	scanf("%d", &n);

	while (n != -1)
	{
		for (int i = 0; i < 1000; i++)
		{
			for (int j = 0; j < 1000; j++)
			{
				pic[i][j] = ' ';
			}
		}
		Fractal(n, 0,0);
		for (int i = 0; i < pow(3, n - 1); i++)
		{
			for (int j = 0; j < pow(3, n - 1); j++)
			{
				printf("%c", pic[i][j]);
			}
			printf("\n");
		}
		scanf("%d", &n);
		printf("-\n");
	}

	return 0;
}