#include "group.h"
#include <iostream>


Student::Student(int id,string s){
    int i;
    _id=id;
    for(i=0;i<s.size();i++){
        name.push_back(s[i]);
    }
}

void Student::print(){
    int i;
    if(_id=='\0')return;
    cout<<_id<<endl;
    cout<<name<<endl;

}
int Student::getID(){
    return _id;
}
string Student::getName(){
    return name;
}

void Student::clear(){
    _id='\0';
    name='\0';
}
