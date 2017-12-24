/*来自POJ 1011的一道深度优先搜索的题目，难度很大，超出了这一阶段我的接受范围
  希望能在以后的生活中习惯这种题目*/
#include<iostream>
#include<algorithm>
using namespace std;
int sticks[65];
int used[65];
int n, len;
bool dfs(int i, int l, int t)
{
	if (l == 0)
	{
		t -= len;
		if (t == 0) return true;
		for (i = 0; !used[i]; i++);
		used[i] = true;
		if (dfs(i, len - sticks[i], t)) return true;
		used[i] = false;
		t += len;
	}
	else
	{
		for (int j = i; j < n; ++j)
		{
			if (j > 0 && (sticks[j] == sticks[j - 1] && !used[j - 1]))  continue;
			if (!used[j] && l >= sticks[j])
			{
				l -= sticks[j];
				used[j] = 1;
				if (dfs(j, l, t))  return true;
				used[j] = 0;
				l += sticks[j];
				if (sticks[j] == l) return false;
			}
		}
	}
}
bool cmp(const int a, const int b)
{
	return a > b;
}
int main()
{
	while (cin >> n && n)
	{
		int sum = 0;
		for (int i = 0; i < n; i++)
		{
			cin >> sticks[i]; sum += sticks[i];
			used[i] = 0;
		}
		sort(sticks, sticks + n, cmp);
		bool flag = false;
		for (len = sticks[0]; len <= sum / 2; len++)
		{
			if (sum%len == 0)
			{
				if (dfs(0, len, sum))
				{
					flag = true;
					cout << len << endl;
					break;
				}
			}
		}
		if (!flag)cout << sum << endl;
	}
	return 0;
}