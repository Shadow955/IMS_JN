#pragma once
#include<iostream>
#include<string>
#include"data.h"
#include"base.h"

using namespace std;

int QQmain() {
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

int QQservice() {

}