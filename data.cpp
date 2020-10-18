#include<iostream>
#include<vector>
#include<string>
#include<stdlib.h>
#include"base.h"
#include"data.h"
#define CLS system("cls")  //��������

using namespace std;

void QQDatabase::signup(WeblogDatabase &BD,WeChatDatabase &WCD) {  //ע����QQ�ź���

    bool flag = false;
    //vector<QQ>::iterator end;
    int newID;
    string newName;
    string newBirthDate;
    int newAge;
    string newLocation;
    bool isHaveWeibo;
    int weChatID;

    CLS;
    //auto pd = database.end();
    //newID = *pd.getID();
    //�˴�����ʹ�õ�������ȡ���һ�������˺ŵ�ID�����δ�ܳɹ�ʵ��
    //��ʹ���ֶ������˺�ע��
    while (!flag) {
        flag = true;
        cout << "\n��������ϲ�����˺ţ������֣�����" << endl;
        cin >> newID;
        for (int i = 0; i < database.size(); i++) {
            if (database[i].getID() == newID) {
                cout << "\n�˺��ѱ�ע���ˣ����������룡" << endl;
                flag = false;
            }
        }
    }

    cout << "\n�������ǳƣ�" << endl;
    cin >> newName;
    cout << "\n�������������գ�" << endl;
    cin >> newBirthDate;
    cout << "\n����������Q�䣺" << endl;
    cin >> newAge;
    cout << "\n�������������ڵأ�" << endl;
    cin >> newLocation;
    cout << "\n�Ƿ���Ҫͬʱ��ͨ΢����y/n" << endl;
    char choose;
    cin >> choose;
    if (choose == 'y')
        isHaveWeibo = true;
    else
        isHaveWeibo = false;

    cout << "\n�Ƿ���Ҫ��΢�ţ�y/n" << endl;
    char choose;
    cin >> choose;
    if (choose == 'y') {
        bool flag2 = false;
        while (!flag2) {
            cout << "\n����������΢�źţ�" << endl;
            cin >> weChatID;
            int i;
            for (i = 0; i < WCD.database.size(); i++) {
                if (weChatID == WCD.database[i].getID()) {
                    flag2 = true;
                    break;
                }
            }
            if (!flag2)
                cout << "\n��΢�źŲ����ڣ����������룡" << endl;
        }
    }
    else
        weChatID = -1;

    CLS;
    cout << "\n�˺�" << newID << "ע��ɹ���" << endl;
    setup(newID, newName, newBirthDate, newAge, newLocation
        , isHaveWeibo, weChatID, BD);
}

void QQDatabase::setup(int ID, string nickname, string birthDate, int age,
    string location, bool blog, int weChatID, WeblogDatabase blogD) {

    QQ newAccount;  //����һ����QQ�������������Ϣ��ʼ��

    newAccount.setID(ID);
    newAccount.setName(nickname);
    newAccount.setBirthDate(birthDate);
    newAccount.setAge(age);
    newAccount.setLocation(location);
    newAccount.linkToWechat(weChatID);

    if (blog) {
        newAccount.linkToWebolg();
        Weblog newblog;
        newblog.setWeblogID(newAccount);
        newblog.setName(nickname);
        newblog.setBirthDate(birthDate);
        newblog.setAge(age);
        newblog.setLocation(location);
        newblog.setisHaveWeblog(true);
        blogD.database.push_back(newblog);
    }
    database.push_back(newAccount);
}

void QQDatabase::login() {
    //CLS;
    //bool flag = true;
    //while (flag) {
    //    cout << "\n������QQ�˺ţ�";
    //    int account, i;
    //    cin >> account;
    //    for (i = 0; i < database.size(); i++) {
    //        if (account == database[i].getID()) {
    //            CLS;
    //            cout << "\n�˺ŵ�¼�ɹ�����ӭ�û�" << account;
    //            flag = false;
    //            break;
    //        }
    //    }
    //    cout << "\n�˺Ų���ȷ��������������룡";
    //}
    //�˴�ȷ�Ϻ��¼�󶨵�΢�ź�΢�����ܴ�ʵ��

    stdlogin(database);
}

void WeblogDatabase::signup() {
    int newID;
    string newName;
    string newBirthDate;
    int newAge;
    string newLocation;
    bool flag = false;

    CLS;
    while (!flag) {
        flag = true;
        cout << "\n��������ϲ�����˺ţ������֣�����" << endl;
        cin >> newID;
        for (int i = 0; i < database.size(); i++) {
            if (database[i].getID() == newID) {
                cout << "\n�˺��ѱ�ע���ˣ����������룡" << endl;
                flag = false;
            }
        }
    }

    cout << "\n�������ǳƣ�" << endl;
    cin >> newName;
    cout << "\n�������������գ�" << endl;
    cin >> newBirthDate;
    cout << "\n���������Ĳ��䣺" << endl;
    cin >> newAge;
    cout << "\n�������������ڵأ�" << endl;
    cin >> newLocation;

    CLS;
    cout << "\n�˺�" << newID << "ע��ɹ���" << endl;
    setup(newID,newName,newBirthDate,newAge,newLocation);
}

