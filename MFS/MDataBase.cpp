#include "stdafx.h"
#include "MDataBase.h"
#include<fstream>  // 对文件进行读写
//#include <cstring>
MDataBase::MDataBase()
{
	Member m;
	fstream file;  // 读取文件
	file.open("members.dat", ios::in | ios::binary);  // 打开文件 将二进制文件中的数据读出
	int key;
	while (1)
	{
		file.read((char*)&key, sizeof(int)*2);  // 居然凭直觉后移了个两倍居然就可以了。。具体原因到时候追究。
		file.read((char*)&m, sizeof(m));
		if (!file) break;
		members.insert(map<int, Member>::value_type(key, m));
	}
	file.close();
}
MDataBase::~MDataBase()
{
	fstream file;
	file.open("members.dat", ios::out | ios::binary);
	map<int, Member>::iterator  it;
	int key;
	for (it = members.begin(); it != members.end(); ++it)
  {
		key = it->first;
		file.write((char*)&key, sizeof(int)*2);
		file.write((char*)&members[it->first], sizeof(members[it->first]));  
  }
	file.close();
}
void MDataBase::addmember(int key, char* _name, char* _sex, Bdata _Bdate, int _age, double _height, double _weight)  // 添加成员
{  
	members.insert(map<int, Member> ::value_type(key, Member(_name, _sex, _Bdate, _age, _height, _weight)));
}
void MDataBase::delmember(int key)  // 删除成员
{
	map<int, Member>::iterator it;
	it = members.find(key);       // 获得指向key的迭代子
	if (it == members.end())
	{
        cout << "没有找到" << endl;
		return ;
	}
	else
	{
        members.erase(it);  
		return;
	}
}
void MDataBase::memberlist()  // 遍历map容器，输出member类
{
	map<int, Member>::iterator it = members.begin();
	for (; it != members.end(); ++it)
	{
		cout << it->first << "  " << endl;
		cout << it->second << endl;  // 此处重载了插入运算符
	}

}
void MDataBase::change_name(int key, char*_name)  // 根据key值修改成员名字
{
	map<int, Member>::iterator it;
	it = members.find(key);
	it->second.changename(_name);
}
void MDataBase::change_sex(int key, char* _sex)  // 根据key值修改成员性别
{
	map<int, Member>::iterator it;
	it = members.find(key);
	it->second.changename(_sex);
}
void MDataBase::change_Bdata(int key, Bdata _Bate)  // 根据key值修改成员的生日
{
	map<int, Member>::iterator it;
	it = members.find(key);
	it->second.changeBdate(_Bate);
}
void MDataBase::change_weight(int key, double weight)  // 根据key值修改成员的体重
{
	map<int, Member>::iterator it;
	it = members.find(key);
	it->second.changeweight(weight);
}
void MDataBase::change_height(int key, double height)  // 根据key值修改成员的身高
{
	map<int, Member>::iterator it;
	it = members.find(key);
	it->second.changeheight(height);
}  
void MDataBase::change_age(int key, int age)  // 根据key值修改成员的年龄
{
	map<int, Member>::iterator it;
	it = members.find(key);
	it->second.changeage(age);
}