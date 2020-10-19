#pragma once
#include<iostream>
#include<vector>
#include<string>
#include<stdlib.h>
#define CLS system("cls")

using namespace std;

class QQ;
class WeChat;
class Weblog;

int mainUI() {
	CLS;      //清屏函数
	int choose = 0;

	cout << "\n\n\n\t\t------------多重账号综合管理系统-----------" << endl;
	cout << "\n\t\t\t\t1:<QQ账号管理>" << endl;
	cout << "\n\t\t\t\t2:<微博账号管理>" << endl;
	cout << "\n\t\t\t\t3:<微信账号管理>" << endl;
	cout << "\n\t\t\t\t4:<QQ群成员管理>" << endl;
	cout << "\n\t\t\t\t0:<退出系统>" << endl;
	cout << "\n\t\t注:仅上述出现的纯数字输入有效！其他输入均为非法输入！\n\n" << endl;
	cout << "\t\t\t请输入您的选择：";
	cin >> choose;
	if (choose >= 0 && choose <= 4) {
		CLS;
		return choose;
	}
	else {
		CLS;
		cout << "\n\t\t警告:您的输入有误！请重新输入！\n" << endl;
		mainUI();
	}
}

template<typename T>
int stdlogin(T database) {  //尝试使用模板函数实现多平台登录
	CLS;
	bool flag = true;
	int account, i;
	while (flag) {
		cout << "\n请输入账号：" << endl;
		cin >> account;
		for (i = 0; i < database.size(); i++) {
			if (account == database[i].getID()) {
				CLS;
				cout << "\n账号登录成功！欢迎用户" << account << endl;
				flag = false;
				break;
			}
		}
		cout << "\n账号不存在！请检查后重新输入！" << endl;
	}
	return account;
}

//尝试使用模板类，实验是否能成功实例化
//template<class T>
//class Database {
//
//public:
//	vector<T> database;  //构建一个模拟数据库，储存所有三平台账号
//};

class QQDatabase {

public:

	vector<QQ> database;  //构建一个模拟数据库，储存所有QQ号

	int QQmain();  //QQ主界面

	int QQservice(WeblogDatabase, WeChatDatabase);  //QQ功能函数

	int QQclient(int ID, WeblogDatabase BD, WeChatDatabase WD);

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

	int weblogUI();

	int weblogService();

	int weblogmain();

	int weblogClient(int);

	void signup();  //注册账号函数

	void login();  //登录函数

	void setup(int ID, string nickname, string birthDate, int age, string location); //初始化一个新账号（用于注册时）
};

class WeChatDatabase {

public:

	vector<WeChat> database;  //构建一个模拟数据库，储存所有微信号

	void signup(QQDatabase QQD);  //注册账号函数

	void login();  //登录函数

	int wechatmain();

	int wechatService(QQDatabase QD);

	int wechatUI();

	int wechatClient(int ID);

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
	void addMember(T D,int num);  //使用模板函数实现QQ或微信群的添加成员功能

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
		CLS;
		for (int i = 0; i < database.size(); i++)
			cout << database[i].getGroupNum() << endl;
	}
};