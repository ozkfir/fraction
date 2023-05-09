#include <iostream>
#include "Fraction.hpp"
using namespace std;
#include <bits/stdc++.h>



using std::cout; using std::endl;

void Fraction::negtive(){
    if (this->denominator<0)
    {
        this->numerator*=-1;
        this->denominator*=-1;
    }
}

int Fraction::getNumerator(){
    return this->numerator;
}
int Fraction::getDenominator(){
    return this->denominator;
}
int Gcd(int a, int b)
{
    if (b == 0)
        return ((0 < a) ? a : -a);
    return Gcd(b, a % b);
}




void Fraction::reduced() {
    int i=Gcd(this->numerator,this->denominator);
    this->numerator/=i;
    this->denominator/=i;
    this->negtive();
}


Fraction::Fraction(double b)
{
    int gcd= Gcd((int)(b*1000),1000);
   this->numerator=((int)(b*1000))/gcd;
    this->denominator=1000/gcd;
    this->negtive();
}

Fraction::Fraction()
{
    this->numerator=1;
    this->denominator=1;
}

Fraction::Fraction(int a,int b){
    if(b==0){ throw invalid_argument("Math error: Attempted to divide by Zero\n");}
    this->numerator=a;
    this->denominator=b;
    this->reduced();
}

double Fraction::to_double()const{
    return ((double) this->numerator)/((double) this->denominator);
}
bool maxmin1(int a,int b){
    int t=a*b;
    if((a>0 && b>0)){
        if(a>t/b)
            return false;
    }
    if ((a<0 && b>0)){
        if(b>t/a)
            return false;
    }
    if(a<0 && b<0){
        if(a<t/b)
            return false;
    }
    if ((a>0 && b<0)){
        if(a>t/b)
            return false;
    }
//    if((a>0 && b>0)){
//        if(a>INT_MAX/b)
//            return false;
//    }
//    if ((a<0 && b>0)){
//        if(b>INT_MIN/a)
//            return false;
//    }
//    if(a<0 && b<0){
//        if(a<INT_MAX/b)
//            return false;
//    }
//    if ((a>0 && b<0)){
//        if(a>INT_MIN/b)
//            return false;
//    }
    return true;
}

bool maxmin2(int a,int b){
    if((a>0 && b>0)){
        if(a>INT_MAX-b)
            return false;
    }
    if(a<0 && b<0){
        if(a<INT_MIN-b)
            return false;
    }
    return true;}

    bool maxmin3(int a,int b){
        if((a>0 && b<0)){
            if(a>INT_MAX+b)
                return false;
        }
        if(a<0 && b>0){
            if(a<INT_MIN+b)
                return false;
        }
//int t=a+b;
//        if((a>0 && b>0)){
//        if(a!=t-b)
//            return false;
//    }
//    if(a<0 && b<0){
//        if(a!=t-b)
//            return false;
//    }
    return true;
}
Fraction const operator+(const Fraction & a,const Fraction & b)
{
    bool result3 = maxmin2(a.numerator,b.numerator);
    if(!result3){
        throw overflow_error("overflow_error");
    }
    int gcd= Gcd(b.denominator,a.denominator);

    int numerator=a.numerator*(b.denominator/gcd)+(a.denominator/gcd)* b.numerator;
    int denominator=a.denominator*(b.denominator/gcd);
        Fraction t(numerator,denominator);
        return t;
    }


Fraction const operator*(const Fraction & a,const Fraction & b){
    bool result1 = maxmin1(a.numerator, b.numerator);
    bool result2 = maxmin1(a.denominator,b.denominator);
    if(!(result1 && result2)){
        throw overflow_error("overflow_error");
        }

Fraction t(a.numerator*b.numerator, a.denominator*b.denominator);
    return t;
}

Fraction const operator-(const Fraction & a,const Fraction & b){

    bool result3 = maxmin3(a.numerator,b.numerator);
    if(!result3){
        throw overflow_error("overflow_error");
    }
    int gcd= Gcd(b.denominator,a.denominator);
    int numerator=a.numerator*(b.denominator/gcd)-(a.denominator/gcd)* b.numerator;
    int denominator=a.denominator*(b.denominator/gcd);
    Fraction t(numerator,denominator);
    return t;
}

