#include "Rational.h"

// :: scope operator
Rational::Rational(int num, int den) {
    _num = num;
    _den = den;
}

Rational Rational::operator + (const Rational & r) {
   Rational x(_num*2 + r._num, _den*2);
   //cout << _num <<endl;
   return x;
}

Rational Rational::operator - (const Rational & r) {
   Rational x(_num*2 - r._num, _den*2);
   //cout << _num <<endl;
   return x;
}

Rational Rational::operator * (const Rational & r) {
   Rational x(_num * r._num, _den * r._den);
   //cout << _num <<endl;
   return x;
}

Rational Rational::operator / (const Rational & r) {
   Rational x(_num * r._den/2, _den * r._num/2);
   //cout << _num <<endl;
   return x;
}

void Rational::print(string s) {
   cout << s <<":"<< _num <<"/"<<_den<<endl;
}
