#include<iostream>
#include<vector>
#include<string>
#include<stdlib.h>
#include"base.h"
#include"data.h"
#define CLS system("cls")  //清屏函数

using namespace std;

void QQDatabase::signup(WeblogDatabase &BD,WeChatDatabase &WCD) {  //注册新QQ号函数

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
    //此处尝试使用迭代器获取最后一个已有账号的ID，结果未能成功实现
    //故使用手动输入账号注册
    while (!flag) {
        flag = true;
        cout << "\n请输入您喜欢的账号（纯数字！）：" << endl;
        cin >> newID;
        for (int i = 0; i < database.size(); i++) {
            if (database[i].getID() == newID) {
                cout << "\n账号已被注册了，请重新输入！" << endl;
                flag = false;
            }
        }
    }

    cout << "\n请输入昵称：" << endl;
    cin >> newName;
    cout << "\n请输入您的生日：" << endl;
    cin >> newBirthDate;
    cout << "\n请输入您的Q龄：" << endl;
    cin >> newAge;
    cout << "\n请输入您的所在地：" << endl;
    cin >> newLocation;
    cout << "\n是否需要同时开通微博？y/n" << endl;
    char choose;
    cin >> choose;
    if (choose == 'y')
        isHaveWeibo = true;
    else
        isHaveWeibo = false;

    cout << "\n是否需要绑定微信？y/n" << endl;
    char choose;
    cin >> choose;
    if (choose == 'y') {
        bool flag2 = false;
        while (!flag2) {
            cout << "\n请输入您的微信号：" << endl;
            cin >> weChatID;
            int i;
            for (i = 0; i < WCD.database.size(); i++) {
                if (weChatID == WCD.database[i].getID()) {
                    flag2 = true;
                    break;
                }
            }
            if (!flag2)
                cout << "\n此微信号不存在！请重新输入！" << endl;
        }
    }
    else
        weChatID = -1;

    CLS;
    cout << "\n账号" << newID << "注册成功！" << endl;
    setup(newID, newName, newBirthDate, newAge, newLocation
        , isHaveWeibo, weChatID, BD);
}

void QQDatabase::setup(int ID, string nickname, string birthDate, int age,
    string location, bool blog, int weChatID, WeblogDatabase blogD) {

    QQ newAccount;  //创建一个新QQ对象并用填入的信息初始化

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
    //    cout << "\n请输入QQ账号：";
    //    int account, i;
    //    cin >> account;
    //    for (i = 0; i < database.size(); i++) {
    //        if (account == database[i].getID()) {
    //            CLS;
    //            cout << "\n账号登录成功！欢迎用户" << account;
    //            flag = false;
    //            break;
    //        }
    //    }
    //    cout << "\n账号不正确！请检查后重新输入！";
    //}
    //此处确认后登录绑定的微信和微博功能待实现

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
        cout << "\n请输入您喜欢的账号（纯数字！）：" << endl;
        cin >> newID;
        for (int i = 0; i < database.size(); i++) {
            if (database[i].getID() == newID) {
                cout << "\n账号已被注册了，请重新输入！" << endl;
                flag = false;
            }
        }
    }

    cout << "\n请输入昵称：" << endl;
    cin >> newName;
    cout << "\n请输入您的生日：" << endl;
    cin >> newBirthDate;
    cout << "\n请输入您的博龄：" << endl;
    cin >> newAge;
    cout << "\n请输入您的所在地：" << endl;
    cin >> newLocation;

    CLS;
    cout << "\n账号" << newID << "注册成功！" << endl;
    setup(newID,newName,newBirthDate,newAge,newLocation);
}

void WeblogDatabase::setup(int ID, string nickname, string birthDate, int age,string location) {
    Weblog newAccount;  //创建一个新微博对象并用填入的信息初始化

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
    //    cout << "\n请输入QQ账号：";
    //    int account, i;
    //    cin >> account;
    //    for (i = 0; i < database.size(); i++) {
    //        if (account == database[i].getID()) {
    //            CLS;
    //            cout << "\n账号登录成功！欢迎用户" << account;
    //            flag = false;
    //            break;
    //        }
    //    }
    //    cout << "\n账号不正确！请检查后重新输入！";
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
        cout << "\n请输入您喜欢的账号（纯数字！）：" << endl;
        cin >> newID;
        for (int i = 0; i < database.size(); i++) {
            if (database[i].getID() == newID) {
                cout << "\n账号已被注册了，请重新输入！" << endl;
                flag = false;
            }
        }
    }

    cout << "\n请输入昵称：" << endl;
    cin >> newName;
    cout << "\n请输入您的生日：" << endl;
    cin >> newBirthDate;
    cout << "\n请输入您的微龄：" << endl;
    cin >> newAge;
    cout << "\n请输入您的所在地：" << endl;
    cin >> newLocation;

    cout << "\n是否需要绑定QQ？y/n" << endl;
    char choose;
    cin >> choose;
    if (choose == 'y') {
        bool flag2 = false;
        while (!flag2) {
            cout << "\n请输入您的微信号：" << endl;
            cin >> qqID;
            int i;
            for (i = 0; i < QQD.database.size(); i++) {
                if (qqID == QQD.database[i].getID()) {
                    flag2 = true;
                    break;
                }
            }
            if (!flag2)
                cout << "\n此QQ号不存在！请重新输入！" << endl;
        }
    }
    else
        qqID = -1;

    CLS;
    cout << "\n账号" << newID << "注册成功！" << endl;
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
    //    cout << "\n请输入微信账号：";
    //    int account, i;
    //    cin >> account;
    //    for (i = 0; i < database.size(); i++) {
    //        if (account == database[i].getID()) {
    //            CLS;
    //            cout << "\n账号登录成功！欢迎用户" << account;
    //            flag = false;
    //            break;
    //        }
    //    }
    //    cout << "\n账号不正确！请检查后重新输入！";
    //}

    stdlogin(database);
}

template<class T>
void stdlogin(T& database) {
    CLS;
    bool flag = true;
    while (flag) {
        cout << "\n请输入账号：";
        int account, i;
        cin >> account;
        for (i = 0; i < database.size(); i++) {
            if (account == database[i].getID()) {
                CLS;
                cout << "\n账号登录成功！欢迎用户" << account;
                flag = false;
                break;
            }
        }
        cout << "\n账号不正确！请检查后重新输入！";
    }
}

