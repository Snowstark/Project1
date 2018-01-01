#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#define N 50
struct student
{
	char ID[20];
	char name[30];
	int age;
	double score;
};
typedef struct student student;
void sort(student stu[], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (stu[i].score < stu[j].score)
			{
				student temp;
				temp = stu[i];
				stu[i] = stu[j];
				stu[j] = temp;
			}
		}
	}
	for (int i = 0; i < N; i++)
	{
		printf("%s\n%s\n%d\n%lf\n\n", stu[i].ID, stu[i].name, stu[i].age, stu[i].score);
	}
}
void Readout()
{
	FILE *p;
	char ch;
	p = fopen("C:\\Space of space\\Info.dat", "rb");
	if (p == NULL)
	{
		printf("Failed!\n");
		exit(1);
	}
	ch = fgetc(p);
	while (!feof(p))
	{
		putchar(ch);
		ch = fgetc(p);
	}
}8
int main()
{
	student stu[N];
	FILE *p1;
	p1 = fopen("C:\\Space of space\\Info.dat", "wb");
	if (p1 == NULL)
	{
		printf("Failed!\n");
		exit(1);
	}
	for (int i = 0; i < N; i++)
	{
		fscanf(p1, "%s\n%s\n%d\n%lf\n\n", stu[i].ID, stu[i].name, &stu[i].age, &stu[i].score);
	}
	fclose(p1);
	Readout();
	sort(stu, N);
	return 0;
}