/*
#include <iostream>
#include <string>
#include "EaterOf.h"

using namespace std;

int main() {
    EaterOf<int> eaterInt;
    EaterOf<double> eaterDouble;
    EaterOf<string> eaterString;

    // Food for int and double
    int intFoods[] = { 1, 2, 3 };
    double doubleFoods[] = { 1.5, 2.5, 3.5 };
    string stringFoods[] = { "apple", "banana", "carrot" };

    // Feed int eater
    for (auto food : intFoods) {
        eaterInt.eat(food);
    }
    cout << "Int burp: " << eaterInt.burp() << endl;

    // Feed double eater
    for (auto food : doubleFoods) {
        eaterDouble.eat(food);
    }
    cout << "Double burp: " << eaterDouble.burp() << endl;

    // Feed string eater
    for (auto& food : stringFoods) {
        eaterString.eat(food);
    }
    cout << "String burp: " << eaterString.burp() << endl;
 

    return 0;
}
*/