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

	int QQmain();  //QQ������

	int QQservice(WeblogDatabase, WeChatDatabase);  //QQ���ܺ���

	int QQclient(int ID, WeblogDatabase& BD, WeChatDatabase& WD);

	//int QQclient(int,WeblogDatabase,WeChatDatabase);

	int QQUI();

	void signup(WeblogDatabase , WeChatDatabase);  //ע���˺ź���

	int login();  //��¼����

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


//template<typename T>
//void stdlogin(T database);  //����ʹ�ú���ģ��ʵ�ֶ�ƽ̨�ĵ�¼


class Group {

private:
	int groupNum;
	vector<int> memberList;

public:
	Group() {
		groupNum = -1;  //Լ��Ⱥ��Ĭ�ϳ�ʼֵΪ-1
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
	void addMember(T &D,int num);  //ʹ��ģ�庯��ʵ��QQ��΢��Ⱥ����ӳ�Ա����

	void deleteMember(int num);

};

class GroupData {

public:

	vector<Group> database;  //������ģ��Ⱥ�����ݿ�

	void createNewGroup();

	void setNewGroup(int number) {  //ʹ�����ݳ�ʼ���趨��Ⱥ
		Group newGroup;
		newGroup.setGroupNum(number);
		database.push_back(newGroup);
	}

	void showAllGroup() {  //��ʾĿǰ����Ⱥ��
		system("cls");
		for (int i = 0; i < database.size(); i++)
			cout << database[i].getGroupNum() << endl;
	}
};