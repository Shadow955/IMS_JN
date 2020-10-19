#include<iostream>
#include<vector>
#include<string>
#include<stdlib.h>
#include"base.h"
#include"data.h"
#define CLS system("cls")  //清屏函数

using namespace std;

void QQDatabase::signup(WeblogDatabase BD,WeChatDatabase WD) {  //注册新QQ号函数

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
            for (i = 0; i < WD.database.size(); i++) {
                if (weChatID == WD.database[i].getID()) {
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

int QQDatabase::login() {
    //CLS;
    //bool flag = true;
    //while (flag) {
    //    cout << "\n请输入QQ账号："<<endl;
    //    int account, i;
    //    cin >> account;
    //    for (i = 0; i < database.size(); i++) {
    //        if (account == database[i].getID()) {
    //            CLS;
    //            cout << "\n账号登录成功！欢迎用户" << account<<endl;
    //            flag = false;
    //            break;
    //        }
    //    }
    //    cout << "\n账号不正确！请检查后重新输入！"<<endl;
    //}
    //此处确认后登录绑定的微信和微博功能待实现

    int ID = stdlogin(database);
    return ID;
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
    //    cout << "\n请输入QQ账号："<<endl;
    //    int account, i;
    //    cin >> account;
    //    for (i = 0; i < database.size(); i++) {
    //        if (account == database[i].getID()) {
    //            CLS;
    //            cout << "\n账号登录成功！欢迎用户" << account<<endl;
    //            flag = false;
    //            break;
    //        }
    //    }
    //    cout << "\n账号不正确！请检查后重新输入！"<<endl;
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
    //    cout << "\n请输入微信账号："<<endl;
    //    int account, i;
    //    cin >> account;
    //    for (i = 0; i < database.size(); i++) {
    //        if (account == database[i].getID()) {
    //            CLS;
    //            cout << "\n账号登录成功！欢迎用户" << account<<endl;
    //            flag = false;
    //            break;
    //        }
    //    }
    //    cout << "\n账号不正确！请检查后重新输入！"<<endl;
    //}

    stdlogin(database);
}

template<typename T>
int stdlogin(T database) {  //尝试使用模板函数实现多平台登录
    CLS;
    bool flag = true;
    while (flag) {
        cout << "\n请输入账号：" << endl;
        int account, i;
        cin >> account;
        for (i = 0; i < database.size(); i++) {
            if (account == database[i].getID()) {
                CLS;
                cout << "\n账号登录成功！欢迎用户" << account << endl;
                flag = false;
                break;
            }
        }
        cout << "\n账号不存在！请检查后重新输入！" << endl;
    }
    return account;
}

void Group::showInfo() {  //展示群信息函数
    cout << "\n群号：" << groupNum << endl;
    cout << "\n成员列表：" << endl;
    if (memberList.empty())
        cout << "\n此群暂无成员！" << endl;
    else {
        for (int i = 0; i < memberList.size(); i++)
            cout << "\n" << memberList[i] << endl;
    }
}

template<typename T>
void Group::addMember(T &D,int number) {

    bool flag = false;
    for (int i = 0; i < D.database.size(); i++) {
        if (number == D.database[i].getID()) {
            flag = true;
            break;
        }
    }
    if (flag) {
        for (int j = 0; j < memberList.size(); j++) {
            if (memberList[j] == number) {
                cout << "\n该用户已经是群组成员！" << endl;
                return;
            }
        }
        memberList.push_back(number);
        cout << "\n成员添加成功！" << endl;
        return;
    }
    else
        cout << "该账号不存在！" << endl;
}

void Group::deleteMember(int number) {

    bool flag = false;
    for (int i = 0; i < memberList.size(); i++) {
        if (memberList[i] == number) {
            memberList.erase(memberList.begin() + i);
            flag = true;
            cout << "\n删除成功！" << endl;
            break;
        }
    }
    if (!flag)
        cout << "\n此账号不在该群中！" << endl;
}

void GroupData::createNewGroup() {
    int num;
    bool flag = false;
    CLS;
    while (!flag) {
        flag = true;
        cout << "\n请输入想创建的群号：" << endl;
        cin >> num;
        for (int i = 0; i < database.size(); i++) {
            if (num == database[i].getGroupNum()) {
                cout << "\n此群号已被注册！" << endl;
                flag = false;
            }
        }
    }
    if (flag) {
        setNewGroup(num);
        CLS;
        cout << "已创建群" << num << endl;
    }
}

int QQDatabase::QQmain() {
    int choose = 0;

    cout << "\n\n\n------------欢迎使用JNQQ！-----------" << endl;
    cout << "\n1:<QQ账号登陆>" << endl;
    cout << "\n2:<查看所有已注册的QQ号>" << endl;
    cout << "\n3:<注册新QQ号>" << endl;
    cout << "\n0:<返回上一层>" << endl;
    cout << "\n注:仅上述出现的纯数字输入有效！其他输入均为非法输入！\n\n" << endl;
    cout << "请输入您的选择：";
    cin >> choose;
    if (choose >= 0 && choose <= 3) {
        system("cls");
        return choose;
    }
    else {
        system("cls");
        cout << "\n\t\t警告:您的输入有误！请重新输入！\n" << endl;
        QQmain();
    }
}

int QQDatabase::QQservice(WeblogDatabase BD,WeChatDatabase WD) {
    int choose;
    int result = 10;
    choose = QQmain();
    switch (choose) {
    case 1: {
        int ID = login();
        QQclient(ID,BD,WD);
        break;
        }
    case 2: {
        CLS;
        cout << "\n\n\n------------QQ账号信息列表-----------" << endl;
        for (int i = 0; i < database.size(); i++)
            cout << database[i].getID() << ":" << database[i].getName() << endl;
        QQservice(BD, WD);
        break;
    }
    case 3: {
        signup(BD, WD);
        break;
    }
    }
}

int QQDatabase::QQclient(int ID,WeblogDatabase &BD,WeChatDatabase &WD) {
    bool flag = false;
    int choose;
    int result = 10;
    for (int i = 0; i < database.size(); i++) {      //查找并显示QQ账号信息
        if (database[i].getID() == ID) {
            cout << "\n\n\n------------帐号信息-----------" << endl;
            database[i].showInfo();
            choose = QQUI();

            switch (choose) {

            case 1: {         //更改昵称
                CLS;
                cout << "\t请输入更改之后的昵称：";
                string name;
                cin >> name;
                database[i].setName(name);
                QQclient(ID, BD, WD);
                break;
            }

            case 2: {         //添加好友
                CLS;
                cout << "\t请输入您要添加的QQ好友帐号：";
                int account;
                cin >> account;
                database[i].addFriend(account);
                break;
            }

            case 3: {             //比较共同好友
                system("cls");
                cout << "\t请输入您想要比较共同好友的QQ帐号：";
                int account;
                bool flag = false;
                cin >> account;
                for (int j = 0; j < database.size(); j++) {
                    if (database[j].getID() == account) {
                        database[i].checkQQCommonFriend(client[j]);
                        flag = true;
                        break;
                    }
                }
                if (flag)
                    QQclient(ID, BD, WD);
                else {
                    cout << "\n您输入的QQ帐号并未在本系统中注册过，请您核实您的输入！" << endl;
                    QQclient(ID, BD, WD);
                }
                break;
            }

            case 4: {         //删除好友
                system("cls");
                cout << "\n请输入您要删除的好友的QQ帐号：";
                int account;
                cin >> account;
                database[i].deleteFriend(account);
                QQclient(ID, BD, WD);
                break;
            }

            case 5: {             //加群
                system("cls");
                cout << "\t请输入您想加入的群的群号：";
                int groupNumber;
                cin >> groupNumber;
                database[i].enterGroup(groupNumber);
                QQclient(ID, BD, WD);
                break;
            }

            case 6: {             //退群
                system("cls");
                cout << "\t请输入您要退出的群号：";
                int groupNumber;
                cin >> groupNumber;
                database[i].exitGroup(groupNumber);
                QQclient(ID, BD, WD);
                break;
            }

            case 7: {             //开通微博
                bool flag = false;
                if (database[i].ifSetWebolg())
                    cout << "\n此帐号已经开通过微博了！" << endl;
                else {
                    for (int j = 0; j < WD.database.size(); j++) {
                        if (BD.database[j].getID() == ID) {
                            BD.database[j].setisHaveWeblog(true);
                            flag = true;
                            break;
                        }
                    }
                    if (!flag)
                        Weblog w(database[i]);

                    database[i].linkToWebolg();
                    cout << "\n恭喜您已经成功开通微博了！" << endl;
                }
                QQclient(ID, BD, WD);
                break;
            }

            case 8: {             //开通微信
                CLS;
                cout << "\n请输入您要绑定的微信帐号：";
                int account;
                cin >> account;
                database[i].linkToWechat(account);
                cout << "\n恭喜您！账号绑定成功！" << endl;
                QQclient(ID, BD, WD);
                break;
            }

            case 0: {             //返回上一层
                CLS;
                result = QQUI();
                break;
            }
            };
            flag = true;
            break;
        }
    }
    if (!flag) {
        cout << "\t查无此人！请确认您的QQ帐号是否填写正确！" << endl;
        QQclient(ID,BD, WD);
    }

    return result;
}


int QQDatabase::QQUI() {
    int choose = 0;

    cout << "\n\n\n------------QQ帐号服务系统-----------" << endl;
    cout << "\n1:<修改昵称>" << endl;
    cout << "\n2:<添加好友>" << endl;
    cout << "\n3:<比较与他人的共同好友>" << endl;
    cout << "\n4:<删除好友>" << endl;
    cout << "\n5:<加入一个群>" << endl;
    cout << "\n6:<退出一个群>" << endl;
    cout << "\n7:<绑定微博>" << endl;
    cout << "\n8:<绑定微信>" << endl;
    cout << "\n0:<返回上一层>" << endl;
    cout << "\n注:仅上述出现的纯数字输入有效！其他输入均为非法输入！\n\n" << endl;
    cout << "\n请输入您的选择：";
    cin >> choose;
    if (choose >= 0 && choose <= 8) {
        CLS;
        return choose;
    }
    else {
        CLS;
        cout << "\n警告:您的输入有误！请重新输入！\n" << endl;
        QQUI();
    }
}