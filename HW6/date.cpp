#include "Date.h"



const int Date::days[]={0,31,28,31,30,31,30,31,31,30,31,30,31};

Date::Date(int y,int m,int d){
   setDate(y,m,d);
}

Date::Date(const Date & x){
    setDate(x.year,x.month,x.day);

}

Date::Date(char *s){
    year=(s[0]-'0')*1000+(s[1]-'0')*100+(s[2]-'0')*10+(s[3]-'0');
    month=(s[5]-'0')*10+(s[6]-'0');
    day=(s[8]-'0')*10+(s[9]-'0');

}

void Date::setDate(int y,int m,int d){
    year=(y>=1900 && y<=2100)?y:1900;
    month=(m>=1 && m<=12)?m:1;
    if(month==2 && leapYear(year)){
        day=(d>=1 && d<=29)?d:1;
    }
    else day=(d>=1 && d<=days[month])?d:1;
}

Date &Date::operator++(){
    helpIncrement();
    return *this;
}

Date Date::operator++(int){
    Date tmp=*this;
    helpIncrement();
    return tmp;
}

const Date &Date::operator+=(int x){
    int i;
    for(i=0;i<x;i++){
        helpIncrement();
    }
    return *this;
}

bool Date::leapYear(int x){
    if(x%400==0 || (x%100!=0 && x%4==0)){
        return true;
    }
    else return false;

}

int Date::endOfMonth(int x) const{
    if(month==2 &&leapYear(year)){
        return x=29;
    }
    else return days[month];
}

void Date::helpIncrement(){
    if(day!=endOfMonth(day)){
        day++;
    }
    else if(month<12){
        month++;
        day=1;
    }
    else{
        year++;
        month=1;
        day=1;
    }
}

ostream &operator<<(ostream & o, const Date &d){
    static string monthName[13]={"","January","February","March","April","May","June","July","August","Setmpber","October","November","December"};
    o<<monthName[d.month]<<' '<<d.day<<", "<<d.year;
    return o;
}
istream &operator >>(istream & i, Date & d){
    int year,month,day;

    i>>setw(4)>>year;
    i.ignore();
    i>>setw(2)>>month;
    i.ignore();
    i>>setw(2)>>day;

    d.setDate(year,month,day);
    return i;


}

int Date::getDay()const{
    return day;
}
int Date::getMonth()const{
    return month;
}
int Date::getYear()const{
    return year;
}


Date &Date::setYear(int x){
    year=x;
}
Date &Date::setMonth(int x){
    month=x;
}
Date &Date::setDay(int x){
    day=x;
}


bool Date::operator==(const Date &d) const{
    if(year==d.year && month==d.month && day==d.day)return 1;
    return 0;

}

bool Date::operator!=(const Date &d) const{
    if(year!=d.year || month!=d.month || day!=d.day)return 1;
    return 0;

}

bool Date::operator<(const Date &d) const{
    if(year<d.year)return 1;
    else if(year==d.year && month<d.month)return 1;
    else if(month==d.month && day<d.day)return 1;
    else return 0;
}



Date::operator char *() const{
    char *s;
    string str;

    str.push_back((year/1000)+'0');
    str.push_back((year%1000/100)+'0');
    str.push_back((year%100/10)+'0');
    str.push_back((year%10)+'0');
    str.push_back('/');
    str.push_back((month%100/10)+'0');
    str.push_back((month%10)+'0');
    str.push_back('/');
    str.push_back((day%100/10)+'0');
    str.push_back((day%10)+'0');

    s=&str[0];
    //cout<<str<<endl;
    //cout<<s<<endl;
    return s;

}
