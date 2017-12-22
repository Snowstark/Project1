#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
int main()
{
	int n, d, *s,j,q;
	cin >> n >> d;
	while (n!=0||d!=0)
	{
		bool yes = false;
		s = (int*)calloc(n, sizeof(int));
		for (int i = 0; i < n ; i++)
		{
			s[i] = 1;
		}
		for (int i = 0; i < d; i++)
		{
			for (j = 0; j < n; j++)
			{
				if (s[j] == 0)  scanf("%d", &q);
				else
				{
					cin >> s[j];
				}
			}
		}
		for (j = 0; j < n; j++)
		{
			if (s[j] ==1)
			{
				yes = true;
			}
		}
		if (yes) cout << "Yes" << endl;
		else
		{
			cout << "No" << endl;
		}
		cin >> n >> d;
	}
	return 0;
}