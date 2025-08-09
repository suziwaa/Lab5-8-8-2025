#include "exceptions.h"
#include "Picture.h"
#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;

Picture readPictureFromFile(const string& filename, int width, int height) {
    ifstream file(filename);
    if (!file)
        throw FileNotFoundException("File not found: " + filename);

    Picture pic(width, height);
    std::string line;

    while (getline(file, line)) {
        stringstream ss(line);
        int x, y, r, g, b;

        if (!(ss >> x >> y >> r >> g >> b))
            throw ColorFileFormatException("Invalid file format: could not parse 5 integers");

        // Check coordinates, log and skip if negative
        if (x < 0 || y < 0) {
            cerr << "CoordinateOutOfRangeException: Negative coordinate at X=" << x << " Y=" << y << ". Skipping pixel.\n";
            continue;
        }

        // Clamp and log if out of range
        if (r < 0) {
            cerr << "Error! X: " << x << " Y: " << y << " Red value too low: min : 0, actual: " << r << "\n";
            r = 0;
        }
        else if (r > 255) {
            cerr << "Error! X: " << x << " Y: " << y << " Red value too high: max : 255, actual: " << r << "\n";
            r = 255;
        }
        if (g < 0) {
            cerr << "Error! X: " << x << " Y: " << y << " Green value too low: min : 0, actual: " << g << "\n";
            g = 0;
        }
        else if (g > 255) {
            cerr << "Error! X: " << x << " Y: " << y << " Green value too high: max : 255, actual: " << g << "\n";
            g = 255;
        }
        if (b < 0) {
            cerr << "Error! X: " << x << " Y: " << y << " Blue value too low: min : 0, actual: " << b << "\n";
            b = 0;
        }
        else if (b > 255) {
            cerr << "Error! X: " << x << " Y: " << y << " Blue value too high: max : 255, actual: " << b << "\n";
            b = 255;
        }

        Color c(r, g, b);
        pic.setPixel(x, y, c);
    }
    return pic;
}
