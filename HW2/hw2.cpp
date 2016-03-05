#include <iostream>
#include <vector>
#include <string>
#define MAX_SIZE 80

using namespace std;
static const int ROWS=4, COLS=4;

class BigInteger{
private:
    vector <int> digits;
    bool positive;   //正負數，0的正負設為正
    void adding(const vector <int> & ,const vector <int> &, vector <int> &);
    void subing(const vector <int> & ,const vector <int> &, vector <int> &);
    bool max(const vector <int> & ,const vector <int> &);
public:
    BigInteger(string s);
    BigInteger();
    BigInteger(const BigInteger &);
    BigInteger & operator =(const BigInteger &);
    BigInteger operator +(const BigInteger &);
    BigInteger operator -(const BigInteger &);
    BigInteger operator *(const BigInteger &);
    void print();
};

BigInteger::BigInteger(){
    digits.push_back(0);
    positive=true;
}
BigInteger::BigInteger(const BigInteger & x){
    digits=x.digits;
    positive=x.positive;
}
BigInteger::BigInteger(string s){
    int i=0;
    if(s[0]=='-'){
        positive=false;
        for(i=s.size()-1;i>0;i--){
            digits.push_back(s[i]-'0');
        }
    }
    else {
        positive=true;
        for(i=s.size()-1;i>=0;i--){
            digits.push_back(s[i]-'0');
        }
    }
}

void BigInteger::print(){
    int i;
    if(positive==false)cout <<'-';
    for(i=digits.size()-1;i>=0;i--){
        if(digits[digits.size()-1]==0){
            cout << 0 ;
            break;
        }
        cout << digits[i];
    }
    cout <<endl;
}

void BigInteger::adding(const vector <int> & n1,const vector <int> & n2, vector <int> & ans){
    int i=0,carry=0;
    ans.clear();
    for(i=0;i<n2.size();i++){
        ans.push_back((carry+n1[i]+n2[i])%10);
        carry=(carry+n1[i]+n2[i])/10;
    }
    for(;i<n1.size();i++){
        ans.push_back((carry+n1[i])%10);
        carry=(carry+n1[i])/10;
    }
    //cout << carry;
    if(carry==1)ans.push_back(carry);
}

void BigInteger::subing(const vector <int> & n1,const vector <int> & n2, vector <int> & ans){
    ans.clear();
    int i=0,carry=0;
    for(i=0;i<MAX_SIZE;i++){
        if(i>n1.size()-1 || i>n2.size()-1)break;
        ans.push_back((10+n1[i]-n2[i]-carry)%10);
        carry=(ans[i]+n2[i]+carry)/10;
    }
}

bool BigInteger ::max(const vector <int> & n1,const vector <int> & n2){
    int i;
    bool result=0;
    if(n1.size()>n2.size())result=1;
    else if(n1.size()<n2.size())result=0;
    else {
        for(i=n1.size()-1;i>=0;i--){
            if(n1[i]>n2[i]){
                result=1;
                break;
            }
            else if(n1[i]<n2[i]){
                result=0;
                break;
            }
        }

    }
    return result;
}
BigInteger & BigInteger::operator = (const BigInteger & x){
    positive = x.positive;
    digits = x.digits;
    return *this;
}
BigInteger BigInteger::operator +(const BigInteger & x){
    BigInteger Answer;
    if(positive==x.positive){
        Answer.positive=positive;
        if(max(digits,x.digits)==1)adding(digits,x.digits,Answer.digits);
        else adding(x.digits,digits,Answer.digits);
    }
    else{
        if(positive&&max(digits,x.digits))Answer.positive=true;
        else if((!positive)&&(!max(digits,x.digits)))Answer.positive=true;
        else Answer.positive=false;
        if(max(digits,x.digits)==1) subing(digits,x.digits,Answer.digits);
        else subing(x.digits,digits,Answer.digits);

    }
    return Answer;
}


BigInteger BigInteger::operator*(const BigInteger & x){
    BigInteger ans,temp;
    int i,j;
    int carry;
    for(i=0;i<x.digits.size();i++){
        carry = 0;
        temp.digits.clear();
        for(j=0;j<i;j++){
            temp.digits.push_back(0);
        }
        for(j=0;j<digits.size();j++){
            temp.digits.push_back((x.digits[i]*digits[j]+carry) % 10);
            carry = (x.digits[i]*digits[j]+carry) / 10;
        }
        if(carry!=0){
            temp.digits.push_back(carry);
        }
        ans = ans + temp;
    }
    if(positive == x.positive)ans.positive=true;
    else ans.positive=false;
    return ans;
}
BigInteger BigInteger::operator-(const BigInteger & x){
    BigInteger ans(x);
    if(ans.positive==true)ans.positive=false;
    else ans.positive=true;
    return *this + ans;
}





int main() {
    BigInteger a("-1234567890");
    BigInteger b("234567891");
    BigInteger ans1, ans2, ans3, ans4;
    BigInteger c(a), d;
    ans1 = a + b;
    ans2 = a - c;
    ans3 = c - b;
    ans4 = a * b;
    cout<<"a=";     a.print();
    cout<<"b=";     b.print();
    cout<<"c=";     c.print();
    cout<<"d=";     d.print();
    cout<<"a+b=";   ans1.print();
    cout<<"a-c=";   ans2.print();
    cout<<"c-b=";   ans3.print();
    cout<<"a*b=";   ans4.print();

}
