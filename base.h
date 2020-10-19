#pragma once
#include<string>
#include<vector>
#define CLS system("cls")  //清屏函数

using namespace std;

class Tencent;
class QQ;
class Weblog;
class WeChat;
class QQDatabase;
class WeblogDatabase;
class WeChatDatabase;

//较短函数直接在类中定义，较长函数只在此声明，在对应cpp文件中定义

class Tencent {  //基类，包含三款软件的通用功能

protected:
	int ID;  
	int age;
	string nickname;
	string birthDate;
	string location;
	vector<int> friendList;  //好友列表，使用vector实现

public:
	Tencent();  //无参构造函数
	//以下是设定函数
	void setID(int in);

	void setAge(int in);

	void setName(string in);

	void setBirthDate(string in);

	void setLocation(string in);

	int getID();

	int getAge();

	//以下是获取账号信息函数
	string getName();

	string getBirthDate();

	string getLoation();

	vector<int> getFriendList();

	//以下是功能函数
	void addFriend(const int ID);  //添加好友

	void deleteFriend(const int ID);  //删除好友

	void showFriendList();  //显示好友列表

	template<typename T>
	void checkCommonFriend(T);
};

class QQ: public Tencent{  //QQ类，继承基础类，包含通用功能和独特功能

private:
	vector<int> groupList;  //群组列表，使用vector实现
	bool isHaveWebolg;  //状态：是否绑定了微博
	bool isHaveWechat;  //状态：是否绑定了微信
	int weChatID;  //绑定的微信号（仅当绑定了微信时）

public:
	QQ();  //无参构造函数

	//以下是设定函数
	void linkToWebolg();

	void linkToWechat(int wechatID);

	//以下是获取信息函数
	bool ifSetWebolg();

	bool ifSetWechat();

	int getWechatID();

	vector<int> getGroupList();

	void showInfo();  //显示当前QQ信息

	void showGroupList();  //显示群组列表

	void enterGroup(const int groupID);  //加入一个群

	void exitGroup(int groupID);  //退出一个群
};

class Weblog : public Tencent {

private:
	bool isHaveWebolg;

public:
	Weblog(QQ  qq);  //含参构造函数，仅在开通了微博时执行

	Weblog();  //重载无参构造函数，默认执行此构造函数

	//以下是设定函数
	void setWeblogID(QQ  qq);

	void setisHaveWeblog(bool is);

	//以下是获取信息函数
	bool getIsHaveWeblog();

	void showInfo();  //显示当前微博信息
};

class WeChat : public Tencent {

private:
	int qqID;  //绑定的QQ账号（仅当绑定了QQ时）
	vector<int> groupList;  //群组列表，使用vector实现

public:
	WeChat(QQ qq);  //有参构造函数，仅当绑定了QQ时执行

	WeChat();  //无参构造函数，默认执行此构造函数

	//以下是信息获取函数
	int getqqID();

	vector<int> getGroupList();

	void setqqID(int qq);

	void showInfo();  //显示当前微信信息

	void showGroupList();  //显示群组列表

	void enterGroup(const int groupID);  //加入一个群

	void exitGroup(int groupID);  //退出一个群
};


int mainUI();
	

template<typename T>
int stdlogin(T database);  //尝试使用模板函数实现多平台登录


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

	void signup(WeblogDatabase, WeChatDatabase);  //注册账号函数

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
	Group();

	void setGroupNum(int number);

	int getGroupNum();

	vector<int> getMemberList();

	void showInfo();

	template<typename T>
	void addMember(T D, int num);  //使用模板函数实现QQ或微信群的添加成员功能

	void deleteMember(int num);

};

class GroupData {

public:

	vector<Group> database;  //用向量模拟群组数据库

	void createNewGroup();

	void setNewGroup(int number);  //使用数据初始化设定新群

	void showAllGroup();  //显示目前所有群组
};