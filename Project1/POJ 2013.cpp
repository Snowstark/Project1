#include<iostream>                          //Ԥ��������
#include<string>                            
using namespace std;
void print(int n)
{
	string s;//��ǰ�ַ���
	cin >> s;//���뼰�����ǰ�ַ���
	cout << s << endl;
	if (--n)//���뵱ǰ��ĵڶ����ַ�����ѹ��ϵͳջ��
	{
		cin >> s;
		if (--n)
		{
			print(n);
		}
		cout << s << endl;//���ݣ�ջ���ַ�����ջ�����
	}
}
int main()
{
	int n, loop = 1;//�ַ���������ų�ʼ��
	cin >> n;//�����һ���ַ������ϵ��ַ�������
	while (n)
	{
		cout << "Set " << loop++ << endl;//�����ǰ�ַ����������
		print(n);//���նԳƸ�ʽ�����ǰ�ַ�������
		cin >> n;//������һ���ַ������ϵ��ַ�������
	}
	return 0;
}