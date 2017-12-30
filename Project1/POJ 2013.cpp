#include<iostream>                          //预编译命令
#include<string>                            
using namespace std;
void print(int n)
{
	string s;//当前字符串
	cin >> s;//输入及输出当前字符串
	cout << s << endl;
	if (--n)//输入当前组的第二个字符串并压入系统栈区
	{
		cin >> s;
		if (--n)
		{
			print(n);
		}
		cout << s << endl;//回溯，栈首字符串出栈后输出
	}
}
int main()
{
	int n, loop = 1;//字符串集合序号初始化
	cin >> n;//输入第一个字符串集合的字符串个数
	while (n)
	{
		cout << "Set " << loop++ << endl;//输出当前字符串集合序号
		print(n);//按照对称格式输出当前字符串集合
		cin >> n;//输入下一个字符串集合的字符串个数
	}
	return 0;
}