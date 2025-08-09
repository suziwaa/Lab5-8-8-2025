#ifndef EATEROF_H
#define EATEROF_H

#include <iostream>
#include <string>
#include <sstream> 
#include <type_traits>
#include <exception>

template <typename T>
class EaterOf {
private:
    T sum;

public:
    // Custom exception class inside EaterOf
    class NotEdibleException : public std::exception {
    private:
        std::string message;
    public:
        NotEdibleException(const std::string& foodDesc, const T& currentSum) {
            message = "Burp! \n" + toString(currentSum) + "\nI can't eat " + foodDesc;
        }
        const char* what() const noexcept override {
            return message.c_str();
        }

    private:
        // Helper to convert sum to string 
        static std::string toString(const T& value) {
            std::ostringstream oss;
            oss << value;
            return oss.str();
        }
    };

    // Constructor initializes sum to default T()
    EaterOf() : sum(T()) {}

    
       void eat(const T & food) {
            std::cout << "nom-nom" << std::endl;
            try {
                sum = sum + food;
            }
            catch (...) {
                throw NotEdibleException(toString(food), sum);
            }
        }

    

    T burp() const {
        return sum;
    }

private:
    // Helper to convert any T to string using ostream
    static std::string toString(const T& val) {
        std::ostringstream oss;
        oss << val;
        return oss.str();
    }

};

#endif
