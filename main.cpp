#include<iostream>
#include"base.h"

using namespace std;

int main() {
    //�ȴ����������˺ŵ�������
    QQDatabase qq;
    WeblogDatabase weibo;
    WeChatDatabase weixin;
    GroupData group;

    //��������һЩ������Ԥ�ȴ����һЩ���󣬱�֤ϵͳ����һ�����û�����������ʹ��
    /*��ע�����ڳ���ʹ����vector��ʹ���ļ���������л������˲����Ѷȣ��ȽϷ����boost������л�����Ҫ
    ����Boost��⣬�ȽϷ�ʱ�����Բ����˹̻��ڳ�������У���Ȼ����һЩ������ʡȥ�˺ܶ಻��Ҫ���鷳*/

    QQ test1;
    QQ test2;
    QQ test3;

    test1.setID(55160602);
    test2.setID(55160603);
    test3.setID(55160604);

    test1.setName("denghan");
    test2.setName("louruiqi");
    test3.setName("jianghuiyun");

    test1.setBirthDate("1998-01-22");
    test2.setBirthDate("1998-01_01");
    test3.setBirthDate("1998-07-17");

    test1.setAge(1);
    test2.setAge(2);
    test3.setAge(3);

    test1.setLocation("heilongjiang");
    test2.setLocation("changchun");
    test3.setLocation("guangdong");

    test1.linkToWebolg();
    test2.linkToWebolg();
    test3.linkToWebolg();

    test1.linkToWechat(100001);
    test2.linkToWechat(100002);
    test3.linkToWechat(100003);

    test1.addFriend(55160603);
    test1.addFriend(55160604);
    test2.addFriend(55160602);
    test2.addFriend(55160604);
    test3.addFriend(55160602);
    test3.addFriend(55160604);

    test1.enterGroup(1001);
    test1.enterGroup(1002);
    test2.enterGroup(1001);
    test2.enterGroup(1002);
    test3.enterGroup(1001);
    test3.enterGroup(1002);


    qq.database.push_back(test1);
    qq.database.push_back(test2);
    qq.database.push_back(test3);


    Weblog test4(test1);
    Weblog test5(test2);
    Weblog test6(test3);

    test4.addFriend(55160603);
    test4.addFriend(55160604);
    test5.addFriend(55160602);
    test5.addFriend(55160604);
    test6.addFriend(55160602);
    test6.addFriend(55160603);

    weibo.database.push_back(test4);
    weibo.database.push_back(test5);
    weibo.database.push_back(test6);

    WeChat test7(test1);
    WeChat test8(test2);
    WeChat test9(test3);

    test7.setID(10101);
    test8.setID(10102);
    test9.setID(10103);

    test7.setName("denghan");
    test8.setName("louruiqi");
    test9.setName("jianghuiyun");

    test7.addFriend(10102);
    test7.addFriend(10103);
    test8.addFriend(10101);
    test8.addFriend(10103);
    test9.addFriend(10101);
    test9.addFriend(10102);

    weixin.database.push_back(test7);
    weixin.database.push_back(test8);
    weixin.database.push_back(test9);

    /*Group test10;
    Group test11;


    test10.setGroupNumber(001);
    test11.setGroupNumber(002);

    test10.addMember(55160602);
    test10.addMember(55160603);
    test10.addMember(55160604);
    test11.addMember(55160602);
    test11.addMember(55160603);
    test11.addMember(55160604);

    group.client.push_back(test10);
    group.client.push_back(test11);*/

    //���������û����˽���

    int choose;
    int result = 10;
    while (result != 0) {         //ѭ����ʹ������ֻ���ڹرճ���ʱ�˳�
        choose = mainUI();

        switch (choose) {

        case 1: {                 //QQ�˺Ź�����
            CLS;
            result = qq.QQservice(weibo, weixin);
            break;
        }

        case 2: {                 //΢���˺Ź�����
            CLS;
            result = weibo.weblogService();
            break;
        }

        case 3: {                //΢���˺Ź�����
            CLS;
            result = weixin.wechatService(qq);
            break;
        }

        //case 4: {                 //Ⱥ�������
        //    CLS;
        //    result = group.selectGroup(qq);
        //}

        case 0: {
            CLS;
            cout << "\t��л��ʹ�ñ�ϵͳ���ڴ�������һ��ʹ�ã�\n\t���������ɵ������˺���Ϣ��������˸�Ŀ¼�µĶ�ӦTXT�ļ��У�" << endl;
            //�����Ǹ����˻���Ϣ���ļ�����
            //qq.writeToFile();
            //weibo.writeToFile();
            //weixin.writeToFile();
            //group.writeToFile();
            exit(0);
        }
        };
    }
    return 0;
}