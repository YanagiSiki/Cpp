#include "group.h"
#include <iostream>
int main() {

    return UnitTest::RunAllTests();

    Student a(102590021,"siki");//建立學生資料
    Student b(111111111,"kami");
    Student c(123456789,"OwO");


    Group kon(001,a,1995,10,10,"K-on");//建立社團資料
    Group rokyubu(002,a,2014,10,25,"rokyubu");
    kon.insert(c);

    kon.insert(b);//學生加入社團
    kon.print();//印出社團資料
    rokyubu.print();
    cout<<"--------------------------我是分隔線--------------------------"<<endl;
    kon.del(a);//學生退出社團

    kon.print();
    rokyubu.print();
    cout<<"--------------------------我是分隔線--------------------------"<<endl;
    kon.insert(a);//

    if(kon.search(a)==1 && rokyubu.search(a)==1){//判斷學生a是否兩個社團都參加
        cout<<a.getName()<<" is in two groups."<<endl;
    }
    if(kon.search(b)==1 && rokyubu.search(b)==1){//判斷學生b是否兩個社團都參加
        cout<<b.getName()<<" is in two groups."<<endl;
    }
    cout<<"--------------------------我是分隔線--------------------------"<<endl;


    if(kon.search(a)==1 || rokyubu.search(a)==1){//判斷學生a是否至少參加一個社團
        cout<<a.getName()<<" at least one goup"<<endl;
    }
    if(kon.search(b)==1 || rokyubu.search(b)==1){//判斷學生b是否至少參加一個社團
        cout<<b.getName()<<" at least one goup"<<endl;
    }

    cout<<"--------------------------我是分隔線--------------------------"<<endl;

    kon.print();
    rokyubu.print();
    if(kon.compare(rokyubu)==1)cout<<"kon is a subset of rokyubu."<<endl; //判斷kon是否為rokyubu的子集合
    else cout<<"kon isn't a subset of rokyubu."<<endl;

    if(rokyubu.compare(kon)==1)cout<<"rokyubu is a subset of kon."<<endl; //判斷kon是否為rokyubu的子集合
    else cout<<"rokyubu isn't a subset of kon."<<endl;
    cout<<"--------------------------我是分隔線--------------------------"<<endl;


    cout<<"--------------------------以下為作業5--------------------------"<<endl;
    rokyubu-kon;//交集
    kon-rokyubu;
    cout<<"--------------------------我是分隔線--------------------------"<<endl;
    kon+rokyubu;//聯集
    rokyubu+kon;
    cout<<"--------------------------我是分隔線--------------------------"<<endl;
    kon<rokyubu;//子集合
    rokyubu<kon;
    return 0;
}

