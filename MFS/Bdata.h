#pragma once

#include<string>
using namespace std;
class Bdata
{
public:
	Bdata();  // 默认构造函数
	Bdata(int _year, int _month, int _day);
	Bdata(const Bdata & B);  // 拷贝构造函数
	virtual ~Bdata();
	friend ostream &operator<<(ostream & output, Bdata b);  //运算符重载
	friend istream &operator>>(istream & input, Bdata b);
protected:
private:
	int year;  // 出生年
	int month;  //出生月
	int day;  // 出生日
};
