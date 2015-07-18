#include "stdafx.h"
#include "Item_MS.h"
#include<fstream>

Item_MS::Item_MS()   // 构造函数，读入文件里面的信息
{
	Item t;
	Item *tnext;  // 作为下层项目写入的媒介
	fstream file;  // 读取文件
	top = 0;
	file.open("items.dat", ios::in | ios::binary);  // 打开文件 将二进制文件中的数据读出
	while (1)
	{
		file.read((char*)&t, sizeof(t));
		for (int i = 0; i < t.getnextnumber(); i++)
		{
			tnext = new Item;
			file.read((char*)tnext, sizeof(t));  // 将其读出
			t.next[i] = tnext;
		}
		if (!file) break;
		items[top] = t;
		top++;
	}
	file.close();
}

Item_MS::~Item_MS()   // 析构函数 将信息写入文件保存
{
	Item t;  // 作为第二层写入的中间媒介
	fstream file;
	file.open("items.dat", ios::out | ios::binary);
	for (int i = 0; i < top; i++)  // 进行第一层的写入
	{
		if (items[i].getnote() == 1) continue;  // 如果已经删除则不写入,继续下一轮
		else  // 否则写入
		{
			file.write((char*)&items[i], sizeof(t));  //将其写入
			// 将项目下层的项目写入
			for (int j = 0; j < items[i].getnextnumber(); j++)
			{
				file.write((char*)&(*items[i].next[j]), sizeof(t));  // 将其写入
			}
			
		}
	}
}

Item * Item_MS::search(char *c)  // 根据项目的名字返回指向这个项目的指针
{
	Item * prt;  // 定义对象指针，用作返回
	for (int i = 0; i < top; i++)  // 遍历项目管理系统的第一层
	{
		prt = &items[i];  // 指针指向管理系统中的管理项目  
	    if (!strcmp(c, prt->getname()))  // 如果项目的名字相同  /strcmp()如果相同则返回0
		return prt;  // 找到返回指向项目的指针
		// 找不到进行下一层遍历
		if (items[i].getnextnumber() != 0)// 如果项目的下层项目数不为零 
			for (int j = 0; j < items[i].getnextnumber(); j++)  // 进行下一级的遍历
			{
				prt = items[i].next[j];   // 指向下层第一个
				if (!strcmp(c, prt->getname()))   // 对下一层项目的名字进行判断  
				{
					return prt;  //找到返回指针
				}
			}
	}
	return NULL;  // 一直没找到就返回空指针
}

void Item_MS::Item_MSadd(Item t)  // 添加项目
{
	items[top] = t;
	top++;
}
void Item_MS::Item_Msdel(char * c)  // 删除项目  
{
	Item* ptr;
	ptr = search(c);
	ptr->delitem();
}
void Item_MS::changemoney(char *c, double money)  // 修改项目的金额
{
	Item* ptr;
	ptr = search(c);
	ptr->changemoney(money);
}
void Item_MS::changename(char *c, char *name)  // 修改项目的名字
{
	Item* ptr;
	ptr = search(c);
	ptr->changename(name);
}