Fraction const operator/(const Fraction & a,const Fraction & b){
    if (b.numerator==0){throw overflow_error("overflow_error");}
    bool result1 = maxmin1(a.numerator, b.denominator);
    bool result2 = maxmin1(a.denominator,b.numerator);
    if(!(result1 && result2)){
        throw overflow_error("overflow_error");
    }
    Fraction t(a.numerator*b.denominator, a.denominator*b.numerator);
    return t;
}



const Fraction operator++(Fraction& b,int a){
    Fraction t(b.numerator,b.denominator);
    b.numerator+=b.denominator;
    return t;
}

Fraction& operator++(Fraction &b){
    b.numerator+=b.denominator;
    return b;
}

Fraction& operator--(Fraction &b){
    b.numerator-=b.denominator;
    return b;
}

const Fraction operator--(Fraction &b,int a){
    Fraction t(b.numerator,b.denominator);
    b.numerator-=b.denominator;
    return t;
}

istream& operator>>(istream  &cin,Fraction &frc){
   int numerator,denominator;
    if(cin >>numerator){}
    else {(cin.setstate(std::ios::failbit));
        throw runtime_error("Math error: Attempted to divide by Zero\n");}

    if(cin >>denominator){}
    else {(cin.setstate(std::ios::failbit));
        throw runtime_error("Math error: Attempted to divide by Zero\n");}
    if(denominator==0){ throw runtime_error("Math error: Attempted to divide by Zero\n");}
    frc.denominator=denominator;
    frc.numerator=numerator;
    frc.reduced();
    return cin;
}


ostream& operator<<(ostream &output,const Fraction &b) {
    output << ""<<b.numerator << "/" << b.denominator<<"";
    return output;
}

const bool operator==(const Fraction & a,const Fraction & b){
    int gcd_a=Gcd(a.numerator,a.denominator);
    int gcd_b=Gcd(b.numerator,b.denominator);
    return (a.numerator/gcd_a)*(b.denominator/gcd_b)==(b.numerator/gcd_a)*(a.denominator/gcd_b);}
const bool operator>=(const Fraction & a,const Fraction & b){
    int gcd_a=Gcd(a.numerator,a.denominator);
    int gcd_b=Gcd(b.numerator,b.denominator);
    return (a.numerator/gcd_a)*(b.denominator/gcd_b)>=(b.numerator/gcd_a)*(a.denominator/gcd_b);}

const bool operator>(const Fraction & a,const Fraction & b){
    int gcd_a=Gcd(a.numerator,a.denominator);
    int gcd_b=Gcd(b.numerator,b.denominator);
    return (a.numerator/gcd_a)*(b.denominator/gcd_b)>(b.numerator/gcd_a)*(a.denominator/gcd_b);}
const bool operator<=(const Fraction & a,const Fraction & b){
    int gcd_a=Gcd(a.numerator,a.denominator);
    int gcd_b=Gcd(b.numerator,b.denominator);
    return (a.numerator/gcd_a)*(b.denominator/gcd_b)<=(b.numerator/gcd_a)*(a.denominator/gcd_b);}
const bool operator<(const Fraction & a,const Fraction & b){
    int gcd_a=Gcd(a.numerator,a.denominator);
    int gcd_b=Gcd(b.numerator,b.denominator);
    return (a.numerator/gcd_a)*(b.denominator/gcd_b)<(b.numerator/gcd_a)*(a.denominator/gcd_b);}





//    if (a != 0 && b != 0)
//    {
//    long long result1 = a.numerator*b.numerator;
//    long long result2 = a.denominator*b.denominator;
//
//        if(result1>INT_MAX || result1<INT_MIN|| result2>INT_MAX || result2<INT_MIN){






//    long long result1 = a.numerator*b.denominator+a.denominator* b.numerator;
//    long long result2 = a.denominator*b.denominator;
//    long long result3 = a.numerator*b.denominator;
//    long long result4 = a.denominator* b.numerator;
//    long long result5= max(max(result1,result2), max(result3,result4));
//    long long result6=min(min(result1,result2), min(result3,result4));
//    bool result1 = max_min(a.numerator*b.denominator,a.denominator* b.numerator);
//    bool result2 = max_min(a.denominator,b.denominator);
////    bool result4 = maxmin2(a.denominator,b.numerator);
////    if(result5>INT_MAX || result6<INT_MIN) {
////if(!(result1 && result2 && result3 && result4)) {