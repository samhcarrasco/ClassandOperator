#pragma once

#ifndef MONEY_H

#define MONEY_H

using namespace std;



//create the money class
class Money
{

    //all of the public member functions will be used to manipulate the private member variables
public:

    //we are initializing all of the public member functions
    Money();
    Money(double amount);
    Money(int theDollars, int theCents) {
        dollars = theDollars;
        cents = theCents;
    }
    Money(int theDollars);
    double getAmount() const {
        return dollars + cents * .01;
    }
    int getDollars() const {
        return dollars;
    }
    int getCents() {
        return cents;
    }
    //initializaing all of the logic operators
    friend const Money operator + (const Money& amount1, const Money& amount2);
    friend const Money operator - (const Money& amount1, const Money& amount2);
    friend bool operator == (const Money& amount1, const Money& amount2);
    friend const Money operator - (const Money& amount);
    friend ostream& operator << (ostream& outputStream, const Money& amount);
    friend istream& operator >> (istream& inputStream, Money& amount);
    friend bool operator < (const Money& amount1, const Money& amount2);
    friend bool operator <= (const Money& amount1, const Money& amount2);
    friend bool operator > (const Money& amount1, const Money& amount2);
    friend bool operator >= (const Money& amount1, const Money& amount2);
    const Money percent(int percentFigure) const {
        int d = dollars * percentFigure / 100;
        int c = dollars * percentFigure % 100 + cents * percentFigure / 100;
        return Money(d, c);
    }


private:
    //initialize all of the member variables that will not be touched that take in cents and dollars and cantake cents turn them into dollars and apply the remaining for cents
    int dollars, cents;
    int dollarsPart(double amount) const {
        return static_cast<int>(amount);
    }
    int centsPart(double amount) const {
        double cents = amount * 100;
        int intCents = (rounded(fabs(cents))) % 100;
        return intCents;
    }
    int rounded(double number) const {
        return static_cast<int>(floor(number + .5));
    }
};
#endif