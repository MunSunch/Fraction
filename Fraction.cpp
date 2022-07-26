#include "Fraction.h"
#include "MyAlgorithm.h"

Fraction operator + (const Fraction& frac1, const Fraction& frac2){
    //  a/b + c/d = (a*lcm/b + c*lcm/d)/lcm(b*d)
    int new_denominator = lcm(frac1.denominator, frac2.denominator);
    int new_numerator = frac1.numerator*new_denominator/frac1.denominator
            + frac2.numerator*new_denominator/frac2.denominator;
    return Fraction(new_numerator, new_denominator);
}

void Fraction::operator += (const Fraction& frac){
    int new_denominator = lcm(denominator, frac.denominator);
    numerator = numerator*new_denominator/denominator + frac.numerator*new_denominator/frac.denominator;
    denominator = new_denominator;
}


Fraction operator - (const Fraction& frac1, const Fraction& frac2){
    int new_denominator = lcm(frac1.denominator, frac2.denominator);
    int new_numerator = frac1.numerator*new_denominator/frac1.denominator -
            frac2.numerator*new_denominator/frac2.denominator;
    return Fraction(new_numerator, new_denominator);
}
void Fraction::operator -= (const Fraction& frac){
    int new_denominator = lcm(denominator, frac.denominator);
    numerator = numerator*new_denominator/denominator - frac.numerator*new_denominator/frac.denominator;
    denominator = new_denominator;
}


Fraction operator * (const Fraction& frac1, const Fraction& frac2){
    return Fraction(frac1.numerator*frac2.numerator, frac1.denominator*frac2.denominator);
}
void Fraction::operator *= (const Fraction& frac){
    this->numerator *= frac.numerator;
    this->denominator *= frac.denominator;
}

Fraction operator / (const Fraction& frac1, const Fraction& frac2){
    return Fraction(frac1.numerator*frac2.denominator, frac1.denominator*frac2.numerator);
}

void Fraction::operator /= (const Fraction& frac){
    this->numerator /= frac.numerator;
    this->denominator /= frac.denominator;
}


bool Fraction::operator == (const Fraction& frac){
    double res_1 = (double)numerator/denominator;
    double res_2 = (double)frac.numerator/frac.denominator;
    return res_1 == res_2;
}

Fraction Fraction::operator = (const Fraction& fraction)
{
    if(*this == fraction){
        return *this;
    }
    this->numerator = fraction.numerator;
    this->denominator = fraction.denominator;
}


bool Fraction::isContractible() const
{
    return gcd(numerator, denominator)>1;
}

bool Fraction::shorten(){
    if(this->isContractible()){
        int div = gcd(numerator, denominator);
        numerator /= div;
        denominator /= div;
    }
    return false;
}

char *Fraction::toString() const
{
    const int BUF_SIZE = 256;
    const char *sep = "/";
    char *out = new char[BUF_SIZE];
    strcpy(out, "");

    char buf[BUF_SIZE];
    sprintf(buf, "%d", numerator);
    strcat(out, buf);
    strcat(out, sep);

    sprintf(buf, "%d", denominator);
    strcat(out, buf);

    return out;
}

ostream &operator << (ostream &stream, const Fraction& fraction)
{
    return stream << fraction.toString();
}

istream &operator >> (istream& stream, Fraction& fraction)
{
    std::cout << "Numerator = ";
    stream >> fraction.numerator;
    std::cout << "Denominator = ";
    stream >> fraction.denominator;
    return stream;
}

void Fraction::setNumerator(int numerator) {  this->numerator = numerator;}
void Fraction::setDenominator(int denominator) {
    if(denominator != 0) {
        this->denominator = denominator;
    } else {
        std::cout << "Invalid denominator" << std::endl;
        exit(1);
    }
}









