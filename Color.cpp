#include "Color.h"

Color::Color(int r, int g, int b) : red(r), green(g), blue(b) {}

int Color::getRed() const { return red; }
int Color::getGreen() const { return green; }
int Color::getBlue() const { return blue; }

std::ostream& operator<<(std::ostream& os, const Color& c) {
    int r = c.red, g = c.green, b = c.blue;

    // Check equalities first
    if (r == g && g == b) {
        if (r > 250) os << 'W';      // White
        else if (r < 50) os << 'D';  // Dark
        else os << 'G';              // Gray
    }
    else if (r == b && r > g) os << 'P';   // Purple (R and B equal highest)
    else if (r == g && r > b) os << 'Y';   // Yellow (R and G equal highest)
    else if (b == g && b > r) os << 'T';   // Teal (B and G equal highest)
    else {
        // Find max channel
        if (r > g && r > b) os << 'R';
        else if (g > r && g > b) os << 'V'; // V for Green (to differentiate from Blue)
        else if (b > r && b > g) os << 'B';
        else os << '?'; 
    }
    return os;
}
