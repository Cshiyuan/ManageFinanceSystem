#include "stdafx.h"
#include "Bdata.h"
#include<iomanip>  //为了使用setw（）


Bdata::Bdata()
{

}
Bdata::Bdata(int _year, int _month, int _day) :year(_year), month(_month), day(_day)
{

}
Bdata::~Bdata()
{

}
Bdata::Bdata(const Bdata & b)  // 拷贝构造函数
{
	year = b.year;
	month = b.month;
	day = b.day;
}
ostream & operator <<(ostream & output, Bdata b)  // 运算符<<的重载
{
	output << setw(6) << b.year << setw(6) << b.month << setw(6) << b.day;
	return output;
}
istream & operator >>(istream & input, Bdata b)  // 运算符>>的重载
{
	input >> b.year >> b.month >> b.day;
	return input;
}
