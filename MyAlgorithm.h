#ifndef DZ_MYALGORITHM_H
#define DZ_MYALGORITHM_H

// Возвращает НОД(a, b)
int gcd(int a, int b){
    if(b==0){
        return a;
    }
    return gcd(b, a%b);
}

// Возавращает НОК(a, b)
int lcm(int a, int b){
    return (a*b)/gcd(a,b);
}


#endif //DZ_MYALGORITHM_H
