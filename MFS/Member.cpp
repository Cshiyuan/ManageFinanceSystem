#include "stdafx.h"
#include "Member.h"
#include "Bdata.h"
Member::Member()
{

}
Member::~Member()
{

}
Member::Member(char* _name, char* _sex, Bdata _Bdate, int _age, double _height, double _weight)
	:Bdate(_Bdate), age(_age), height(_height), weight(_weight)
{
		strcpy_s(name, strlen(_name) + 1, _name);  //strcpy函数，就象gets函数一样，它没有方法来保证有效的缓冲区尺寸
		                                           //于是修改成strcpy_s
		strcpy_s(sex, strlen(_sex) + 1, _sex);
}
void Member::changename(const char *_name)
{
		strcpy_s(name, strlen(_name) + 1, _name);
	return;
}
void Member::changesex(const char * _sex)
{
		strcpy_s(sex, strlen(_sex) + 1, _sex);
	return;
}
void Member::changeBdate(const Bdata _Bdata)
{
    Bdate = _Bdata;  // 调用拷贝构造函数
	return;

}
void Member::changeage(const int _age)
{
	age = _age;
	return;
}
void Member::changeheight(const double _height)
{
	height = _height;
}
void Member::changeweight(const double _weight)
{
	weight = _weight;
}
ostream & operator << (ostream & output, const Member &m)
{
	output << "姓名: " << setw(6) << m.name << " 性别: " << setw(6) << m.sex << " 出生日期: " << setw(6) << m.Bdate << endl;
	output << "年龄: " << setw(6) << m.age << " 身高: " << setw(6) << m.height << " 体重: " << setw(6) << m.weight << endl;  // 为了写入文件
	return output;
}
istream & operator >> (istream & input, Member &m)
{
	input >> m.name >> m.sex >> m.Bdate >> m.age >> m.height >> m.weight;
	return input;
}



