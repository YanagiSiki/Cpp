#include "group.h"

    TEST(insert_delete){
        Student a(102590021,"siki");//�إ߾ǥ͸��
        Student b(111111111,"kami");
        Student c(123456789,"OwO");

        Group kon(001,a,1995,10,10,"K-on");//�إߪ��θ��
        Group rokyubu(002,a,2014,10,25,"rokyubu");

        kon.insert(b);//�ǥͥ[�J����
        kon.insert(c);

        cout<<"��X��Ӫ��Ϊ����"<<endl;
        kon.print();//�L�X���θ��
        rokyubu.print();


        cout<<"��X���G���T��?(y or n)"<<endl;
        char ans;
        cin>>ans;
        CHECK_EQUAL(ans,'y');
        cout<<"--------------------------�ڬO���j�u--------------------------"<<endl;

        kon.del(c);//�ǥͰh�X����
        cout<<"�ǥ�c�h�Xkon"<<endl;
        kon.print();//�L�X���θ��
        rokyubu.print();
        cout<<"��X���G���T��?(y or n)"<<endl;
        cin>>ans;
        CHECK_EQUAL(ans,'y');


        cout<<"--------------------------�ڬO���j�u--------------------------"<<endl;
        cout<<"---------------����@�ӾǥͬO�_��Ӫ��γ��ѥ[-----------------"<<endl;
        if(kon.search(a)==1 && rokyubu.search(a)==1){//�P�_�ǥ�a�O�_��Ӫ��γ��ѥ[
            cout<<a.getName()<<" is in two groups."<<endl;
        }
        if(kon.search(b)==1 && rokyubu.search(b)==1){//�P�_�ǥ�b�O�_��Ӫ��γ��ѥ[
            cout<<b.getName()<<" is in two groups."<<endl;
        }

        cout<<"��X���G���T��?(y or n)"<<endl;
        cin>>ans;
        CHECK_EQUAL(ans,'y');

        cout<<"--------------------------�ڬO���j�u--------------------------"<<endl;
        cout<<"--------------����@�ӾǥͬO�_�ܤְѥ[�@�Ӫ���----------------"<<endl;

        if(kon.search(a)==1 || rokyubu.search(a)==1){//�P�_�ǥ�a�O�_�ܤְѥ[�@�Ӫ���
            cout<<a.getName()<<" at least one goup"<<endl;
        }
        if(kon.search(b)==1 || rokyubu.search(b)==1){//�P�_�ǥ�b�O�_�ܤְѥ[�@�Ӫ���
            cout<<b.getName()<<" at least one goup"<<endl;
        }

        cout<<"��X���G���T��?(y or n)"<<endl;
        cin>>ans;
        CHECK_EQUAL(ans,'y');

        cout<<"--------------------------�ڬO���j�u--------------------------"<<endl;
        cout<<"--------------����@�Ӫ��άO�_���t�@�Ӫ��l���X----------------"<<endl;


        if(kon.compare(rokyubu)==1)cout<<"kon is a subset of rokyubu."<<endl; //�P�_kon�O�_��rokyubu���l���X
        else cout<<"kon isn't a subset of rokyubu."<<endl;

        if(rokyubu.compare(kon)==1)cout<<"rokyubu is a subset of kon."<<endl; //�P�_kon�O�_��rokyubu���l���X
        else cout<<"rokyubu isn't a subset of kon."<<endl;

        cout<<"��X���G���T��?(y or n)"<<endl;
        cin>>ans;
        CHECK_EQUAL(ans,'y');

    }

    TEST(HW5_operator){
        char ans;
        cout<<"--------------����HW5----------------"<<endl;
        Student a(102590021,"siki");//�إ߾ǥ͸��
        Student b(111111111,"kami");
        Student c(123456789,"OwO");


        Group kon(001,a,1995,10,10,"K-on");//�إߪ��θ��
        Group rokyubu(002,a,2014,10,25,"rokyubu");
        kon.insert(c);

        kon.insert(b);//�ǥͥ[�J����
        cout<<"��X��Ӫ��Ϊ����"<<endl;
        kon.print();//�L�X���θ��
        rokyubu.print();
        cout<<"��X���G���T��?(y or n)"<<endl;
        cin>>ans;
        CHECK_EQUAL(ans,'y');
        cout<<"--------------------------�ڬO���j�u--------------------------"<<endl;
        cout<<"--------------------------�涰--------------------------"<<endl;
        rokyubu-kon;//�涰
        kon-rokyubu;
        cout<<"��X���G���T��?(y or n)"<<endl;
        cin>>ans;
        CHECK_EQUAL(ans,'y');
        cout<<"--------------------------�ڬO���j�u--------------------------"<<endl;
        cout<<"--------------------------�p��--------------------------"<<endl;
        kon+rokyubu;//�p��
        rokyubu+kon;
        cout<<"��X���G���T��?(y or n)"<<endl;
        cin>>ans;
        CHECK_EQUAL(ans,'y');
        cout<<"--------------------------�l���X--------------------------"<<endl;
        kon<rokyubu;//�l���X
        rokyubu<kon;
        cout<<"��X���G���T��?(y or n)"<<endl;
        cin>>ans;
        CHECK_EQUAL(ans,'y');
    }
