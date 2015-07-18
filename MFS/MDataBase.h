#pragma once
#include"Member.h"
#include<map>
//#define MAX 20  // 宏定义，好修改
class MDataBase
{
public:
	MDataBase();
	virtual ~MDataBase();
	void addmember(int key, char* _name, char* _sex, Bdata _Bdate, int _age, double _height, double _weight);  // 添加成员
	void memberlist();  // 输出所有成员信息
	void delmember(int key);  //根据key删除成员

	void change_name(int key, char* _name);  // 修改姓名
	void change_sex(int key, char* _sex);    // 修改性别
	void change_Bdata(int key, Bdata _Bdata);  // 修改生日
	void change_height(int key, double _height);  // 修改身高
	void change_weight(int key, double _weight);   // 修改体重
	void change_age(int key, int _age);   // 修改年龄

private:
	map<int, Member> members;  // 利用map容器  int作为键值，Member作为关联

};

