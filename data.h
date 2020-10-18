#pragma once
#include<iostream>
#include<vector>
#include<string>
#include<stdlib.h>
#include"base.h"

using namespace std;

//����ʹ��ģ���࣬ʵ���Ƿ��ܳɹ�ʵ����
template<class T>
class Database {

public:
	vector<T> database;  //����һ��ģ�����ݿ⣬����������ƽ̨�˺�
};

class QQDatabase {

public:

	vector<QQ> database;  //����һ��ģ�����ݿ⣬��������QQ��

	void signup(WeblogDatabase& BD, WeChatDatabase& WCD) {}  //ע���˺ź���

	void login();  //��¼����

	void setup(int ID, string nickname, string birthDate, int age,
		string location, bool blog, int weChatID, WeblogDatabase blogD); //��ʼ��һ�����˺ţ�����ע��ʱ��
};

class WeblogDatabase {

public:

	vector<Weblog> database;  //����һ��ģ�����ݿ⣬��������΢����

	void signup();  //ע���˺ź���

	void login();  //��¼����

	void setup(int ID, string nickname, string birthDate, int age, string location); //��ʼ��һ�����˺ţ�����ע��ʱ��
};

class WeChatDatabase {

public:

	vector<WeChat> database;  //����һ��ģ�����ݿ⣬��������΢�ź�

	void signup(QQDatabase& QQD);  //ע���˺ź���

	void login();  //��¼����

	void setup(int ID, string nickname, string birthDate, int age, string location, int qqID); //��ʼ��һ�����˺ţ�����ע��ʱ��
};


template<class T>
void stdlogin(T& database);