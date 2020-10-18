#pragma once
#include<string>
#include<vector>

using namespace std;

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
	Tencent() {  //�޲ι��캯��
		ID = -1;
		age = -1;
		nickname = "����";
		birthDate = "��������";
		location = "δ֪";
	}
	//�������趨����
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
	//�����ǻ�ȡ�˺���Ϣ����
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
	//�����ǹ��ܺ���
	void addFriend(const int ID);  //��Ӻ���

	void deleteFriend(const int ID);  //ɾ������

	void showFriendList();  //��ʾ�����б�
};

class QQ: public Tencent{  //QQ�࣬�̳л����࣬����ͨ�ù��ܺͶ��ع���

private:
	vector<int> groupList;  //Ⱥ���б�ʹ��vectorʵ��
	bool isHaveWebolg;  //״̬���Ƿ����΢��
	bool isHaveWechat;  //״̬���Ƿ����΢��
	int weChatID;  //�󶨵�΢�źţ���������΢��ʱ��

public:
	QQ() {  //�޲ι��캯��
		isHaveWebolg = false;
		isHaveWechat = false;
		weChatID = -1;
	}
	//�������趨����
	void linkToWebolg() {
		isHaveWebolg = true;
	}
	void linkToWechat(int wechatID) {
		isHaveWechat = true;
		weChatID = wechatID;
	}
	//�����ǻ�ȡ��Ϣ����
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
	void showInfo();  //��ʾ��ǰQQ��Ϣ

	void showGroupList();  //��ʾȺ���б�

	void enterGroup(const int groupID);  //����һ��Ⱥ

	void exitGroup(int groupID);  //�˳�һ��Ⱥ
};

class Weblog : public Tencent {

private:
	bool isHaveWebolg;

public:
	Weblog(QQ & qq) {  //���ι��캯�������ڿ�ͨ��΢��ʱִ��
		ID = qq.getID();
		nickname = qq.getName();
		isHaveWebolg = true;  //�Ƿ�ͨ��΢��
	}
	Weblog(){}  //�����޲ι��캯����Ĭ��ִ�д˹��캯��

	//�������趨����
	void setWeblogID(QQ & qq) {
		ID=qq.getID();
	}
	void setisHaveWeblog(bool is) {
		isHaveWebolg = is;
	}
	//�����ǻ�ȡ��Ϣ����
	bool getIsHaveWeblog() {
		return isHaveWebolg;
	}
	void showInfo() { }  //��ʾ��ǰ΢����Ϣ
};

class WeChat : public Tencent {

private:
	int qqID;  //�󶨵�QQ�˺ţ���������QQʱ��
	vector<int> groupList;  //Ⱥ���б�ʹ��vectorʵ��

public:
	WeChat(QQ& qq) {  //�вι��캯������������QQʱִ��
		qqID = qq.getID();
	}

	WeChat() {  //�޲ι��캯����Ĭ��ִ�д˹��캯��
		qqID = -1;  //Ĭ�ϲ���QQ�˺�
	}

	//��������Ϣ��ȡ����
	int getqqID() {
		return qqID;
	}

	vector<int> getGroupList() {
		return groupList;
	}

	void setqqID(int qq) {
		qqID = qq;
	}

	void showInfo();  //��ʾ��ǰ΢����Ϣ

	void showGroupList();  //��ʾȺ���б�

	void enterGroup(const int groupID);  //����һ��Ⱥ

	void exitGroup(int groupID);  //�˳�һ��Ⱥ
};