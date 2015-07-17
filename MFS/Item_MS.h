#pragma once
#include"Item.h"
#define MAXn 10  // 这个系统能够使用的最大项目的数量
class Item_MS
{
public:
	Item_MS();
	~Item_MS();
	void Item_MSadd(Item t);  // 添加项目
	void Item_Msdel(int num);  // 删除项目

	Item * search(char *name);  // 根据项目的名字返回指向这个项目的指针
private:
	Item items[MAXn];  //项目数组
	int top;  // 记录项目的数量
};

