#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <exception>
#include <string>

class FileNotFoundException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Error: File not found.";
    }
};

class ColorFileFormatException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Error: Color file format is incorrect.";
    }
};

class CoordinateOutOfRangeException : public std::exception {
private:
    std::string message;
public:
    CoordinateOutOfRangeException(int x, int y) {
        message = "CoordinateOutOfRangeException: Negative coordinate detected. X: " + std::to_string(x) + " Y: " + std::to_string(y);
    }
    const char* what() const noexcept override {
        return message.c_str();
    }
};

class ColorVectorOutOfRangeException : public std::exception {
private:
    std::string message;
public:
    ColorVectorOutOfRangeException(int x, int y, const std::string& colorName, int value) {
        message = "Error! X: " + std::to_string(x) + " Y: " + std::to_string(y) + " " + colorName + " value out of range: min: 0, max: 255, actual: " + std::to_string(value);
    }
    const char* what() const noexcept override {
        return message.c_str();
    }
};

#endif
