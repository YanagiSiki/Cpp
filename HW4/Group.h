#include <iostream>
#include <vector>



using namespace std;

class Student {
public:
    Student(int id,string s);
    void print();
    int getID();
    string getName();
    void clear();
private:
    int _id;
    string name;
};


////////////////////////////////////////////////////////////////////////
class Group {
public:
    Group(int id,Student stu,int year,int month,int day,string s);
    void insert(Student stu);
    void del(Student stu);
    void print();
    bool search(Student stu);
    bool compare(Group gro);
private:
    int _id;
    int _year;
    int _month;
    int _day;
    string name;
   vector <Student> member;

};





