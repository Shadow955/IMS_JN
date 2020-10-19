#pragma once
#include<iostream>
#include<vector>
#include<string>
#include<stdlib.h>
#include"base.h"

using namespace std;

//尝试使用模板类，实验是否能成功实例化
template<class T>
class Database {

public:
	vector<T> database;  //构建一个模拟数据库，储存所有三平台账号
};

class QQDatabase {

public:

	vector<QQ> database;  //构建一个模拟数据库，储存所有QQ号

	int QQmain();  //QQ主界面

	int QQservice(WeblogDatabase, WeChatDatabase);  //QQ功能函数

	int QQclient(int ID, WeblogDatabase& BD, WeChatDatabase& WD);

	//int QQclient(int,WeblogDatabase,WeChatDatabase);

	int QQUI();

	void signup(WeblogDatabase , WeChatDatabase);  //注册账号函数

	int login();  //登录函数

	void setup(int ID, string nickname, string birthDate, int age,
		string location, bool blog, int weChatID, WeblogDatabase blogD); //初始化一个新账号（用于注册时）
};

class WeblogDatabase {

public:

	vector<Weblog> database;  //构建一个模拟数据库，储存所有微博号

	void signup();  //注册账号函数

	void login();  //登录函数

	void setup(int ID, string nickname, string birthDate, int age, string location); //初始化一个新账号（用于注册时）
};

class WeChatDatabase {

public:

	vector<WeChat> database;  //构建一个模拟数据库，储存所有微信号

	void signup(QQDatabase& QQD);  //注册账号函数

	void login();  //登录函数

	void setup(int ID, string nickname, string birthDate, int age, string location, int qqID); //初始化一个新账号（用于注册时）
};


//template<typename T>
//void stdlogin(T database);  //尝试使用函数模板实现多平台的登录


class Group {

private:
	int groupNum;
	vector<int> memberList;

public:
	Group() {
		groupNum = -1;  //约定群号默认初始值为-1
	}

	void setGroupNum(int number) {
		groupNum = number;
	}

	int getGroupNum() {
		return groupNum;
	}

	vector<int> getMemberList() {
		return memberList;
	}

	void showInfo();

	template<typename T>
	void addMember(T &D,int num);  //使用模板函数实现QQ或微信群的添加成员功能

	void deleteMember(int num);

};

class GroupData {

public:

	vector<Group> database;  //用向量模拟群组数据库

	void createNewGroup();

	void setNewGroup(int number) {  //使用数据初始化设定新群
		Group newGroup;
		newGroup.setGroupNum(number);
		database.push_back(newGroup);
	}

	void showAllGroup() {  //显示目前所有群组
		system("cls");
		for (int i = 0; i < database.size(); i++)
			cout << database[i].getGroupNum() << endl;
	}
};