/*UVA 167 �˻ʺ�����
  ʹ���˻��ݷ�����һ������Ի��ݷ��Լ��ݹ�������ʹ��
 */
#define _CRT_SECURE_NO_WARNINGS
#include<cstdio>
#include<vector>
using namespace std;
bool Left[15] = { 0 }, Right[15] = { 0 }, col[8] = { 0 };//�ݹ����ʱ��״̬��������Ϊȫ�ֱ���
int p[1000][8];//�洢�ڷŵ�����λ��
int temp[8];
int n = 0;//��ͬ�İڷŷ���������

void func(int r)
{
	if (r == 8)//�߽�����
	{
		for (int i = 0; i < 8; i++)//����p
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

			if (!Left[leftn] && !Right[rightn] && !col[j])//�����ص�λ��û�б����ʣ���ô�����ҽ�����һ��ݹ�
			{
				Left[leftn] = 1;
				Right[rightn] = 1;
				col[j] = 1;
				temp[r] = j;
				func(r + 1);

				Left[leftn] = 0;//���ݣ��ָ��ݹ�ǰ��״̬
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
	int boaed[8][8];//��������
	scanf("%d", &Case);//������������
	while (Case--)
	{
		for (int i = 0; i < 8; i++)//������������
		{
			for (int j = 0; j < 8; j++)
			{
				scanf("%d", &boaed[i][j]);
			}
		}

		int ans = 0;

		for (int i = 0; i < n; i++)//����������аڷ�λ�����δ���Ѱ�����ֵ
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