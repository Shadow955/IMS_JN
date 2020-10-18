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

	void signup(WeblogDatabase& BD, WeChatDatabase& WCD) {}  //注册账号函数

	void login();  //登录函数

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


template<class T>
void stdlogin(T& database);