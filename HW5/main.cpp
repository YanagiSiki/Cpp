#include "group.h"
#include <iostream>
int main() {

    return UnitTest::RunAllTests();

    Student a(102590021,"siki");//�إ߾ǥ͸��
    Student b(111111111,"kami");
    Student c(123456789,"OwO");


    Group kon(001,a,1995,10,10,"K-on");//�إߪ��θ��
    Group rokyubu(002,a,2014,10,25,"rokyubu");
    kon.insert(c);

    kon.insert(b);//�ǥͥ[�J����
    kon.print();//�L�X���θ��
    rokyubu.print();
    cout<<"--------------------------�ڬO���j�u--------------------------"<<endl;
    kon.del(a);//�ǥͰh�X����

    kon.print();
    rokyubu.print();
    cout<<"--------------------------�ڬO���j�u--------------------------"<<endl;
    kon.insert(a);//

    if(kon.search(a)==1 && rokyubu.search(a)==1){//�P�_�ǥ�a�O�_��Ӫ��γ��ѥ[
        cout<<a.getName()<<" is in two groups."<<endl;
    }
    if(kon.search(b)==1 && rokyubu.search(b)==1){//�P�_�ǥ�b�O�_��Ӫ��γ��ѥ[
        cout<<b.getName()<<" is in two groups."<<endl;
    }
    cout<<"--------------------------�ڬO���j�u--------------------------"<<endl;


    if(kon.search(a)==1 || rokyubu.search(a)==1){//�P�_�ǥ�a�O�_�ܤְѥ[�@�Ӫ���
        cout<<a.getName()<<" at least one goup"<<endl;
    }
    if(kon.search(b)==1 || rokyubu.search(b)==1){//�P�_�ǥ�b�O�_�ܤְѥ[�@�Ӫ���
        cout<<b.getName()<<" at least one goup"<<endl;
    }

    cout<<"--------------------------�ڬO���j�u--------------------------"<<endl;

    kon.print();
    rokyubu.print();
    if(kon.compare(rokyubu)==1)cout<<"kon is a subset of rokyubu."<<endl; //�P�_kon�O�_��rokyubu���l���X
    else cout<<"kon isn't a subset of rokyubu."<<endl;

    if(rokyubu.compare(kon)==1)cout<<"rokyubu is a subset of kon."<<endl; //�P�_kon�O�_��rokyubu���l���X
    else cout<<"rokyubu isn't a subset of kon."<<endl;
    cout<<"--------------------------�ڬO���j�u--------------------------"<<endl;


    cout<<"--------------------------�H�U���@�~5--------------------------"<<endl;
    rokyubu-kon;//�涰
    kon-rokyubu;
    cout<<"--------------------------�ڬO���j�u--------------------------"<<endl;
    kon+rokyubu;//�p��
    rokyubu+kon;
    cout<<"--------------------------�ڬO���j�u--------------------------"<<endl;
    kon<rokyubu;//�l���X
    rokyubu<kon;
    return 0;
}

