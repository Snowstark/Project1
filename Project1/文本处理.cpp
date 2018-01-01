#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int main()
{
	FILE *ps, *pd;
	char ch;
	ps = fopen("C:\\Space of space\\f1.txt", "r");
	if (ps == NULL)
	{
		printf("Failed!");
		exit(1);
	}
	pd = fopen("f2.txt", "w");
	if (pd == NULL)
	{
		printf("Failed!");
		exit(1);
	}
	ch = fgetc(ps);
	while (!feof(ps))
	{
		putchar(ch);
		if ((ch >= 'a'&&ch <= 'z') || (ch >= 'A'&&ch <= 'Z'))
		{
			fprintf(pd, "%d\n", ch);
		}
		ch = fgetc(ps);
	}
	fclose(ps);
	fclose(pd);
	return 0;
}