#include "PrimeFactor.h"
#include <cmath>

int findLowestPrimeFactor(int num) {
    if (num <= 1) return 0;  // no prime factors for 0 or 1

    for (int i = 2; i <= std::sqrt(num); ++i) {
        if (num % i == 0) {
            return i;  // found lowest factor
        }
    }
    return 0; 
}

// Recursive function
std::vector<int> getPrimeFactors(int num) {
    std::vector<int> factors;

    int factor = findLowestPrimeFactor(num);

    if (factor == 0) {
        if (num > 1) factors.push_back(num);
    }
    else {
        // factor divides num, recurse on num/factor
        factors.push_back(factor);
        std::vector<int> subFactors = getPrimeFactors(num / factor);
        factors.insert(factors.end(), subFactors.begin(), subFactors.end());
    }

    return factors;
}