void WeblogDatabase::setup(int ID, string nickname, string birthDate, int age,string location) {
    Weblog newAccount;  //����һ����΢���������������Ϣ��ʼ��

    newAccount.setID(ID);
    newAccount.setName(nickname);
    newAccount.setBirthDate(birthDate);
    newAccount.setAge(age);
    newAccount.setLocation(location);

    database.push_back(newAccount);
}

void WeblogDatabase::login() {
    //CLS;
    //bool flag = true;
    //while (flag) {
    //    cout << "\n������QQ�˺ţ�";
    //    int account, i;
    //    cin >> account;
    //    for (i = 0; i < database.size(); i++) {
    //        if (account == database[i].getID()) {
    //            CLS;
    //            cout << "\n�˺ŵ�¼�ɹ�����ӭ�û�" << account;
    //            flag = false;
    //            break;
    //        }
    //    }
    //    cout << "\n�˺Ų���ȷ��������������룡";
    //}

    stdlogin(database);
}

void WeChatDatabase::signup(QQDatabase &QQD) {

    bool flag = false;
    int newID;
    string newName;
    string newBirthDate;
    int newAge;
    string newLocation;
    bool isHaveWeibo;
    int qqID;

    CLS;
    while (!flag) {
        flag = true;
        cout << "\n��������ϲ�����˺ţ������֣�����" << endl;
        cin >> newID;
        for (int i = 0; i < database.size(); i++) {
            if (database[i].getID() == newID) {
                cout << "\n�˺��ѱ�ע���ˣ����������룡" << endl;
                flag = false;
            }
        }
    }

    cout << "\n�������ǳƣ�" << endl;
    cin >> newName;
    cout << "\n�������������գ�" << endl;
    cin >> newBirthDate;
    cout << "\n����������΢�䣺" << endl;
    cin >> newAge;
    cout << "\n�������������ڵأ�" << endl;
    cin >> newLocation;

    cout << "\n�Ƿ���Ҫ��QQ��y/n" << endl;
    char choose;
    cin >> choose;
    if (choose == 'y') {
        bool flag2 = false;
        while (!flag2) {
            cout << "\n����������΢�źţ�" << endl;
            cin >> qqID;
            int i;
            for (i = 0; i < QQD.database.size(); i++) {
                if (qqID == QQD.database[i].getID()) {
                    flag2 = true;
                    break;
                }
            }
            if (!flag2)
                cout << "\n��QQ�Ų����ڣ����������룡" << endl;
        }
    }
    else
        qqID = -1;

    CLS;
    cout << "\n�˺�" << newID << "ע��ɹ���" << endl;
    setup(newID, newName, newBirthDate, newAge, newLocation, qqID);
}

void WeChatDatabase::setup(int ID, string nickname, string birthDate, int age, string location, int qqID) {
    
    WeChat newAccount;

    newAccount.setID(ID);
    newAccount.setName(nickname);
    newAccount.setBirthDate(birthDate);
    newAccount.setAge(age);
    newAccount.setLocation(location);
    newAccount.setqqID(qqID);

    database.push_back(newAccount);
}

void WeChatDatabase::login() {
    //CLS;
    //bool flag = true;
    //while (flag) {
    //    cout << "\n������΢���˺ţ�";
    //    int account, i;
    //    cin >> account;
    //    for (i = 0; i < database.size(); i++) {
    //        if (account == database[i].getID()) {
    //            CLS;
    //            cout << "\n�˺ŵ�¼�ɹ�����ӭ�û�" << account;
    //            flag = false;
    //            break;
    //        }
    //    }
    //    cout << "\n�˺Ų���ȷ��������������룡";
    //}

    stdlogin(database);
}

template<class T>
void stdlogin(T& database) {
    CLS;
    bool flag = true;
    while (flag) {
        cout << "\n�������˺ţ�";
        int account, i;
        cin >> account;
        for (i = 0; i < database.size(); i++) {
            if (account == database[i].getID()) {
                CLS;
                cout << "\n�˺ŵ�¼�ɹ�����ӭ�û�" << account;
                flag = false;
                break;
            }
        }
        cout << "\n�˺Ų���ȷ��������������룡";
    }
}

