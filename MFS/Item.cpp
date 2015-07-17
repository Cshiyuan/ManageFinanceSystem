#include "stdafx.h"
#include "Item.h"


Item::Item(const char* _name)
{
	sum = 0;  // 项目消费总金额为0
	top = 0;   // 项目消费条目为0
	nextnumber = 0;  // 下一层项目的数量为0
	note = 0;  // 设置删除标记
	strcpy_s(name, strlen(_name) + 1, _name);  // 初始化命名

	for (int i = 0; i < MAXc; i++)
		next[i] = NULL;   // 下一层的项目消费为空
	for (int i = 0; i < MAX; i++)
		for (int j = 0; j < 2; j++)
			member_money[i][j] = 0;   // 初始化项目消费条目
}
Item::Item()  // 默认构造函数
{

}
Item::~Item()
{

}
void Item::Addconsumption(int key, double money)
{
	
	if (top >= MAX)
	{
		cout << "条目输出已满。" << endl;
		return;
	}
	sum = sum + money;  // 消费总金额增加
	member_money[top][0] = key;  // 储存key
	member_money[top][1] = money;  // 储存money
	top;  // 条目数加一
	return;
}
void Item::Addnext(const char* _name)  // 向项目的下一层添加项目
{
	
	this -> next[nextnumber] = new Item(_name);
	this -> nextnumber++;
	return;
}
void Item::changename(const char* _name)  // 修改名字
{
	strcpy_s(name, strlen(_name) + 1, _name);
}
void Item::changemoney(double _money)   // 修改金额
{
	sum = _money;
}
void Item::delitem()  // 设置删除标记
{
	note = 1;
}
int Item::getnote()  // 获得删除标记
{
	return note;
}
int Item::getnextnumber()  // 返回下一层项目的数量
{
	return nextnumber;
}
char * Item::getname()  // 返回项目的名字
{
	return name;
}
