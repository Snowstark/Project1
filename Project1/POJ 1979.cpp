/*POJ 1979 Red and Black  ���ݷ�ѧϰ����
 1��״̬
 2����Ե����
 3��������Χ
 4��Լ������
 5���Ż���֦
*/
#include<iostream>
using namespace std;
#define maxw 25
#define maxh 25
char map[maxw][maxh];
bool visited[maxw][maxh];
int ans, w, h;
void search(int i, int j);
int main()
{
	cin >> w >> h;
	while (w||h)
	{
		int pw, ph;
		ans = 0;
		memset(visited, false, sizeof(visited));
		for (int i = 0; i < h; i++)
		{
			cin >> map[i];
			for (int j = 0; j < w; j++)
			{
				if (map[i][j] == '@')
				{
					pw = i;
					ph = j;
				}
			}
		}
		search(pw, ph);
		cout << ans << endl;
		cin >> w >> h;
	}
	return 0;
}
void search(int i, int j)
{
	if (i<0 || i>=w || j<0 || j>=h || map[i][j] == '#' || visited[i][j])
	{
		return;
	}
	ans++;
	visited[i][j] = true;
	search(i, j + 1);
	search(i, j - 1);
	search(i + 1, j);
	search(i - 1, j);
}