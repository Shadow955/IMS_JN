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
	CLS;      //��������
	int choose = 0;

	cout << "\n\n\n\t\t------------�����˺��ۺϹ���ϵͳ-----------" << endl;
	cout << "\n\t\t\t\t1:<QQ�˺Ź���>" << endl;
	cout << "\n\t\t\t\t2:<΢���˺Ź���>" << endl;
	cout << "\n\t\t\t\t3:<΢���˺Ź���>" << endl;
	cout << "\n\t\t\t\t4:<QQȺ��Ա����>" << endl;
	cout << "\n\t\t\t\t0:<�˳�ϵͳ>" << endl;
	cout << "\n\t\tע:���������ֵĴ�����������Ч�����������Ϊ�Ƿ����룡\n\n" << endl;
	cout << "\t\t\t����������ѡ��";
	cin >> choose;
	if (choose >= 0 && choose <= 4) {
		CLS;
		return choose;
	}
	else {
		CLS;
		cout << "\n\t\t����:���������������������룡\n" << endl;
		mainUI();
	}
}

template<typename T>
int stdlogin(T database) {  //����ʹ��ģ�庯��ʵ�ֶ�ƽ̨��¼
	CLS;
	bool flag = true;
	int account, i;
	while (flag) {
		cout << "\n�������˺ţ�" << endl;
		cin >> account;
		for (i = 0; i < database.size(); i++) {
			if (account == database[i].getID()) {
				CLS;
				cout << "\n�˺ŵ�¼�ɹ�����ӭ�û�" << account << endl;
				flag = false;
				break;
			}
		}
		cout << "\n�˺Ų����ڣ�������������룡" << endl;
	}
	return account;
}

//����ʹ��ģ���࣬ʵ���Ƿ��ܳɹ�ʵ����
//template<class T>
//class Database {
//
//public:
//	vector<T> database;  //����һ��ģ�����ݿ⣬����������ƽ̨�˺�
//};

class QQDatabase {

public:

	vector<QQ> database;  //����һ��ģ�����ݿ⣬��������QQ��

	int QQmain();  //QQ������

	int QQservice(WeblogDatabase, WeChatDatabase);  //QQ���ܺ���

	int QQclient(int ID, WeblogDatabase BD, WeChatDatabase WD);

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

	int weblogUI();

	int weblogService();

	int weblogmain();

	int weblogClient(int);

	void signup();  //ע���˺ź���

	void login();  //��¼����

	void setup(int ID, string nickname, string birthDate, int age, string location); //��ʼ��һ�����˺ţ�����ע��ʱ��
};

class WeChatDatabase {

public:

	vector<WeChat> database;  //����һ��ģ�����ݿ⣬��������΢�ź�

	void signup(QQDatabase QQD);  //ע���˺ź���

	void login();  //��¼����

	int wechatmain();

	int wechatService(QQDatabase QD);

	int wechatUI();

	int wechatClient(int ID);

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
	void addMember(T D,int num);  //ʹ��ģ�庯��ʵ��QQ��΢��Ⱥ����ӳ�Ա����

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
		CLS;
		for (int i = 0; i < database.size(); i++)
			cout << database[i].getGroupNum() << endl;
	}
};