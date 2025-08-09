#ifndef COLOR_H
#define COLOR_H

#include <iostream>

class Color {
private:
    int red, green, blue;

public:
    Color(int r = 255, int g = 255, int b = 255);

    int getRed() const;
    int getGreen() const;
    int getBlue() const;

    friend std::ostream& operator<<(std::ostream& os, const Color& c);
};

#endif
