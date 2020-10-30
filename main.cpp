#include <iostream>
#include <cstdlib>
#include <cmath>
#include "CarrascoSamuelMoney.h"
using namespace std;

//resulting screen prints with the final money input values
int main() {
    Money amnt1, amnt2(10, 50);
    cout << "Enter an amount of money: " << endl;
    cin >> amnt1;
    cout << "amount 1 is: " << amnt1 << endl;
    cout << "amount 2 is: " << amnt2 << endl;
    cout << "25% of amount 1 is: " << amnt1.percent(25) << endl;
    cout << "25% of amount 2 is: " << amnt2.percent(25) << endl;

    if (amnt1 == amnt2) {
        cout << "Amounts are equal" << endl;
    }
    else {
        cout << "Amounts are different" << endl;
    }

    Money sum = amnt1 + amnt2;
    cout << "Sum is " << sum << endl;
    Money dif = amnt1 - amnt2;
    cout << "Difference is " << dif << endl;

    if (amnt1 < amnt2) {
        cout << "Amount 1 is less than amount 2" << endl;
    }
    else {
        cout << "Amount 1 is not less than amount 2" << endl;
    }
    if (amnt1 >= amnt2) {
        cout << "Amount 1 is greater than or equal to amount 2" << endl;
    }
    else {
        cout << "Amount 1 is not greater than or equal to amount 2" << endl;
    }

}
