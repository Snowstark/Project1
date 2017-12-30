/*来自POJ 1011的一道深度优先搜索的题目，难度很大，超出了这一阶段我的接受范围
  希望能在以后的生活中习惯这种题目*/
#include<iostream>
#include<algorithm>
using namespace std;
int sticks[65];//给出的n根木条长度
int used[65];//n根木条是否被切下的标志
int n, len;//木条数n，木棒长度len

bool dfs(int i, int l, int t)//判断长度为len的木棒能否切下n根木条。参数：待切割的木条序号i，当前木棒的长度l，剩余木棒的长度和t（以len为单位）
{
	if (l == 0)//将一根长度为len的木棒完整的切成了木条
	{
		t -= len;//计算剩余木条的长度和
		if (t == 0) return true;//n根木条都被切下
		for (i = 0; !used[i]; i++);//按长度递减顺序枚举第一根未使用的木条i
		used[i] = true;//切下木条

		if (dfs(i, len - sticks[i], t)) return true;//若能切下剩余的木条，则成功返回

		used[i] = false;//递归失败，恢复失败前的状态
		t += len;
	}
	else
	{
		for (int j = i; j < n; ++j)//按长度递减顺序枚举木条i至木条n-1
		{
			if (j > 0 && (sticks[j] == sticks[j - 1] && !used[j - 1]))  continue;//若木条j-1的长度与木条j的长度相同且木条j未被使用，则枚举木条j+1（剪枝）
			if (!used[j] && l >= sticks[j])//未木条j未切下，且长度小于l，则切下木条
			{
				l -= sticks[j];
				used[j] = 1;
				if (dfs(j, l, t))  return true;//若能切下剩余的木条，则成功返回

				used[j] = 0;//未能切下剩余的木条，恢复递归前状态
				l += sticks[j];

				if (sticks[j] == l) break;//若当前木棒最后切出j之后，余下木棒无法完成切下木条的任务，则失败返回
			}
		}
	}
	return false;//失败返回
}
bool cmp(const int a, const int b)//木条长度比较函数
{
	return a > b;
}
int main()
{
	while (cin >> n && n)//反复输入木条数量，直到输入0
	{
		int sum = 0;
		for (int i = 0; i < n; i++)//输入n根木头的长度，累计长度和，标志所有木条未被切下
		{
			cin >> sticks[i]; sum += sticks[i];
			used[i] = 0;
		}
		sort(sticks, sticks + n, cmp);//n根木条按长度顺序递减排序
		bool flag = false;//初始时，标志木棒为一根
		for (len = sticks[0]; len <= sum / 2; len++)//在[stick[0],sum/2]区间内按递增顺序枚举sum的因子len
		{
			if (sum%len == 0)
			{
				if (dfs(0, len, sum))//若长len的木棒能切下n根木条，则标志木棒非一根
				{
					flag = true;
					cout << len << endl;//输出木棒的最小可能长度并退出计算
					break;
				}
			}
		}
		if (!flag)cout << sum << endl;//输出长度为sum的一根木棒切出的n根木条.
	}
	return 0;
}