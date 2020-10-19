#include<iostream>
#include<vector>
#include<string>
#include<stdlib.h>
#include"data.h"
#include"base.h"
#define CLS system("cls")  //��������

using namespace std;

void QQDatabase::signup(WeblogDatabase BD,WeChatDatabase WD) {  //ע����QQ�ź���

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
    //char choose;
    cin >> choose;
    if (choose == 'y') {
        bool flag2 = false;
        while (!flag2) {
            cout << "\n����������΢�źţ�" << endl;
            cin >> weChatID;
            int i;
            for (i = 0; i < WD.database.size(); i++) {
                if (weChatID == WD.database[i].getID()) {
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

int QQDatabase::login() {
    //CLS;
    //bool flag = true;
    //while (flag) {
    //    cout << "\n������QQ�˺ţ�"<<endl;
    //    int account, i;
    //    cin >> account;
    //    for (i = 0; i < database.size(); i++) {
    //        if (account == database[i].getID()) {
    //            CLS;
    //            cout << "\n�˺ŵ�¼�ɹ�����ӭ�û�" << account<<endl;
    //            flag = false;
    //            break;
    //        }
    //    }
    //    cout << "\n�˺Ų���ȷ��������������룡"<<endl;
    //}
    //�˴�ȷ�Ϻ��¼�󶨵�΢�ź�΢�����ܴ�ʵ��

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
    //    cout << "\n������QQ�˺ţ�"<<endl;
    //    int account, i;
    //    cin >> account;
    //    for (i = 0; i < database.size(); i++) {
    //        if (account == database[i].getID()) {
    //            CLS;
    //            cout << "\n�˺ŵ�¼�ɹ�����ӭ�û�" << account<<endl;
    //            flag = false;
    //            break;
    //        }
    //    }
    //    cout << "\n�˺Ų���ȷ��������������룡"<<endl;
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
    //    cout << "\n������΢���˺ţ�"<<endl;
    //    int account, i;
    //    cin >> account;
    //    for (i = 0; i < database.size(); i++) {
    //        if (account == database[i].getID()) {
    //            CLS;
    //            cout << "\n�˺ŵ�¼�ɹ�����ӭ�û�" << account<<endl;
    //            flag = false;
    //            break;
    //        }
    //    }
    //    cout << "\n�˺Ų���ȷ��������������룡"<<endl;
    //}

    stdlogin(database);
}


void Group::showInfo() {  //չʾȺ��Ϣ����
    cout << "\nȺ�ţ�" << groupNum << endl;
    cout << "\n��Ա�б�" << endl;
    if (memberList.empty())
        cout << "\n��Ⱥ���޳�Ա��" << endl;
    else {
        for (int i = 0; i < memberList.size(); i++)
            cout << "\n" << memberList[i] << endl;
    }
}

template<typename T>
void Group::addMember(T D,int number) {

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
                cout << "\n���û��Ѿ���Ⱥ���Ա��" << endl;
                return;
            }
        }
        memberList.push_back(number);
        cout << "\n��Ա��ӳɹ���" << endl;
        return;
    }
    else
        cout << "���˺Ų����ڣ�" << endl;
}

void Group::deleteMember(int number) {

    bool flag = false;
    for (int i = 0; i < memberList.size(); i++) {
        if (memberList[i] == number) {
            memberList.erase(memberList.begin() + i);
            flag = true;
            cout << "\nɾ���ɹ���" << endl;
            break;
        }
    }
    if (!flag)
        cout << "\n���˺Ų��ڸ�Ⱥ�У�" << endl;
}

void GroupData::createNewGroup() {
    int num;
    bool flag = false;
    CLS;
    while (!flag) {
        flag = true;
        cout << "\n�������봴����Ⱥ�ţ�" << endl;
        cin >> num;
        for (int i = 0; i < database.size(); i++) {
            if (num == database[i].getGroupNum()) {
                cout << "\n��Ⱥ���ѱ�ע�ᣡ" << endl;
                flag = false;
            }
        }
    }
    if (flag) {
        setNewGroup(num);
        CLS;
        cout << "�Ѵ���Ⱥ" << num << endl;
    }
}

int QQDatabase::QQmain() {
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
        CLS;
        return choose;
    }
    else {
        CLS;
        cout << "\n\t\t����:���������������������룡\n" << endl;
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
        cout << "\n\n\n------------QQ�˺���Ϣ�б�-----------" << endl;
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

int QQDatabase::QQclient(int ID,WeblogDatabase BD,WeChatDatabase WD) {
    bool flag = false;
    int choose;
    int result = 10;
    for (int i = 0; i < database.size(); i++) {      //���Ҳ���ʾQQ�˺���Ϣ
        if (database[i].getID() == ID) {
            cout << "\n\n\n------------�ʺ���Ϣ-----------" << endl;
            database[i].showInfo();
            choose = QQUI();

            switch (choose) {

            case 1: {         //�����ǳ�
                CLS;
                cout << "\t���������֮����ǳƣ�";
                string name;
                cin >> name;
                database[i].setName(name);
                QQclient(ID, BD, WD);
                break;
            }

            case 2: {         //��Ӻ���
                CLS;
                cout << "\t��������Ҫ��ӵ�QQ�����ʺţ�";
                int account;
                cin >> account;
                database[i].addFriend(account);
                break;
            }

            case 3: {             //�ȽϹ�ͬ����
                CLS;
                cout << "\t����������Ҫ�ȽϹ�ͬ���ѵ�QQ�ʺţ�";
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
                    cout << "\n�������QQ�ʺŲ�δ�ڱ�ϵͳ��ע�����������ʵ�������룡" << endl;
                    QQclient(ID, BD, WD);
                }
                break;
            }

            case 4: {         //ɾ������
                CLS;
                cout << "\n��������Ҫɾ���ĺ��ѵ�QQ�ʺţ�";
                int account;
                cin >> account;
                database[i].deleteFriend(account);
                QQclient(ID, BD, WD);
                break;
            }

            case 5: {             //��Ⱥ
                CLS;
                cout << "\t��������������Ⱥ��Ⱥ�ţ�";
                int groupNumber;
                cin >> groupNumber;
                database[i].enterGroup(groupNumber);
                QQclient(ID, BD, WD);
                break;
            }

            case 6: {             //��Ⱥ
                CLS;
                cout << "\t��������Ҫ�˳���Ⱥ�ţ�";
                int groupNumber;
                cin >> groupNumber;
                database[i].exitGroup(groupNumber);
                QQclient(ID, BD, WD);
                break;
            }

            case 7: {             //��ͨ΢��
                bool flag = false;
                if (database[i].ifSetWebolg())
                    cout << "\n���ʺ��Ѿ���ͨ��΢���ˣ�" << endl;
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
                    cout << "\n��ϲ���Ѿ��ɹ���ͨ΢���ˣ�" << endl;
                }
                QQclient(ID, BD, WD);
                break;
            }

            case 8: {             //��ͨ΢��
                CLS;
                cout << "\n��������Ҫ�󶨵�΢���ʺţ�";
                int account;
                cin >> account;
                database[i].linkToWechat(account);
                cout << "\n��ϲ�����˺Ű󶨳ɹ���" << endl;
                QQclient(ID, BD, WD);
                break;
            }

            case 0: {             //������һ��
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
        cout << "\t���޴��ˣ���ȷ������QQ�ʺ��Ƿ���д��ȷ��" << endl;
        QQclient(ID,BD, WD);
    }

    return result;
}


int QQDatabase::QQUI() {
    int choose = 0;

    cout << "\n\n\n------------QQ�ʺŷ���ϵͳ-----------" << endl;
    cout << "\n1:<�޸��ǳ�>" << endl;
    cout << "\n2:<��Ӻ���>" << endl;
    cout << "\n3:<�Ƚ������˵Ĺ�ͬ����>" << endl;
    cout << "\n4:<ɾ������>" << endl;
    cout << "\n5:<����һ��Ⱥ>" << endl;
    cout << "\n6:<�˳�һ��Ⱥ>" << endl;
    cout << "\n7:<��΢��>" << endl;
    cout << "\n8:<��΢��>" << endl;
    cout << "\n0:<������һ��>" << endl;
    cout << "\nע:���������ֵĴ�����������Ч�����������Ϊ�Ƿ����룡\n\n" << endl;
    cout << "\n����������ѡ��";
    cin >> choose;
    if (choose >= 0 && choose <= 8) {
        CLS;
        return choose;
    }
    else {
        CLS;
        cout << "\n����:���������������������룡\n" << endl;
        QQUI();
    }
}


int WeblogDatabase::weblogmain() {
    int choose = 0;

    cout << "\n\n\n\t\t------------΢���˺��ۺϹ���ϵͳ-----------" << endl;
    cout << "\n\t\t\t\t1:<΢���˺ŵ�½>" << endl;
    cout << "\n\t\t\t\t2:<�鿴������ע���΢���˺�>" << endl;
    cout << "\n\t\t\t\t0:<������һ��>" << endl;
    cout << "\n\t\tע:���������ֵĴ�����������Ч�����������Ϊ�Ƿ����룡\n\n" << endl;
    cout << "\t\t\t����������ѡ��";
    cin >> choose;
    if (choose >= 0 && choose <= 2) {
        CLS;
        return choose;
    }
    else {
        CLS;
        cout << "\n\t\t����:���������������������룡\n" << endl;
        weblogmain();
    }
}

int WeblogDatabase::weblogUI() {
    int choose = 0;

    cout << "\n\n\n------------΢���ʺŷ���ϵͳ-----------" << endl;
    cout << "\n1:<�޸��ǳ�>" << endl;
    cout << "\n2:<��Ӻ���>" << endl;
    cout << "\n3:<ɾ������>" << endl;
    cout << "\n4:<�Ƚ������˵Ĺ�ͬ����>" << endl;
    cout << "\n0:<������һ��>" << endl;
    cout << "\nע:���������ֵĴ�����������Ч�����������Ϊ�Ƿ����룡\n\n" << endl;
    cout << "\n����������ѡ��";
    cin >> choose;
    if (choose >= 0 && choose <= 4) {
        CLS;
        return choose;
    }
    else {
        CLS;
        cout << "\n\t\t����:���������������������룡\n" << endl;
        weblogUI();
    }
}

int WeblogDatabase::weblogService() {
    int choose;
    int result = 10;

    choose = weblogmain();

    switch (choose) {

    case 1: {                //��½
        //CLS;
        //cout << "\t����������΢���˺�:" << endl;
        //int account;
        //cin >> account;
        //int temp = serviceWeibo(account);
        //if (temp == 10)
        //    selectWeibo();
        login();
        break;
    }

    case 2: {             //��ʾ���г�Ա��Ϣ
        CLS;
        cout << "\n\n\n------------΢���û���Ա�б�-----------" << endl;
        for (int i = 0; i < database.size(); i++)
            cout << "\n" << database[i].getID() << ":" << database[i].getName() << endl;
        weblogService();
        break;
    }

    case 0: {             //������һ��
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
        if (database[i].getID() == ID) {       //���Ҳ���ʾ���˺���Ϣ
            cout << "\n\n\n\t\t------------�ʺ���Ϣ-----------" << endl;
            database[i].showInfo();
            choose = weblogUI();
            switch (choose) {

            case 1: {             //�޸��ǳ�
                CLS;
                cout << "\t���������֮����ǳƣ�";
                string name;
                cin >> name;
                database[i].setName(name);
                weblogClient(ID);
                break;
            }

            case 2: {             //��Ӻ���
                CLS;
                cout << "\t����������Ҫ��ӵĺ��ѵ�΢���ʺţ�";
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
                    cout << "\t���û���û���ڱ�ϵͳע�ᣬ������ʵ������Ϣ��" << endl;
                weblogClient(ID);
                break;
            }

            case 3: {             //ɾ������
                CLS;
                cout << "\t��������Ҫɾ���ĺ��ѵ�΢���ʺţ�";
                int account;
                cin >> account;
                database[i].deleteFriend(account);
                weblogClient(ID);
            }

            case 4: {             //�ȽϹ�ͬ����
                CLS;
                cout << "\t����������Ҫ�ȽϹ�ͬ���ѵ�΢���ʺţ�";
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
                    cout << "\t���ʺŲ�û���ڱ�ϵͳ��ע��������ʵ������Ϣ��" << endl;
                weblogClient(ID);
            }

            case 0: {             //������һ��
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
        cout << "\t���޴��ˣ���ȷ������΢���ʺ��Ƿ���д��ȷ��" << endl;
        weblogService();
    }

    return result;
}

int WeChatDatabase::wechatmain() {
    int choose = 0;

    cout << "\n\n\n-----------΢���˺��ۺϹ���ϵͳ-----------" << endl;
    cout << "\n1:<΢���˺ŵ�½>" << endl;
    cout << "\n2:<�鿴������ע���΢���˺�>" << endl;
    cout << "\n3:<ע���������Լ���΢���˺�>" << endl;
    cout << "\n0:<������һ��>" << endl;
    cout << "\nע:���������ֵĴ�����������Ч�����������Ϊ�Ƿ����룡\n\n" << endl;
    cout << "����������ѡ��";
    cin >> choose;
    if (choose >= 0 && choose <= 3) {
        CLS;
        return choose;
    }
    else {
        CLS;
        cout << "\n\t\t����:���������������������룡\n" << endl;
        wechatmain();
    }
}

int WeChatDatabase::wechatService(QQDatabase QD) {
    int choose;
    int result = 10;
    choose = wechatmain();

    switch (choose) {
    case 1: {            //��½
        /*CLS;
        cout << "����������΢���˺ţ�";
        string account;
        cin >> account;
        int temp;
        temp = serviceWeixin(account);
        if (temp == 10)
            selectWeixin();*/
        login();
        break;
    }

    case 2: {                 //��ʾ����΢���û�
        CLS;
        cout << "\n\n\n-----------΢���˺���Ϣ�б�-----------" << endl;
        for (int i = 0; i < database.size(); i++)
            cout << database[i].getID() << ":" << database[i].getName() << endl;
        wechatService(QD);
        break;
    }

    case 3: {        //ע��΢��
        CLS;
        string number;
        string name;
        int qqNumber;
        bool flag = false;

        cout << "\n\n\n\t\t------------��л��ע��΢���˺�-----------" << endl;
   /*     while (!flag)
        {
            flag = true;
            cout << "\t��������ϲ����΢���˺ţ�";
            cin >> number;
            for (int i = 0; i < client.size(); i++) {
                if (client[i].getWeixinAccount() == number) {
                    cout << "\t�ܱ�Ǹ�������˺��Ѿ�����������ע���ˣ���һ���ɣ�" << endl;
                    flag = false;
                    break;
                }
            }
        }

        cout << "\t�����������ǳƣ�";
        cin >> name;
        cout << "\t�������Ƿ�Ҫ��������QQ�˺ţ�Y/N" << endl;
        char chooseQQ;
        cin >> chooseQQ;
        if (chooseQQ == 'Y' || chooseQQ == 'y') {
            cout << "\t��������Ҫ�󶨵�QQ�˺ţ�";
            cin >> qqNumber;
        }
        else
            qqNumber = -1;

        setNewWeixinAccount(number, name, qqNumber);
        CLS;
        cout << "\t��ϲ�����˺�Ϊ" << number << "��΢���˺��Ѿ��ɹ�������" << endl;
        selectWeixin();*/
        signup(QD);
        break;
    }

    case 0: {        //������һ��
        CLS;
        result = mainUI();
        break;
    }
    };

    return result;
}

int WeChatDatabase::wechatUI() {
    int choose = 0;

    cout << "\n\n\n------------΢���ʺŷ���ϵͳ-----------" << endl;
    cout << "\n1:<�޸��ǳ�>" << endl;
    cout << "\n2:<��Ӻ���>" << endl;
    cout << "\n3:<ɾ������>" << endl;
    cout << "\n4:<�Ƚ������˵Ĺ�ͬ����>" << endl;
    cout << "\n5:<��QQ��>" << endl;
    cout << "\n0:<������һ��>" << endl;
    cout << "\nע:���������ֵĴ�����������Ч�����������Ϊ�Ƿ����룡\n\n" << endl;
    cout << "����������ѡ��";
    cin >> choose;
    if (choose >= 0 && choose <= 5) {
        CLS;
        return choose;
    }
    else {
        CLS;
        cout << "\n\t\t����:���������������������룡\n" << endl;
        wechatUI();
    }
}

int WeChatDatabase::wechatClient(int ID) {
    bool flag;
    int choose;
    int result = 10;
    for (int i = 0; i < database.size(); i++) {      //���Ҳ���ʾ΢���û�������Ϣ
        if (database[i].getID() == ID) {
            cout << "\n\n\n\t\t------------�ʺ���Ϣ-----------" << endl;
            database[i].showInfo();
            choose = wechatUI();

            switch (choose) {
            case 1: {                     //�޸��ǳ�
                CLS;
                cout << "\t���������֮����ǳƣ�";
                string name;
                cin >> name;
                database[i].setName(name);
                wechatClient(ID);
                break;
            }

            case 2: {                 //��Ӻ���
                CLS;
                cout << "\t��������Ҫ��ӵĺ��ѵ�΢���ʺţ�";
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
                    cout << "\t���û���û���ڱ�ϵͳע�ᣬ������ʵ������Ϣ��" << endl;
                wechatClient(ID);
                break;
            }

            case 3: {                     //ɾ������
                CLS;
                cout << "\t��������Ҫɾ����΢�ź��ѵ��ʺţ�";
                int account;
                cin >> account;
                database[i].deleteFriend(account);
                wechatClient(ID);
                break;
            }

            case 4: {             //�ȽϹ�ͬ����
                CLS;
                cout << "\t����������Ҫ�ȽϹ�ͬ���ѵ�΢���ʺţ�";
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
                    cout << "\t������΢���ʺŲ�û���ڱ�ϵͳ��ע��������ʵ������Ϣ!" << endl;

                wechatClient(ID);
            }

            case 5: {                 //��QQ����
                CLS;
                cout << "\n����������Ҫ�󶨵�QQ�ʺţ�";
                int account;         //�����������QQ�ŵ���ȷ�Ե��жϾͻ�������⣬ԭ����QQ�˺Ź�����������
                cin >> account;
                database[i].setqqID(account);
                cout << "\n��ϲ����QQ�ʺŰ󶨳ɹ���" << endl;

                wechatClient(ID);
                break;
            }

            case 0: {                 //������һ��
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
    //    cout << "\t��ȷ������΢���ʺ��Ƿ���д��ȷ��" << endl;
    //    wechatService(QD);
    //}
    return result;
}