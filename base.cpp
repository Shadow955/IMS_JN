#include<iostream>
#include<vector>
#include<string>
#include<stdlib.h>
#include"base.h"
using namespace std;

void Tencent::addFriend(int ID) {  //ͨ����Ӻ��Ѻ���
    for (int i = 0; i < friendList.size(); i++) {
        if (friendList[i] == ID) {
            cout << "\n" << ID << "�Ѿ������ĺ�����!" << endl;
            return;
        }
    }
    friendList.push_back(ID);
    cout << "\n������ӳɹ�!" << endl;
    return;
}

void Tencent::deleteFriend(int ID) {  //ͨ��ɾ�����Ѻ���
    int state = 0;  //״̬����
    for (int i = 0; i < friendList.size(); i++) {
        if (friendList[i] == ID) {
            char in;
            cout << ID << "ȷ��ɾ���ú�����?(y/n)" << endl;
            cin >> in;
            if (in == 'y') {  //����ȷ�ϣ�����yɾ��
                friendList.erase(friendList.begin() + i);
                cout << "\n����ɾ���ɹ�!" << endl;
            }
            else
                state = 1;
            break;
        }
    }
    if (state == 0)
        cout << "\nδ���ҵ����ˣ�" << endl;
    if (state == 1)
        cout << "\n������ȡ����" << endl;
}

void Tencent::showFriendList() {
    if (friendList.empty())
        cout << "\n��δ��Ӻ��ѣ�" << endl;
    else {
        cout << "�����б�";
        for (int i = 0; i < friendList.size(); i++)
            cout << "\n" << friendList[i] << endl;
    }
}

void QQ::showInfo() {  //QQ:չʾ��ǰ�˺���Ϣ����
    cout << "\nQQ�ʺ�:" << ID << endl;
    cout << "\n�ǳ�:" << nickname << endl;
    cout << "\n��������:" << birthDate << endl;
    cout << "\nQ��:" << age << endl;
    cout << "\nסַ:" << location << endl;
    if (!isHaveWebolg)
        cout << "δ��ͨ΢��" << endl;
    else
        cout << "�ѿ�ͨ��Ѷ΢��" << endl;
    if (!isHaveWechat)
        cout << "δ��΢��" << endl;
    else
        cout << "��΢��ID��" << weChatID << endl;
}

void QQ::showGroupList() {  //QQ:չʾ��ǰ�����Ⱥ�б�
    if (friendList.empty())
        cout << "\n��δ����QQȺ��" << endl;
    else {
        cout << "Ⱥ���б�";
        for (int i = 0; i < groupList.size(); i++)
            cout << "\n" << groupList[i] << endl;
    }
}

void QQ::enterGroup(const int groupID) {  //QQ:����һ��Ⱥ����
    for (int i = 0; i < groupList.size(); i++) {
        if (groupList[i] == groupID) {
            cout << "\n���Ѿ��ڴ�Ⱥ����!" << endl;
            return;
        }
    }
    if (groupID > 1006) {  //�ݶ����Ⱥ��1006
        cout << "��Ⱥ�Ų����ڣ�" << endl;
        return;
    }
    else {
        groupList.push_back(groupID);
        cout << "\n����Ⱥ�ɹ���" << endl;
        return;
    }
 }

void QQ::exitGroup(const int groupID) {  //QQ:�˳�һ��Ⱥ����
    bool flag = false;
    for (int i = 0; i < groupList.size(); i++) {
        if (groupList[i] == groupID) {
            groupList.erase(groupList.begin() + i);
            flag = true;
            cout << "\n�����ɹ�!���˳���Ⱥ!" << endl;
            break;
        }
    }
    if (!flag)
        cout << "\n����ʧ��!����δ�����Ⱥ!" << endl;
}

void Weblog::showInfo() {  //΢��:��ʾ��ǰ��Ϣ����
    cout << "\nQQ�ʺ�:" << ID << endl;
    cout << "\n�ǳ�:" << nickname << endl;
    cout << "\n��������:" << birthDate << endl;
    cout << "\n����:" << age << endl;
    cout << "\nסַ:" << location << endl;
}

void WeChat::showInfo() {  //΢��:��ʾ��ǰ��Ϣ����
    cout << "\n΢���ʺ�:" << ID << endl;
    cout << "\n�ǳ�:" << nickname << endl;
    cout << "\n��������:" << birthDate << endl;
    cout << "\n΢��:" << age << endl;
    cout << "\nסַ:" << location << endl;
    if (qqID != -1)
        cout << "\n��΢���˺Ź�����QQ��:" << qqID << endl;
    else
        cout << "\n��δ��QQ��" << endl;
}

void WeChat::showGroupList() {  //΢��:չʾ��ǰ�����Ⱥ�б�
    if (friendList.empty())
        cout << "\n��δ����QQȺ��" << endl;
    else {
        cout << "Ⱥ���б�";
        for (int i = 0; i < groupList.size(); i++)
            cout << "\n" << groupList[i] << endl;
    }
}

void WeChat::enterGroup(const int groupID) {  //΢��:����һ��Ⱥ����
    for (int i = 0; i < groupList.size(); i++) {
        if (groupList[i] == groupID) {
            cout << "\n���Ѿ��ڴ�Ⱥ����!" << endl;
            return;
        }
    }
    if (groupID > 1006) {  //�ݶ����Ⱥ��1006
        cout << "��Ⱥ�Ų����ڣ�" << endl;
        return;
    }
    else {
        groupList.push_back(groupID);
        cout << "\n����Ⱥ�ɹ���" << endl;
        return;
    }
}

void WeChat::exitGroup(const int groupID) {  //΢��:�˳�һ��Ⱥ����
    bool flag = false;
    for (int i = 0; i < groupList.size(); i++) {
        if (groupList[i] == groupID) {
            groupList.erase(groupList.begin() + i);
            flag = true;
            cout << "\n�����ɹ�!���˳���Ⱥ!" << endl;
            break;
        }
    }
    if (!flag)
        cout << "\n����ʧ��!����δ�����Ⱥ!" << endl;
}

template<typename T>
void Tencent::checkCommonFriend(T other) {
    vector<int> otherFriendList = other.getFriendList();
    int count = 0;
    cout << "\t\t\t\t��ͬ������:" << endl;
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
    cout << "\t\t\t\t��" << count << "λ��ͬ���ѡ�" << endl;
}