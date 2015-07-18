#pragma once
#define MAX 10  // 宏定义项目的消费条目 // 编译前预处理器会用宏值替换宏名
#define MAXc 5  // 定义下一层收支项目的最大数目
#include<iostream>
using namespace std;
class Item
{
public:
	 Item(const char *name);  // 构造函数
	 Item();  // 默认构造函数
	~Item();
	//Item(Item & _t);  // 拷贝构造函数

	void Addconsumption(int key, double money);  // 根据key，添加成员在项目的消费
	void Addnext(const char *name);  // 增加下一层的项目

	void changename(const char *name);  // 修改项目的名字
	void changemoney(const double money);  // 修改项目的金额

	void delitem();  // 删除项目  // 也就是将note置为1

	int getnote();  // 获得删除标记
	int getnextnumber();  // 获得项目下层的项目数

	char *getname();  // 获得项目的名字
	double getmoney();  // 获得金额

    Item *next[MAXc];   // 下一层的收支项目，没有下一层则为NULL  //对应的为nextnumber
	                    // 指针数组

	
private:
	
	char name[50];   // 项目名字
	double sum;  // 此项目消费总金额
	double member_money[MAX][2];  // 支出  [i][0]表示key，[i][1]表示消费了多少钱  //对应的为top

	// 下面的数据成员为指示用的数据
	int top;   // 总共有多少个项目条目
	int nextnumber;  // 表明下一层的数目

	int note;  // 删除标记
};

