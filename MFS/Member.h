#pragma once

#include"Bdata.h"
#include<iostream>
#include<iomanip>  // 为了使用setw();
using namespace std;
class Member
{
public:

	Member();  // 默认构造函数
	Member(char* _name, char* _sex, Bdata _Bdate, int _age, double _height, double _weight); // 使用初始化列表
	
	virtual ~Member();

	friend ostream & operator << (ostream & output, const Member &m);  // 运算符重载
	friend istream & operator >> (istream & input, Member &m);   // 提取提取运算符重载

	void changename(const char *_name);  // 修改名字
	void changesex(const char *_sex);  // 修改性别
	void changeBdate(const Bdata _Bdate);  // 修改生日
	void changeage(const int _age);  // 修改年龄
	void changeheight(const double _height);  // 修改身高
	void changeweight(const double _weight);  // 修改体重

private:
	char name[50];  // 姓名
	char sex[50];  // 性别
	Bdata Bdate;  // 出生日期
	int age;  // 年龄
	double height; // 身高
	double weight;  // 体重

};

