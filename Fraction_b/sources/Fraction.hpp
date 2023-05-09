#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>

using namespace std;
namespace ariel{}
#ifndef GAME_H
#define GAME_H


class  Fraction {
    int numerator;
    int denominator;
private:

    void negtive();

    void reduced();
public:
    double to_double()const;
    Fraction(int numa,int numb);
    Fraction(double numb);
    Fraction();

    int getNumerator();
    int getDenominator();

    friend Fraction& operator++(Fraction &frca);
    friend const Fraction operator++(Fraction &frcb,int numa);

    friend Fraction& operator--(Fraction& frca);
    friend const Fraction operator--(Fraction &frcb,int numa);



    friend const Fraction operator+(const Fraction & frca,const Fraction & frcb);
    friend const Fraction operator*(const Fraction & frca,const Fraction  & frcb);
    friend const Fraction operator-(const Fraction & frca,const Fraction & frcb);
    friend const Fraction operator/(const Fraction & frca,const Fraction & frcb);


    friend istream &operator>>(istream  &input,Fraction &frcb);
    friend ostream &operator<<(ostream &output,const Fraction &frcb);


    friend const bool operator<(const Fraction & frca,const  Fraction  & frcb);
    friend const bool operator<=(const Fraction & frca,const Fraction & frcb);
    friend const bool operator>(const Fraction & frca,const Fraction & frcb);
    friend const bool operator>=(const Fraction & frca,const Fraction & frcb);
    friend const bool operator==(const Fraction & frca,const Fraction & frcb);

    };
#endif
make