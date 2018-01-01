#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int monthday[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
struct Date
{
	int year;
	int month;
	int day;
};
typedef struct Date Date;
int IsLeapYear(Date date)
{
	if (date.year % 400 == 0)
	{
		return 1;
	}
	else if ((date.year % 4 == 0) &&
		     (date.year % 100 != 0))
	{
		return 1;
	}
	return 0;
}
int Dayth(Date date)0
{
	int ans = 0;
	for (int i = 1; i < date.month; i++)
	{
		ans += monthday[i];
	}
	ans += date.day;
	printf("%d\n", ans);
	return 0;
}
int Judge(Date date)
{
	if (IsLeapYear(date))
	{
		monthday[2] = 29;
	}
	else
	{
		monthday[2] = 28;
	}
	if (date.month > 12 || date.month<1 ||
		date.day > monthday[date.month] || date.day < 1 || 
		date.year < 0)
	{
		printf("Error input!\n");
		return 0;
	}
	else
	{
		Dayth(date);
	}
	return 0;
}
int main()
{
	Date date;
	scanf("%d%d%d", &date.year, &date.month, &date.day);
	while (date.year != -1)
	{
		Judge(date);
		scanf("%d%d%d", &date.year, &date.month, &date.day);
	}
	return 0;
}