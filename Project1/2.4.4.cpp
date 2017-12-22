#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
struct a
{
	int date, month, day;
	char name[50];
};
typedef struct a Day;
int compare(Day day1, Day day2);
void sort(Day day[], int n);
int calday(int year, int month)
{
	int dayOfFeb = 28;
	if (year % 4 == 0)dayOfFeb = 29;
	switch (month)
	{
	case

	default:
		break;
	}
}
int main()
{
	Day day[366];
	int year, thisday, thismonth, n = 0,j;
	char c;
	cin >> year >> c;
	while (c == 'A')
	{
		scanf("%d %d %d %s", &day[n].date, &day[n].month, &day[n].day, &day[n].name);
		n++;
		cin >> c;
	}
	sort(day, n);
	while (c == 'D')
	{
		cin >> thisday >> thismonth;
		int num = calday(year, thismonth),cnt = -1;
		for (int i = 0; i < 8; i++)
		{
			for (j = 0; j < n; i++)
			{
				int dday = thisday + i;
				int mmonth = thismonth;
				if (dday > num)
				{
					dday = dday - num;
					mmonth++;
					if (mmonth > 12) mmonth -= 12;
				}
				if (mmonth == day[j].month&&dday == day[j].date)
				{
					printf("%3d%3d ", day[j].date, day[j].month);
					if (i == 0)
					{
						cout << "*TODAY*" << endl;
						printf("%s\n", day[j].name);
					}
					else
					{
						for (int t = 0; t <= day[j].day - i; t++)
						{
							printf("*");
						}
						printf("%s\n", day[j].name);
					}
				}
			}
		}
		cin >> c;
	}
	return 0;
}