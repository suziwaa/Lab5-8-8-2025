#include <iostream>
#include "PrimeFactor.h"

using namespace std;

int main() {
    int number;

    cout << "Enter an integer to factor: ";
    cin >> number;

    if (number <= 1) {
        cout << "Please enter an integer greater than 1." << endl;
        return 1;
    }

    vector<int> primeFactors = getPrimeFactors(number);

    cout << "Prime factors of " << number << ": ";
    for (int factor : primeFactors) {
        cout << factor << " ";
    }
    cout << endl;

    return 0;
}
