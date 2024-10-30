#include <iostream>
#include <string>
#include <cmath>
using namespace std;
double lyh(string str1, string str2)
{
	double jieguo;
	cout.setf(ios_base::fixed, ios_base::floatfield);
	int num1, num2, beishu;
	string str3, str4, zifuban;
	int i;
	for (i = 0; i < str1.size(); i++)
		if (str1[i] == '.') {
			num1 = i;
		}
		else { str3 += str1[i]; };
	for (i = 0; i < str2.size(); i++)
		if (str2[i] == '.') {
			num2 = i;
		}
		else { str4 += str2[i]; };
	int n1 = stoi(str3);
	int n2 = stoi(str4);
	int xiaoshuwei1 = str1.size() - num1 - 1;
	int xiaoshuwei2 = str2.size() - num2 - 1;
	if (xiaoshuwei1 < xiaoshuwei2)
	{
		int chazhi = xiaoshuwei2 - xiaoshuwei1;
		int a = pow(10, chazhi);
		beishu = (n1 * a + n2);
		zifuban = to_string(beishu);
		zifuban.insert(num2, 1, '.');
	}
	else
	{
		int chazhi = xiaoshuwei1 - xiaoshuwei2;
		int a = pow(10, chazhi);
		beishu = (n2 * a + n1);
		zifuban = to_string(beishu);
		zifuban.insert(num1, 1, '.');
	};
	jieguo = stof(zifuban);
	cout << "十进制精确结果为" << zifuban;
	return jieguo;


};
int main()
{
	cout.setf(ios_base::fixed, ios_base::floatfield);
	string num1, num2;
	cin >> num1;
	cin >> num2;
	lyh(num1, num2);

	return 0;
}