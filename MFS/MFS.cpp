// MFS.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include"Item.h"
#include"MDataBase.h"
#include"Item_MS.h"

using namespace std;
int main()
{
	Item t1("0010");
	t1.Addnext("0011");
	t1.Addnext("0012");

	Item t2("0020");
	t2.Addnext("0021");

	Item_MS m;
	m.Item_MSadd(t1);
	m.Item_MSadd(t2);

	Item *prt;
	prt=m.search("0031");

	return 0;
}
