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
	return a * b;            //����Ӽ��˵ĺ������Ա��������
};


int main()
{
	using namespace std;
	cout.setf(ios_base::fixed, ios_base::floatfield);//����ģʽ

	int (*pf)(int a, int b);
	double jieguo;
	string str1, str2, name, str3, str4, zifuban;
	int num1 = 0, num2 = 0, beishu, i, xiaoshuwei = 0,weishu=0, chazhi = 0,cha=0;//����������ָ��

	cout << "�������������ͣ��ӡ�����ˣ�\n";
	cin >> name;
	if (name == "��") {
		pf = jia;
	}
	else if (name == "��") {
		pf = jian;
	}
	else if (name == "��") {                       //�ú���ָ����ú���
		pf = cheng;
	}
	else
	{
		std::cerr << "δ֪�ĺ�����: " << name << std::endl;
		exit(0);
	};


	cout << "�������һ������\n";
	cin >> str1;
	cout << "������ڶ�������\n";
	cin >> str2;

	for (i = 0; i < str1.size(); i++)
		if (str1[i] == '.') {
			num1 = i;
		}
		else { str3 += str1[i]; };
	for (i = 0; i < str2.size(); i++)          //��forѭ����ȡ����С����֮��������ַ���
		if (str2[i] == '.') {                  //���Ϊ�����Ρ����ַ���
			num2 = i;                          //����¼С��������λ��
		}
		else { str4 += str2[i]; };
	int n1 = stoi(str3);
	int n2 = stoi(str4);
	int xiaoshuwei1 = str1.size() - num1 - 1;//���ַ���ת��Ϊ���Σ���ȷ��������С��λ
	int xiaoshuwei2 = str2.size() - num2 - 1;
	if (xiaoshuwei1 < xiaoshuwei2)
	{
		chazhi = xiaoshuwei2 - xiaoshuwei1;
		int a = pow(10, chazhi);
		int n3 = n1 * a;                      //�Ƚ�����С��λ��С
		beishu = pf(n3, n2);                  //���С���㵼�µ��������ˡ���10���ݲ�ͬ
		zifuban = to_string(beishu);          //���Խ�С��λ��С����ʮ��С��λ֮��η�
		if (pf == cheng)
		{
			xiaoshuwei = 2 * xiaoshuwei2;     //���Ϊ�˷���������Ϊ10��2��С��λ�ϴ����η�
		}									  
		else                                  
		{
			xiaoshuwei = xiaoshuwei2;         //���Ϊ�Ӽ�������һ��
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
		zifuban.erase(zifuban.size() - chazhi, chazhi);//�˷�ʱ�������ʱ����˵�ʮ���ݻ���
		cha = chazhi;                                  //���������0����ʾ��������Ҫɾ��
	};
	zifuban.insert(zifuban.size() - xiaoshuwei+cha, 1, '.');//����С���㣬��ɼ���
	jieguo = stof(zifuban);
	cout << "ʮ���ƾ�ȷ���Ϊ" << zifuban;

	return 0;
}