/*POJ 1979 Red and Black  回溯法学习例题
 1、状态
 2、边缘条件
 3、搜索范围
 4、约束条件
 5、优化剪枝
*/
#include<iostream>//预处理文件
using namespace std;
#define maxw 25//设定map最大行列
#define maxh 25
char map[maxw][maxh];//定义map
bool visited[maxw][maxh];//标识相应map点是否已被访问
int ans, w, h;//变量：输出值；行；列
void search(int i, int j);
int main()
{
	cin >> w >> h;//输入map行列
	while (w||h)
	{
		int pw, ph;//初始位置
		ans = 0;//输出值初始化
		memset(visited, false, sizeof(visited));//标识访问数组初始化
		for (int i = 0; i < h; i++)
		{
			cin >> map[i];//输入map
			for (int j = 0; j < w; j++)
			{
				if (map[i][j] == '@')//定位初始位置
				{
					pw = i;
					ph = j;
				}
			}
		}
		search(pw, ph);//回溯法
		cout << ans << endl;
		cin >> w >> h;//输入新的变量
	}
	return 0;
}
void search(int i, int j)
{
	if (i<0 || i>=w || j<0 || j>=h || map[i][j] == '#' || visited[i][j])//边缘条件
	{
		return;//回溯
	}
	ans++;
	visited[i][j] = true;//标识[i][j]已被访问
	search(i, j + 1);//递归
	search(i, j - 1);
	search(i + 1, j);
	search(i - 1, j);
}