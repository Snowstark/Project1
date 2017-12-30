/*UVA 167 八皇后问题
  使用了回溯法，进一步加深对回溯法以及递归的理解与使用
 */
#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<vector>
using namespace std;
bool Left[15] = { 0 }, Right[15] = { 0 }, col[8] = { 0 };//递归回溯时的状态变量，设为全局变量
int p[1000][8];//存储摆放的所有位置
int temp[8];
int n = 0;//不同的摆放方法的数量

void func(int r)
{
	if (r == 8)//边界条件
	{
		for (int i = 0; i < 8; i++)//存入p
		{
			p[n][i] = temp[i];
		}
		n++;
		return;
	}

	else
	{
		for (int j = 0; j < 8; j++)
		{
			int leftn = 7 + j - r;
			int rightn = r + j;

			if (!Left[leftn] && !Right[rightn] && !col[j])//如果相关的位置没有被访问，那么访问且进入下一层递归
			{
				Left[leftn] = 1;
				Right[rightn] = 1;
				col[j] = 1;
				temp[r] = j;
				func(r + 1);

				Left[leftn] = 0;//回溯，恢复递归前的状态
				Right[rightn] = 0;
				col[j] = 0;
			}
		}
	}
}
int main()
{
	func(0);

	int Case;
	int boaed[8][8];//定义棋盘
	scanf("%d", &Case);//读入棋盘数量
	while (Case--)
	{
		for (int i = 0; i < 8; i++)//读入棋盘数据
		{
			for (int j = 0; j < 8; j++)
			{
				scanf("%d", &boaed[i][j]);
			}
		}

		int ans = 0;

		for (int i = 0; i < n; i++)//用求出的所有摆放位置依次代入寻求最大值
		{
			int sum = 0;
			for (int row = 0; row < 8; row++)
			{
				sum += boaed[row][p[i][row]];
			}
			if (ans < sum)
			{
				ans = sum;
			}
		}
		printf("%d", ans);
	}
	return 0;
}