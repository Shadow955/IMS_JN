#include<iostream>
#include<vector>
#include<string>
#include<stdlib.h>
#include"base.h"
#define CLS system("cls")  //清屏函数

using namespace std;

Tencent::Tencent() {
    ID = -1;
    age = -1;
    nickname = "匿名";
    birthDate = "暂无数据";
    location = "未知";
}

//以下是设定、初始化账号信息函数
void Tencent::setID(int in) {
    ID = in;
}

void Tencent::setAge(int in) {
    age = in;
}

void Tencent::setName(string in) {
    nickname = in;
}

void Tencent::setBirthDate(string in) {
    birthDate = in;
}

void Tencent::setLocation(string in) {
    location = in;
}

int Tencent::getID() {
    return ID;
}
int Tencent::getAge() {
    return age;
}
//以下是获取账号信息函数
string Tencent::getName() {
    return nickname;
}
string Tencent::getBirthDate() {
    return birthDate;
}
string Tencent::getLoation() {
    return location;
}
vector<int> Tencent::getFriendList() {
    return friendList;
}

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

QQ::QQ() {  //无参构造函数
    isHaveWebolg = false;
    isHaveWechat = false;
    weChatID = -1;
}
//以下是设定函数
void QQ::linkToWebolg() {
    isHaveWebolg = true;
}
void QQ::linkToWechat(int wechatID) {
    isHaveWechat = true;
    weChatID = wechatID;
}
//以下是获取信息函数
bool QQ::ifSetWebolg() {
    return isHaveWebolg;
}
bool QQ::ifSetWechat() {
    return isHaveWechat;
}
int QQ::getWechatID() {
    return weChatID;
}
vector<int> QQ::getGroupList() {
    return groupList;
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

Weblog::Weblog(QQ  qq) {  //含参构造函数，仅在开通了微博时执行
    ID = qq.getID();
    nickname = qq.getName();
    isHaveWebolg = true;  //是否开通了微博
}
Weblog::Weblog() {}  //重载无参构造函数，默认执行此构造函数

//以下是设定函数
void Weblog::setWeblogID(QQ  qq) {
    ID = qq.getID();
}
void Weblog::setisHaveWeblog(bool is) {
    isHaveWebolg = is;
}
//以下是获取信息函数
bool Weblog::getIsHaveWeblog() {
    return isHaveWebolg;
}

void Weblog::showInfo() {  //微博:显示当前信息函数
    cout << "\nQQ帐号:" << ID << endl;
    cout << "\n昵称:" << nickname << endl;
    cout << "\n出生日期:" << birthDate << endl;
    cout << "\n博龄:" << age << endl;
    cout << "\n住址:" << location << endl;
}

WeChat::WeChat(QQ qq) {  //有参构造函数，仅当绑定了QQ时执行
    qqID = qq.getID();
}

WeChat::WeChat() {  //无参构造函数，默认执行此构造函数
    qqID = -1;  //默认不绑定QQ账号
}

//以下是信息获取函数
int WeChat::getqqID() {
    return qqID;
}

vector<int> WeChat::getGroupList() {
    return groupList;
}

void WeChat::setqqID(int qq) {
    qqID = qq;
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


int mainUI() {
    CLS;      //清屏函数
    int choose = 0;

    cout << "\n\n\n欢迎使用JN账号管理系统！" << endl;
    cout << "制作者55190812JN";
    cout << "\n1:<QQ账号管理>" << endl;
    cout << "\n2:<微博账号管理>" << endl;
    cout << "\n3:<微信账号管理>" << endl;
    cout << "\n4:<QQ群成员管理>" << endl;
    cout << "\n0:<退出系统>" << endl;
    cout << "\n注:仅上述出现的纯数字输入有效！其他输入均为非法输入！\n\n" << endl;
    cout << "请输入您的选择：";
    cin >> choose;
    if (choose >= 0 && choose <= 4) {
        CLS;
        return choose;
    }
    else {
        CLS;
        cout << "\n警告:您的输入有误！请重新输入！\n" << endl;
        mainUI();
    }
}

template<typename T>
int stdlogin(T database) {  //尝试使用模板函数实现多平台登录
    CLS;
    bool flag = true;
    int account, i;
    while (flag) {
        cout << "\n请输入账号：" << endl;
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

Group::Group() {
    groupNum = -1;  //约定群号默认初始值为-1
}

void Group::setGroupNum(int number) {
    groupNum = number;
}

int Group::getGroupNum() {
    return groupNum;
}

vector<int> Group::getMemberList() {
    return memberList;
}

void QQDatabase::signup(WeblogDatabase BD, WeChatDatabase WD) {  //注册新QQ号函数

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
    //char choose;
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
    setup(newID, newName, newBirthDate, newAge, newLocation);
}

void WeblogDatabase::setup(int ID, string nickname, string birthDate, int age, string location) {
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

void WeChatDatabase::signup(QQDatabase QQD) {

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
void Group::addMember(T D, int number) {

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
        CLS;
        return choose;
    }
    else {
        CLS;
        cout << "\n\t\t警告:您的输入有误！请重新输入！\n" << endl;
        QQmain();
    }
}

int QQDatabase::QQservice(WeblogDatabase BD, WeChatDatabase WD) {
    int choose;
    int result = 10;
    choose = QQmain();
    switch (choose) {
    case 1: {
        int ID = login();
        QQclient(ID, BD, WD);
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
    return result;
}

int QQDatabase::QQclient(int ID, WeblogDatabase BD, WeChatDatabase WD) {
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
                CLS;
                cout << "\t请输入您想要比较共同好友的QQ帐号：";
                int account;
                bool flag = false;
                cin >> account;
                for (int j = 0; j < database.size(); j++) {
                    if (database[j].getID() == account) {
                        database[i].checkCommonFriend(database[j]);
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
                CLS;
                cout << "\n请输入您要删除的好友的QQ帐号：";
                int account;
                cin >> account;
                database[i].deleteFriend(account);
                QQclient(ID, BD, WD);
                break;
            }

            case 5: {             //加群
                CLS;
                cout << "\t请输入您想加入的群的群号：";
                int groupNumber;
                cin >> groupNumber;
                database[i].enterGroup(groupNumber);
                QQclient(ID, BD, WD);
                break;
            }

            case 6: {             //退群
                CLS;
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
        QQclient(ID, BD, WD);
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


int WeblogDatabase::weblogmain() {
    int choose = 0;

    cout << "\n\n\n\t\t------------微博账号综合管理系统-----------" << endl;
    cout << "\n\t\t\t\t1:<微博账号登陆>" << endl;
    cout << "\n\t\t\t\t2:<查看所有已注册的微博账号>" << endl;
    cout << "\n\t\t\t\t0:<返回上一层>" << endl;
    cout << "\n\t\t注:仅上述出现的纯数字输入有效！其他输入均为非法输入！\n\n" << endl;
    cout << "\t\t\t请输入您的选择：";
    cin >> choose;
    if (choose >= 0 && choose <= 2) {
        CLS;
        return choose;
    }
    else {
        CLS;
        cout << "\n\t\t警告:您的输入有误！请重新输入！\n" << endl;
        weblogmain();
    }
}

int WeblogDatabase::weblogUI() {
    int choose = 0;

    cout << "\n\n\n------------微博帐号服务系统-----------" << endl;
    cout << "\n1:<修改昵称>" << endl;
    cout << "\n2:<添加好友>" << endl;
    cout << "\n3:<删除好友>" << endl;
    cout << "\n4:<比较与他人的共同好友>" << endl;
    cout << "\n0:<返回上一层>" << endl;
    cout << "\n注:仅上述出现的纯数字输入有效！其他输入均为非法输入！\n\n" << endl;
    cout << "\n请输入您的选择：";
    cin >> choose;
    if (choose >= 0 && choose <= 4) {
        CLS;
        return choose;
    }
    else {
        CLS;
        cout << "\n\t\t警告:您的输入有误！请重新输入！\n" << endl;
        weblogUI();
    }
}

int WeblogDatabase::weblogService() {
    int choose;
    int result = 10;

    choose = weblogmain();

    switch (choose) {

    case 1: {                //登陆
        //CLS;
        //cout << "\t请输入您的微博账号:" << endl;
        //int account;
        //cin >> account;
        //int temp = serviceWeibo(account);
        //if (temp == 10)
        //    selectWeibo();
        login();
        break;
    }

    case 2: {             //显示所有成员信息
        CLS;
        cout << "\n\n\n------------微博用户成员列表-----------" << endl;
        for (int i = 0; i < database.size(); i++)
            cout << "\n" << database[i].getID() << ":" << database[i].getName() << endl;
        weblogService();
        break;
    }

    case 0: {             //返回上一层
        CLS;
        result = mainUI();
        break;
    }
    };
    return result;
}

int WeblogDatabase::weblogClient(int ID) {
    bool flag = false;
    int choose;
    int result = 10;
    for (int i = 0; i < database.size(); i++) {
        if (database[i].getID() == ID) {       //查找并显示该账号信息
            cout << "\n\n\n\t\t------------帐号信息-----------" << endl;
            database[i].showInfo();
            choose = weblogUI();
            switch (choose) {

            case 1: {             //修改昵称
                CLS;
                cout << "\t请输入更改之后的昵称：";
                string name;
                cin >> name;
                database[i].setName(name);
                weblogClient(ID);
                break;
            }

            case 2: {             //添加好友
                CLS;
                cout << "\t请输入您想要添加的好友的微博帐号：";
                int account;
                bool flag = false;
                cin >> account;
                for (int j = 0; j < database.size(); j++) {
                    if (database[j].getID() == account) {
                        database[i].addFriend(account);
                        flag = true;
                        break;
                    }
                }
                if (!flag)
                    cout << "\t该用户并没有在本系统注册，请您核实您的信息！" << endl;
                weblogClient(ID);
                break;
            }

            case 3: {             //删除好友
                CLS;
                cout << "\t请输入您要删除的好友的微博帐号：";
                int account;
                cin >> account;
                database[i].deleteFriend(account);
                weblogClient(ID);
            }

            case 4: {             //比较共同好友
                CLS;
                cout << "\t请输入您想要比较共同好友的微博帐号：";
                int account;
                bool flag = false;
                cin >> account;
                for (int j = 0; j < database.size(); j++) {
                    if (database[j].getID() == account) {
                        database[i].checkCommonFriend(database[j]);
                        flag = true;
                        break;
                    }
                }

                if (!flag)
                    cout << "\t该帐号并没有在本系统中注册过，请核实您的信息！" << endl;
                weblogClient(ID);
            }

            case 0: {             //返回上一层
                CLS;
                result = weblogmain();
                break;
            }
            };
            flag = true;
            break;
        }
    }

    if (!flag) {
        cout << "\t查无此人！请确认您的微博帐号是否填写正确！" << endl;
        weblogService();
    }

    return result;
}

int WeChatDatabase::wechatmain() {
    int choose = 0;

    cout << "\n\n\n-----------微信账号综合管理系统-----------" << endl;
    cout << "\n1:<微信账号登陆>" << endl;
    cout << "\n2:<查看所有已注册的微信账号>" << endl;
    cout << "\n3:<注册属于您自己的微信账号>" << endl;
    cout << "\n0:<返回上一层>" << endl;
    cout << "\n注:仅上述出现的纯数字输入有效！其他输入均为非法输入！\n\n" << endl;
    cout << "请输入您的选择：";
    cin >> choose;
    if (choose >= 0 && choose <= 3) {
        CLS;
        return choose;
    }
    else {
        CLS;
        cout << "\n\t\t警告:您的输入有误！请重新输入！\n" << endl;
        wechatmain();
    }
}

int WeChatDatabase::wechatService(QQDatabase QD) {
    int choose;
    int result = 10;
    choose = wechatmain();

    switch (choose) {
    case 1: {            //登陆
        /*CLS;
        cout << "请输入您的微信账号：";
        string account;
        cin >> account;
        int temp;
        temp = serviceWeixin(account);
        if (temp == 10)
            selectWeixin();*/
        login();
        break;
    }

    case 2: {                 //显示所有微信用户
        CLS;
        cout << "\n\n\n-----------微信账号信息列表-----------" << endl;
        for (int i = 0; i < database.size(); i++)
            cout << database[i].getID() << ":" << database[i].getName() << endl;
        wechatService(QD);
        break;
    }

    case 3: {        //注册微信
        CLS;
        string number;
        string name;
        int qqNumber;
        bool flag = false;

        cout << "\n\n\n\t\t------------感谢您注册微信账号-----------" << endl;
        /*     while (!flag)
             {
                 flag = true;
                 cout << "\t请输入您喜欢的微信账号：";
                 cin >> number;
                 for (int i = 0; i < client.size(); i++) {
                     if (client[i].getWeixinAccount() == number) {
                         cout << "\t很抱歉，您的账号已经被别人抢先注册了，换一个吧！" << endl;
                         flag = false;
                         break;
                     }
                 }
             }

             cout << "\t请输入您的昵称：";
             cin >> name;
             cout << "\t请问您是否要关联您的QQ账号？Y/N" << endl;
             char chooseQQ;
             cin >> chooseQQ;
             if (chooseQQ == 'Y' || chooseQQ == 'y') {
                 cout << "\t请输入您要绑定的QQ账号：";
                 cin >> qqNumber;
             }
             else
                 qqNumber = -1;

             setNewWeixinAccount(number, name, qqNumber);
             CLS;
             cout << "\t恭喜您！账号为" << number << "的微信账号已经成功创建！" << endl;
             selectWeixin();*/
        signup(QD);
        break;
    }

    case 0: {        //返回上一层
        CLS;
        result = mainUI();
        break;
    }
    };

    return result;
}

int WeChatDatabase::wechatUI() {
    int choose = 0;

    cout << "\n\n\n------------微信帐号服务系统-----------" << endl;
    cout << "\n1:<修改昵称>" << endl;
    cout << "\n2:<添加好友>" << endl;
    cout << "\n3:<删除好友>" << endl;
    cout << "\n4:<比较与他人的共同好友>" << endl;
    cout << "\n5:<绑定QQ号>" << endl;
    cout << "\n0:<返回上一层>" << endl;
    cout << "\n注:仅上述出现的纯数字输入有效！其他输入均为非法输入！\n\n" << endl;
    cout << "请输入您的选择：";
    cin >> choose;
    if (choose >= 0 && choose <= 5) {
        CLS;
        return choose;
    }
    else {
        CLS;
        cout << "\n\t\t警告:您的输入有误！请重新输入！\n" << endl;
        wechatUI();
    }
}

int WeChatDatabase::wechatClient(int ID) {
    bool flag;
    int choose;
    int result = 10;
    for (int i = 0; i < database.size(); i++) {      //查找并显示微信用户个人信息
        if (database[i].getID() == ID) {
            cout << "\n\n\n\t\t------------帐号信息-----------" << endl;
            database[i].showInfo();
            choose = wechatUI();

            switch (choose) {
            case 1: {                     //修改昵称
                CLS;
                cout << "\t请输入更改之后的昵称：";
                string name;
                cin >> name;
                database[i].setName(name);
                wechatClient(ID);
                break;
            }

            case 2: {                 //添加好友
                CLS;
                cout << "\t请输入你要添加的好友的微信帐号：";
                int account;
                bool flag = false;
                cin >> account;
                for (int j = 0; j < database.size(); j++) {
                    if (database[j].getID() == account) {
                        database[i].addFriend(account);
                        flag = true;
                        break;
                    }
                }
                if (!flag)
                    cout << "\t该用户并没有在本系统注册，请您核实您的信息！" << endl;
                wechatClient(ID);
                break;
            }

            case 3: {                     //删除好友
                CLS;
                cout << "\t请输入您要删除的微信好友的帐号：";
                int account;
                cin >> account;
                database[i].deleteFriend(account);
                wechatClient(ID);
                break;
            }

            case 4: {             //比较共同好友
                CLS;
                cout << "\t请输入您想要比较共同好友的微信帐号：";
                int account;
                bool flag = false;
                cin >> account;
                for (int j = 0; j < database.size(); j++) {
                    if (database[j].getID() == account) {
                        database[i].checkCommonFriend(database[j]);
                        flag = true;
                        break;
                    }
                }

                if (!flag)
                    cout << "\t您输入微信帐号并没有在本系统中注册过，请核实您的信息!" << endl;

                wechatClient(ID);
            }

            case 5: {                 //绑定QQ好友
                CLS;
                cout << "\n请输入您想要绑定的QQ帐号：";
                int account;         //这里如果进行QQ号的正确性的判断就会出现问题，原因是QQ账号管理类有问题
                cin >> account;
                database[i].setqqID(account);
                cout << "\n恭喜您！QQ帐号绑定成功！" << endl;

                wechatClient(ID);
                break;
            }

            case 0: {                 //返回上一层
                CLS;
                result = wechatmain();
                break;
            }
            };

            flag = true;
            break;
        }
    }

    //if (!flag) {
    //    cout << "\t请确认您的微信帐号是否填写正确！" << endl;
    //    wechatService(QD);
    //}
    return result;
}


void GroupData::setNewGroup(int number) {  //使用数据初始化设定新群
    Group newGroup;
    newGroup.setGroupNum(number);
    database.push_back(newGroup);
}

void GroupData::showAllGroup() {  //显示目前所有群组
    CLS;
    for (int i = 0; i < database.size(); i++)
        cout << database[i].getGroupNum() << endl;
}