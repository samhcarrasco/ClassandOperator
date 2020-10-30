#include <iostream>
#include <cstdlib>
#include <cmath>
#include "CarrascoSamuelMoney.h"
using namespace std;
//contructors setting the default values 
Money::Money() : dollars(0), cents(0) {}
Money::Money(double amount) : dollars(dollarsPart(amount)), cents(centsPart(amount)) {}
Money::Money(int theDollars) : dollars(theDollars), cents(0) {}


// will return a boolean value to determine if the logic proves if the first money object is less than the second money object 
bool operator < (const Money& amount1, const Money& amount2) {
    return ((amount1.dollars < amount2.dollars) ||
        ((amount1.dollars == amount2.dollars) && (amount1.cents < amount2.cents)));
}

// will return a boolean value to determine if the logic proves if the first money object is less than or equal to the second money object 
bool operator <= (const Money& amount1, const Money& amount2) {
    //less than logic
    return ((((amount1.dollars < amount2.dollars) ||
        //equal to logic
        ((amount1.dollars == amount2.dollars) && (amount1.cents < amount2.cents)))) ||
        ((amount1.dollars == amount2.dollars) && (amount1.cents == amount2.cents)));
}
// will return a boolean value to determine if the logic proves if the first money object is greater than the second money object 
bool operator > (const Money& amount1, const Money& amount2) {
    return ((amount1.dollars > amount2.dollars) ||
        ((amount1.dollars == amount2.dollars) && (amount1.cents > amount2.cents)));
}
// will return a boolean value to determine if the logic proves if the first money object is greater than or equal to the second money object 
bool operator >= (const Money& amount1, const Money& amount2) {
    //greater than logic
    return ((((amount1.dollars > amount2.dollars) ||
        //equal to logic
        ((amount1.dollars == amount2.dollars) && (amount1.cents > amount2.cents)))) ||
        ((amount1.dollars == amount2.dollars) && (amount1.cents == amount2.cents)));
}
//logic to check if the objects are equal
bool operator == (const Money& amount1, const Money& amount2) {
    return ((amount1.dollars == amount2.dollars) && (amount1.cents == amount2.cents));
}


//defining the addition operator
const Money operator + (const Money& amount1, const Money& amount2) {
    //adding values for dollars and cents
    int dollarsTotal = amount1.dollars + amount2.dollars;
    int centsTotal = amount1.cents + amount2.cents;
    //logic to take cents over $1 and converting it to dollars while setting cents value to the remaining cents
    if (centsTotal > 100) {
        int remainingCents = centsTotal % 100;
        dollarsTotal += 1;
        centsTotal = remainingCents;
    }
    //evaluating fractional dollar values and converting them into cents 
    if (dollarsTotal < 0) {
        dollarsTotal = -dollarsTotal;
    }
    if (centsTotal < 0) {
        centsTotal = -centsTotal;
    }
    return Money(dollarsTotal, centsTotal);
}

//defining - operator 
const Money operator - (const Money& amount1, const Money& amount2) {
    //convert dollars to cents for easy math
    int cents1 = amount1.dollars * 100 + amount1.cents;
    int cents2 = amount2.dollars * 100 + amount2.cents;
    //subtract cents 
    int cents = cents1 - cents2;
    //turn cents to proper money notation
    int finalDollars = cents / 100;
    int finalCents = cents % 100;
    //if there is negative value for cents after math then the result will subtract from dollar amount to have the proper conversion
    if (cents < 0) {
        finalDollars = -finalDollars;
        finalCents = -finalCents;
    }
    return Money(finalDollars, finalCents);
}



//evaluates input to check if proper positive value has been inserted
ostream& operator << (ostream& outputStream, const Money& amount) {
    int absDollars = abs(amount.dollars);
    int absCents = abs(amount.cents);
    if (amount.dollars < 0 || amount.cents < 0) {
        outputStream << "$-";
    }
    else {
        outputStream << '$';
        outputStream << absDollars;
    }
    if (absCents >= 10) {
        outputStream << '.' << absCents;
    }
    else {
        outputStream << '.' << '0' << absCents;
    }
    return outputStream;
}
//check for proper input with formatting ($)
istream& operator >> (istream& inputStream, Money& amount) {
    char dollarSign;
    inputStream >> dollarSign;
    if (dollarSign != '$') {
        cout << "No dollar sign in Money input" << endl;
        //exit(1);
    }
    double amountAsDouble;
    inputStream >> amountAsDouble;
    amount.dollars = amount.dollarsPart(amountAsDouble);
    amount.cents = amount.centsPart(amountAsDouble);
    return inputStream;
}