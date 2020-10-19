#include<iostream>
#include<vector>
#include<string>
#include<stdlib.h>
#include"base.h"
using namespace std;

void Tencent::addFriend(int ID) {  //通用添加好友函数
    for (int i = 0; i < friendList.size(); i++) {
        if (friendList[i] == ID) {
            cout << "\n" << ID << "已经是您的好友了!" << endl;
            return;
        }
    }
    friendList.push_back(ID);
    cout << "\n好友添加成功!" << endl;
    return;
}

void Tencent::deleteFriend(int ID) {  //通用删除好友函数
    int state = 0;  //状态代码
    for (int i = 0; i < friendList.size(); i++) {
        if (friendList[i] == ID) {
            char in;
            cout << ID << "确定删除该好友吗?(y/n)" << endl;
            cin >> in;
            if (in == 'y') {  //二次确认，输入y删除
                friendList.erase(friendList.begin() + i);
                cout << "\n好友删除成功!" << endl;
            }
            else
                state = 1;
            break;
        }
    }
    if (state == 0)
        cout << "\n未查找到此人！" << endl;
    if (state == 1)
        cout << "\n操作已取消！" << endl;
}

void Tencent::showFriendList() {
    if (friendList.empty())
        cout << "\n暂未添加好友！" << endl;
    else {
        cout << "好友列表";
        for (int i = 0; i < friendList.size(); i++)
            cout << "\n" << friendList[i] << endl;
    }
}

void QQ::showInfo() {  //QQ:展示当前账号信息函数
    cout << "\nQQ帐号:" << ID << endl;
    cout << "\n昵称:" << nickname << endl;
    cout << "\n出生日期:" << birthDate << endl;
    cout << "\nQ龄:" << age << endl;
    cout << "\n住址:" << location << endl;
    if (!isHaveWebolg)
        cout << "未开通微博" << endl;
    else
        cout << "已开通腾讯微博" << endl;
    if (!isHaveWechat)
        cout << "未绑定微信" << endl;
    else
        cout << "绑定微信ID：" << weChatID << endl;
}

void QQ::showGroupList() {  //QQ:展示当前加入的群列表
    if (friendList.empty())
        cout << "\n暂未加入QQ群！" << endl;
    else {
        cout << "群组列表";
        for (int i = 0; i < groupList.size(); i++)
            cout << "\n" << groupList[i] << endl;
    }
}

void QQ::enterGroup(const int groupID) {  //QQ:加入一个群函数
    for (int i = 0; i < groupList.size(); i++) {
        if (groupList[i] == groupID) {
            cout << "\n您已经在此群中了!" << endl;
            return;
        }
    }
    if (groupID > 1006) {  //暂定最大群号1006
        cout << "该群号不存在！" << endl;
        return;
    }
    else {
        groupList.push_back(groupID);
        cout << "\n加入群成功！" << endl;
        return;
    }
 }

void QQ::exitGroup(const int groupID) {  //QQ:退出一个群函数
    bool flag = false;
    for (int i = 0; i < groupList.size(); i++) {
        if (groupList[i] == groupID) {
            groupList.erase(groupList.begin() + i);
            flag = true;
            cout << "\n操作成功!已退出该群!" << endl;
            break;
        }
    }
    if (!flag)
        cout << "\n操作失败!您还未进入该群!" << endl;
}

void Weblog::showInfo() {  //微博:显示当前信息函数
    cout << "\nQQ帐号:" << ID << endl;
    cout << "\n昵称:" << nickname << endl;
    cout << "\n出生日期:" << birthDate << endl;
    cout << "\n博龄:" << age << endl;
    cout << "\n住址:" << location << endl;
}

void WeChat::showInfo() {  //微信:显示当前信息函数
    cout << "\n微信帐号:" << ID << endl;
    cout << "\n昵称:" << nickname << endl;
    cout << "\n出生日期:" << birthDate << endl;
    cout << "\n微龄:" << age << endl;
    cout << "\n住址:" << location << endl;
    if (qqID != -1)
        cout << "\n此微信账号关联的QQ号:" << qqID << endl;
    else
        cout << "\n暂未绑定QQ号" << endl;
}

void WeChat::showGroupList() {  //微信:展示当前加入的群列表
    if (friendList.empty())
        cout << "\n暂未加入QQ群！" << endl;
    else {
        cout << "群组列表";
        for (int i = 0; i < groupList.size(); i++)
            cout << "\n" << groupList[i] << endl;
    }
}

void WeChat::enterGroup(const int groupID) {  //微信:加入一个群函数
    for (int i = 0; i < groupList.size(); i++) {
        if (groupList[i] == groupID) {
            cout << "\n您已经在此群中了!" << endl;
            return;
        }
    }
    if (groupID > 1006) {  //暂定最大群号1006
        cout << "该群号不存在！" << endl;
        return;
    }
    else {
        groupList.push_back(groupID);
        cout << "\n加入群成功！" << endl;
        return;
    }
}

void WeChat::exitGroup(const int groupID) {  //微信:退出一个群函数
    bool flag = false;
    for (int i = 0; i < groupList.size(); i++) {
        if (groupList[i] == groupID) {
            groupList.erase(groupList.begin() + i);
            flag = true;
            cout << "\n操作成功!已退出该群!" << endl;
            break;
        }
    }
    if (!flag)
        cout << "\n操作失败!您还未进入该群!" << endl;
}

template<typename T>
void Tencent::checkCommonFriend(T other) {
    vector<int> otherFriendList = other.getFriendList();
    int count = 0;
    cout << "\t\t\t\t共同好友有:" << endl;
    for (int i = 0; i < friendList.size(); i++) {
        int one = friendList[i];
        for (int j = 0; j < otherFriendList.size(); j++) {
            if (otherFriendList[j] == one) {
                cout << "\t\t\t\t" << one << endl;
                count++;
                break;
            }
        }
    }
    cout << "\t\t\t\t共" << count << "位共同好友。" << endl;
}