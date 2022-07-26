#ifndef DZ_FRACTION_H
#define DZ_FRACTION_H

#include <iostream>
#include <cstring>

using std::ostream;
using std::istream;

class Fraction {
    int numerator;
    int denominator;
public:
    Fraction(const int num, const int den){
        setDenominator(den);    // дробь со знаменателем = 0 не имеет смысла
        if(num == 0){
            numerator = denominator = 0;
        } else {
            setNumerator(num);
        }
    }
    Fraction() : Fraction(1,1){}

    Fraction(const Fraction& frac): numerator(frac.numerator), denominator(frac.denominator){}

    int getNumerator() const   {  return numerator;}
    int getDenominator() const {  return denominator;}

    void setNumerator(int);
    void setDenominator(int);

    bool isContractible() const;  // проверка на сократимость дроби
    bool shorten();         // сократить дробь

    char *toString() const;
    friend ostream &operator << (ostream&, const Fraction&);
    friend istream &operator >> (istream&, Fraction&);

    friend Fraction operator + (const Fraction&, const Fraction&);
    void operator += (const Fraction&);

    friend Fraction operator - (const Fraction&, const Fraction&);
    void operator -= (const Fraction&);

    friend Fraction operator * (const Fraction&, const Fraction&);
    void operator *= (const Fraction&);

    friend Fraction operator / (const Fraction&, const Fraction&);
    void operator /= (const Fraction&);

    bool operator == (const Fraction&);
    Fraction operator = (const Fraction&);
};


#endif //DZ_FRACTION_H
