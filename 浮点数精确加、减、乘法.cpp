#include <iostream>
#include <string>
#include <cmath>

int jia(int a, int b)
{
	return a + b;
};

int jian(int a, int b)
{
	return a - b;
};

int cheng(int a, int b)
{
	return a * b;            //定义加减乘的函数，以便后续运算
};


int main()
{
	using namespace std;
	cout.setf(ios_base::fixed, ios_base::floatfield);//定点模式

	int (*pf)(int a, int b);
	double jieguo;
	string str1, str2, name, str3, str4, zifuban;
	int num1 = 0, num2 = 0, beishu, i, xiaoshuwei = 0,weishu=0, chazhi = 0,cha=0;//声明变量及指针

	cout << "请输入运算类型（加、减或乘）\n";
	cin >> name;
	if (name == "加") {
		pf = jia;
	}
	else if (name == "减") {
		pf = jian;
	}
	else if (name == "乘") {                       //用函数指针调用函数
		pf = cheng;
	}
	else
	{
		std::cerr << "未知的函数名: " << name << std::endl;
		exit(0);
	};


	cout << "请输入第一个数字\n";
	cin >> str1;
	cout << "请输入第二个数字\n";
	cin >> str2;

	for (i = 0; i < str1.size(); i++)
		if (str1[i] == '.') {
			num1 = i;
		}
		else { str3 += str1[i]; };
	for (i = 0; i < str2.size(); i++)          //用for循环提取出除小数点之外的所有字符，
		if (str2[i] == '.') {                  //组成为“整形”的字符串
			num2 = i;                          //并记录小数点所在位置
		}
		else { str4 += str2[i]; };
	int n1 = stoi(str3);
	int n2 = stoi(str4);
	int xiaoshuwei1 = str1.size() - num1 - 1;//将字符串转化为整形，并确定两数的小数位
	int xiaoshuwei2 = str2.size() - num2 - 1;
	if (xiaoshuwei1 < xiaoshuwei2)
	{
		chazhi = xiaoshuwei2 - xiaoshuwei1;
		int a = pow(10, chazhi);
		int n3 = n1 * a;                      //比较两数小数位大小
		beishu = pf(n3, n2);                  //提出小数点导致的两数“乘”的10的幂不同
		zifuban = to_string(beishu);          //所以将小数位较小数乘十的小数位之差次方
		if (pf == cheng)
		{
			xiaoshuwei = 2 * xiaoshuwei2;     //如果为乘法，则所乘为10的2倍小数位较大数次方
		}									  
		else                                  
		{
			xiaoshuwei = xiaoshuwei2;         //如果为加减法则是一倍
		};

	}
	else
	{
		chazhi = xiaoshuwei1 - xiaoshuwei2;   
		int a = pow(10, chazhi);
		int n3 = n2 * a;
		beishu = pf(n1, n3);
		zifuban = to_string(beishu);
		if (pf == cheng)
		{
			xiaoshuwei = 2* xiaoshuwei1;
			
		}
		else
		{
			xiaoshuwei = xiaoshuwei1;
		};
	};
	if (pf == cheng)
	{
		zifuban.erase(zifuban.size() - chazhi, chazhi);//乘法时，因计算时所多乘的十的幂会以
		cha = chazhi;                                  //结果后多余的0来表示，所以需要删除
	};
	zifuban.insert(zifuban.size() - xiaoshuwei+cha, 1, '.');//加上小数点，完成计算
	jieguo = stof(zifuban);
	cout << "十进制精确结果为" << zifuban;

	return 0;
}