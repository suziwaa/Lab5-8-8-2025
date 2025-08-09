#include <string>
#include <iostream>
#include "EaterOf.h"
#include "Exceptions.h"
using namespace std;

// Demonstrates EaterOf with int, double, string
void runProblem2() {
    try {
        EaterOf<int> intEater;
        EaterOf<double> doubleEater;
        EaterOf<string> stringEater;

        intEater.eat(5);
        doubleEater.eat(5.5);
        stringEater.eat("Yum");

        cout << "Int burp: " << intEater.burp() << endl;
        cout << "Double burp: " << doubleEater.burp() << endl;
        cout << "String burp: " << stringEater.burp() << endl;
    }
    catch (const NotEdibleException& e) {
        cerr << "Burp!\n" << e.what() << endl;
    }
}
