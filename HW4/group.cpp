#include "group.h"
#include <iostream>

Group:: Group(int id,Student stu,int year,int month,int day,string s){
    _id=id;
    _year=year;
    _month=month;
    _day=day;
    int i,j;
    for(i=0;i<s.size();i++){
        name.push_back(s[i]);
    }
    member.push_back(stu);


}


void Group::print(){
    int i;
    cout<<_id<<endl;
    cout<<name<<endl;
    cout<<_year<<'/'<<_month<<'/'<<_day<<endl;
    //cout<<member.size()<<endl;
    for(i=0;i<member.size();i++){
        member[i].print();
    }
}

void Group::insert(Student stu){
    member.push_back(stu);
}

void Group::del(Student stu){
    int i;
    for(i=0;i<member.size();i++){
        if(member[i].getID()==stu.getID() ){
            member[i].clear();
            break;
        }
    }
}

bool Group::search(Student stu){
    int i;

    for(i=0;i<member.size();i++){
        if(member[i].getID()==stu.getID() ){
           return 1;
        }
    }
    return 0;
}

bool Group::compare(Group gro){
    int i,j,count=0;
    for(i=0;i<member.size();i++){
        for(j=0;j<gro.member.size();j++){
            if(member[i].getID()==gro.member[j].getID())count++;
        }
    }
    if(count==member.size())return 1;
    return 0;

}
