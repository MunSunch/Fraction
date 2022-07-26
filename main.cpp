#include <iostream>
#include "Fraction.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "rus");


    Fraction f1(3,12);
    Fraction f2(1,6);
    cout << "f1 = " << f1 << endl;
    cout << "f2 = " << f2 << endl;

    Fraction f3 = f1+f2;
    cout << "f1 + f2 = " << f3 << endl;

    Fraction f4 = f1-f2;
    cout << "f1 - f2 = " << f4 << endl;

    Fraction f5 = f1*f2;
    cout << "f1 * f2 = " << f5 << endl;

    Fraction f6 = f1/f2;
    cout << "f1 / f2 = " << f6 << endl;

    cout << "f1/f2 сократима? " << boolalpha << f6.isContractible() << endl;
    f6.shorten();
    cout << "f1 / f2 = " << f6 << endl;
    cout << "f1/f2 сократима? " << boolalpha << f6.isContractible() << endl;

    Fraction f7(f6);
    cout << "Copy f6 = " << f7 << endl;

    Fraction f8(0, 2);
    cout << "Numerator is 0:" << f8 << endl;
    Fraction f9(12, 0);
    cout << "Denominator is 0:" << f9 << endl;

    return 0;
}
