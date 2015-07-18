#pragma once
#include"Item.h"
#define MAXn 10  // 这个系统能够使用的最大项目的数量
class Item_MS
{
public:
	Item_MS();
	~Item_MS();
	void Item_MSadd(Item t);  // 添加项目

	//根据项目名字来修改
	void Item_Msdel(char *c);  // 删除项目
	void changemoney(char *c, double money);  // 修改项目的金额
	void changename(char *c, char *name);  // 修改项目的名字

	void show(int number);  // 输出项目数组中的信息，包括其下层项目

	Item * search(char *name);  // 根据项目的名字返回指向这个项目的指针
private:
	Item items[MAXn];  //项目数组
	int top;  // 记录项目的数量
};

