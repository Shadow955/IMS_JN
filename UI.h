#pragma once
#include<iostream>
#include<string>
#include"data.h"
#include"base.h"

using namespace std;

int QQmain() {
    int choose = 0;

    cout << "\n\n\n------------��ӭʹ��JNQQ��-----------" << endl;
    cout << "\n1:<QQ�˺ŵ�½>" << endl;
    cout << "\n2:<�鿴������ע���QQ��>" << endl;
    cout << "\n3:<ע����QQ��>" << endl;
    cout << "\n0:<������һ��>" << endl;
    cout << "\nע:���������ֵĴ�����������Ч�����������Ϊ�Ƿ����룡\n\n" << endl;
    cout << "����������ѡ��";
    cin >> choose;
    if (choose >= 0 && choose <= 3) {
        system("cls");
        return choose;
    }
    else {
        system("cls");
        cout << "\n\t\t����:���������������������룡\n" << endl;
        QQmain();
    }
}

int QQservice() {

}