#include <iostream>

using namespace std;

class Rational {
public:
    Rational(int num=0, int den=1); //�Yconstructor
    Rational operator + (const Rational & r);
    Rational operator - (const Rational & r);
    Rational operator * (const Rational & r);
    Rational operator / (const Rational & r);
    void print(string s);
private:
    int _num;
    int _den;
    //int gcd(int x, int y);
};
