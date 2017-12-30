/*����POJ 1011��һ�����������������Ŀ���ѶȺܴ󣬳�������һ�׶��ҵĽ��ܷ�Χ
  ϣ�������Ժ��������ϰ��������Ŀ*/
#include<iostream>
#include<algorithm>
using namespace std;
int sticks[65];//������n��ľ������
int used[65];//n��ľ���Ƿ����µı�־
int n, len;//ľ����n��ľ������len

bool dfs(int i, int l, int t)//�жϳ���Ϊlen��ľ���ܷ�����n��ľ�������������и��ľ�����i����ǰľ���ĳ���l��ʣ��ľ���ĳ��Ⱥ�t����lenΪ��λ��
{
	if (l == 0)//��һ������Ϊlen��ľ���������г���ľ��
	{
		t -= len;//����ʣ��ľ���ĳ��Ⱥ�
		if (t == 0) return true;//n��ľ����������
		for (i = 0; !used[i]; i++);//�����ȵݼ�˳��ö�ٵ�һ��δʹ�õ�ľ��i
		used[i] = true;//����ľ��

		if (dfs(i, len - sticks[i], t)) return true;//��������ʣ���ľ������ɹ�����

		used[i] = false;//�ݹ�ʧ�ܣ��ָ�ʧ��ǰ��״̬
		t += len;
	}
	else
	{
		for (int j = i; j < n; ++j)//�����ȵݼ�˳��ö��ľ��i��ľ��n-1
		{
			if (j > 0 && (sticks[j] == sticks[j - 1] && !used[j - 1]))  continue;//��ľ��j-1�ĳ�����ľ��j�ĳ�����ͬ��ľ��jδ��ʹ�ã���ö��ľ��j+1����֦��
			if (!used[j] && l >= sticks[j])//δľ��jδ���£��ҳ���С��l��������ľ��
			{
				l -= sticks[j];
				used[j] = 1;
				if (dfs(j, l, t))  return true;//��������ʣ���ľ������ɹ�����

				used[j] = 0;//δ������ʣ���ľ�����ָ��ݹ�ǰ״̬
				l += sticks[j];

				if (sticks[j] == l) break;//����ǰľ������г�j֮������ľ���޷��������ľ����������ʧ�ܷ���
			}
		}
	}
	return false;//ʧ�ܷ���
}
bool cmp(const int a, const int b)//ľ�����ȱȽϺ���
{
	return a > b;
}
int main()
{
	while (cin >> n && n)//��������ľ��������ֱ������0
	{
		int sum = 0;
		for (int i = 0; i < n; i++)//����n��ľͷ�ĳ��ȣ��ۼƳ��Ⱥͣ���־����ľ��δ������
		{
			cin >> sticks[i]; sum += sticks[i];
			used[i] = 0;
		}
		sort(sticks, sticks + n, cmp);//n��ľ��������˳��ݼ�����
		bool flag = false;//��ʼʱ����־ľ��Ϊһ��
		for (len = sticks[0]; len <= sum / 2; len++)//��[stick[0],sum/2]�����ڰ�����˳��ö��sum������len
		{
			if (sum%len == 0)
			{
				if (dfs(0, len, sum))//����len��ľ��������n��ľ�������־ľ����һ��
				{
					flag = true;
					cout << len << endl;//���ľ������С���ܳ��Ȳ��˳�����
					break;
				}
			}
		}
		if (!flag)cout << sum << endl;//�������Ϊsum��һ��ľ���г���n��ľ��.
	}
	return 0;
}