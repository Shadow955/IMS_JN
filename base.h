#pragma once
#include<string>
#include<vector>
#define CLS system("cls")  //��������

using namespace std;

class Tencent;
class QQ;
class Weblog;
class WeChat;
class QQDatabase;
class WeblogDatabase;
class WeChatDatabase;

//�϶̺���ֱ�������ж��壬�ϳ�����ֻ�ڴ��������ڶ�Ӧcpp�ļ��ж���

class Tencent {  //���࣬�������������ͨ�ù���

protected:
	int ID;  
	int age;
	string nickname;
	string birthDate;
	string location;
	vector<int> friendList;  //�����б�ʹ��vectorʵ��

public:
	Tencent();  //�޲ι��캯��
	//�������趨����
	void setID(int in);

	void setAge(int in);

	void setName(string in);

	void setBirthDate(string in);

	void setLocation(string in);

	int getID();

	int getAge();

	//�����ǻ�ȡ�˺���Ϣ����
	string getName();

	string getBirthDate();

	string getLoation();

	vector<int> getFriendList();

	//�����ǹ��ܺ���
	void addFriend(const int ID);  //��Ӻ���

	void deleteFriend(const int ID);  //ɾ������

	void showFriendList();  //��ʾ�����б�

	template<typename T>
	void checkCommonFriend(T);
};

class QQ: public Tencent{  //QQ�࣬�̳л����࣬����ͨ�ù��ܺͶ��ع���

private:
	vector<int> groupList;  //Ⱥ���б�ʹ��vectorʵ��
	bool isHaveWebolg;  //״̬���Ƿ����΢��
	bool isHaveWechat;  //״̬���Ƿ����΢��
	int weChatID;  //�󶨵�΢�źţ���������΢��ʱ��

public:
	QQ();  //�޲ι��캯��

	//�������趨����
	void linkToWebolg();

	void linkToWechat(int wechatID);

	//�����ǻ�ȡ��Ϣ����
	bool ifSetWebolg();

	bool ifSetWechat();

	int getWechatID();

	vector<int> getGroupList();

	void showInfo();  //��ʾ��ǰQQ��Ϣ

	void showGroupList();  //��ʾȺ���б�

	void enterGroup(const int groupID);  //����һ��Ⱥ

	void exitGroup(int groupID);  //�˳�һ��Ⱥ
};

class Weblog : public Tencent {

private:
	bool isHaveWebolg;

public:
	Weblog(QQ  qq);  //���ι��캯�������ڿ�ͨ��΢��ʱִ��

	Weblog();  //�����޲ι��캯����Ĭ��ִ�д˹��캯��

	//�������趨����
	void setWeblogID(QQ  qq);

	void setisHaveWeblog(bool is);

	//�����ǻ�ȡ��Ϣ����
	bool getIsHaveWeblog();

	void showInfo();  //��ʾ��ǰ΢����Ϣ
};

class WeChat : public Tencent {

private:
	int qqID;  //�󶨵�QQ�˺ţ���������QQʱ��
	vector<int> groupList;  //Ⱥ���б�ʹ��vectorʵ��

public:
	WeChat(QQ qq);  //�вι��캯������������QQʱִ��

	WeChat();  //�޲ι��캯����Ĭ��ִ�д˹��캯��

	//��������Ϣ��ȡ����
	int getqqID();

	vector<int> getGroupList();

	void setqqID(int qq);

	void showInfo();  //��ʾ��ǰ΢����Ϣ

	void showGroupList();  //��ʾȺ���б�

	void enterGroup(const int groupID);  //����һ��Ⱥ

	void exitGroup(int groupID);  //�˳�һ��Ⱥ
};


int mainUI();
	

template<typename T>
int stdlogin(T database);  //����ʹ��ģ�庯��ʵ�ֶ�ƽ̨��¼


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

	void signup(WeblogDatabase, WeChatDatabase);  //ע���˺ź���

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
	Group();

	void setGroupNum(int number);

	int getGroupNum();

	vector<int> getMemberList();

	void showInfo();

	template<typename T>
	void addMember(T D, int num);  //ʹ��ģ�庯��ʵ��QQ��΢��Ⱥ����ӳ�Ա����

	void deleteMember(int num);

};

class GroupData {

public:

	vector<Group> database;  //������ģ��Ⱥ�����ݿ�

	void createNewGroup();

	void setNewGroup(int number);  //ʹ�����ݳ�ʼ���趨��Ⱥ

	void showAllGroup();  //��ʾĿǰ����Ⱥ��
};