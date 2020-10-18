#pragma once
#include<string>
#include<vector>

using namespace std;

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
	Tencent() {  //无参构造函数
		ID = -1;
		age = -1;
		nickname = "匿名";
		birthDate = "暂无数据";
		location = "未知";
	}
	//以下是设定函数
	void setID(int in) {
		ID = in;
	}
	void setAge(int in) {
		age = in;
	}
	void setName(string in) {
		nickname = in;
	}
	void setBirthDate(string in) {
		birthDate = in;
	}
	void setLocation(string in) {
		location = in;
	}
	int getID() {
		return ID;
	}
	int getAge() {
		return age;
	}
	//以下是获取账号信息函数
	string getName() {
		return nickname;
	}
	string getBirthDate() {
		return birthDate;
	}
	string getLoation() {
		return location;
	}
	vector<int> getFriendList() {
		return friendList;
	}
	//以下是功能函数
	void addFriend(const int ID);  //添加好友

	void deleteFriend(const int ID);  //删除好友

	void showFriendList();  //显示好友列表
};

class QQ: public Tencent{  //QQ类，继承基础类，包含通用功能和独特功能

private:
	vector<int> groupList;  //群组列表，使用vector实现
	bool isHaveWebolg;  //状态：是否绑定了微博
	bool isHaveWechat;  //状态：是否绑定了微信
	int weChatID;  //绑定的微信号（仅当绑定了微信时）

public:
	QQ() {  //无参构造函数
		isHaveWebolg = false;
		isHaveWechat = false;
		weChatID = -1;
	}
	//以下是设定函数
	void linkToWebolg() {
		isHaveWebolg = true;
	}
	void linkToWechat(int wechatID) {
		isHaveWechat = true;
		weChatID = wechatID;
	}
	//以下是获取信息函数
	bool ifSetWebolg() {
		return isHaveWebolg;
	}
	bool ifSetWechat() {
		return isHaveWechat;
	}
	int getWechatID() {
		return weChatID;
	}
	vector<int> getGroupList() {
		return groupList;
	}
	void showInfo();  //显示当前QQ信息

	void showGroupList();  //显示群组列表

	void enterGroup(const int groupID);  //加入一个群

	void exitGroup(int groupID);  //退出一个群
};

class Weblog : public Tencent {

private:
	bool isHaveWebolg;

public:
	Weblog(QQ & qq) {  //含参构造函数，仅在开通了微博时执行
		ID = qq.getID();
		nickname = qq.getName();
		isHaveWebolg = true;  //是否开通了微博
	}
	Weblog(){}  //重载无参构造函数，默认执行此构造函数

	//以下是设定函数
	void setWeblogID(QQ & qq) {
		ID=qq.getID();
	}
	void setisHaveWeblog(bool is) {
		isHaveWebolg = is;
	}
	//以下是获取信息函数
	bool getIsHaveWeblog() {
		return isHaveWebolg;
	}
	void showInfo() { }  //显示当前微博信息
};

class WeChat : public Tencent {

private:
	int qqID;  //绑定的QQ账号（仅当绑定了QQ时）
	vector<int> groupList;  //群组列表，使用vector实现

public:
	WeChat(QQ& qq) {  //有参构造函数，仅当绑定了QQ时执行
		qqID = qq.getID();
	}

	WeChat() {  //无参构造函数，默认执行此构造函数
		qqID = -1;  //默认不绑定QQ账号
	}

	//以下是信息获取函数
	int getqqID() {
		return qqID;
	}

	vector<int> getGroupList() {
		return groupList;
	}

	void setqqID(int qq) {
		qqID = qq;
	}

	void showInfo();  //显示当前微信信息

	void showGroupList();  //显示群组列表

	void enterGroup(const int groupID);  //加入一个群

	void exitGroup(int groupID);  //退出一个群
};