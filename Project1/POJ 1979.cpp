/*POJ 1979 Red and Black  ���ݷ�ѧϰ����
 1��״̬
 2����Ե����
 3��������Χ
 4��Լ������
 5���Ż���֦
*/
#include<iostream>//Ԥ�����ļ�
using namespace std;
#define maxw 25//�趨map�������
#define maxh 25
char map[maxw][maxh];//����map
bool visited[maxw][maxh];//��ʶ��Ӧmap���Ƿ��ѱ�����
int ans, w, h;//���������ֵ���У���
void search(int i, int j);
int main()
{
	cin >> w >> h;//����map����
	while (w||h)
	{
		int pw, ph;//��ʼλ��
		ans = 0;//���ֵ��ʼ��
		memset(visited, false, sizeof(visited));//��ʶ���������ʼ��
		for (int i = 0; i < h; i++)
		{
			cin >> map[i];//����map
			for (int j = 0; j < w; j++)
			{
				if (map[i][j] == '@')//��λ��ʼλ��
				{
					pw = i;
					ph = j;
				}
			}
		}
		search(pw, ph);//���ݷ�
		cout << ans << endl;
		cin >> w >> h;//�����µı���
	}
	return 0;
}
void search(int i, int j)
{
	if (i<0 || i>=w || j<0 || j>=h || map[i][j] == '#' || visited[i][j])//��Ե����
	{
		return;//����
	}
	ans++;
	visited[i][j] = true;//��ʶ[i][j]�ѱ�����
	search(i, j + 1);//�ݹ�
	search(i, j - 1);
	search(i + 1, j);
	search(i - 1, j);
}