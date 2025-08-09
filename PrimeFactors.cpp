#include "PrimeFactors.h"
#include <cmath>

int findLowestPrimeFactor(int num) {
    if (num <= 1) return 0;  // no prime factors

    for (int i = 2; i <= std::sqrt(num); ++i) {
        if (num % i == 0) {
            return i;
        }
    }
    return 0;  // prime number
}

std::vector<int> getPrimeFactors(int num) {
    std::vector<int> factors;

    if (num <= 1) return factors;

    int factor = findLowestPrimeFactor(num);

    if (factor == 0) {
        factors.push_back(num);  // num itself prime
    }
    else {
        factors.push_back(factor);
        std::vector<int> rest = getPrimeFactors(num / factor);
        factors.insert(factors.end(), rest.begin(), rest.end());
    }

    return factors;
}
