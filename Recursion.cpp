#include "Recursion.h"
using namespace std;

// Finds the smallest prime factor > 1
int findLowestPrimeFactor(int num) {
    if (num < 2) return 0;
    for (int i = 2; i <= num / 2; i++) {
        bool isPrime = true;
        for (int j = 2; j * j <= i; j++) {
            if (i % j == 0) { isPrime = false; break; }
        }
        if (isPrime && num % i == 0) return i;
    }
    return 0;
}

// Recursively factorizes into primes
vector<int> getPrimeFactors(int num) {
    vector<int> factors;
    int lowest = findLowestPrimeFactor(num);
    if (lowest == 0) { // num is prime
        factors.push_back(num);
        return factors;
    }
    factors.push_back(lowest);
    vector<int> rest = getPrimeFactors(num / lowest);
    factors.insert(factors.end(), rest.begin(), rest.end());
    return factors;
}
