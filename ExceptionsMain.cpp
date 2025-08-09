 /*
 #include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "Color.h"
#include "Picture.h"
#include "Exceptions.h"
#include <tuple>

using namespace std;

int main() {
    string filename;
    cout << "Enter filename for color data: ";
    cin >> filename;

    // Try to open the file
    ifstream infile(filename);
    if (!infile.is_open()) {
        // File not found, print message and exit
        cerr << FileNotFoundException().what() << endl;
        return 1;
    }

    vector<tuple<int, int, int, int, int>> data;

    string line;
    int maxX = 0, maxY = 0;    // Track max dimensions for picture size
    try {
        while (getline(infile, line)) {
            if (line.empty()) continue;
            istringstream iss(line);

            int x, y, r, g, b;
            if (!(iss >> x >> y >> r >> g >> b)) {
                throw ColorFileFormatException();
            }

            if (x < 0 || y < 0) {
                // Log error, do not add this coordinate
                cerr << CoordinateOutOfRangeException(x, y).what() << endl;
                continue;
            }

            // Clamp colors with messages
            if (r < 0) {
                cerr << ColorVectorOutOfRangeException(x, y, "Red", r).what() << endl;
                r = 0;
            }
            else if (r > 255) {
                cerr << ColorVectorOutOfRangeException(x, y, "Red", r).what() << endl;
                r = 255;
            }

            if (g < 0) {
                cerr << ColorVectorOutOfRangeException(x, y, "Green", g).what() << endl;
                g = 0;
            }
            else if (g > 255) {
                cerr << ColorVectorOutOfRangeException(x, y, "Green", g).what() << endl;
                g = 255;
            }

            if (b < 0) {
                cerr << ColorVectorOutOfRangeException(x, y, "Blue", b).what() << endl;
                b = 0;
            }
            else if (b > 255) {
                cerr << ColorVectorOutOfRangeException(x, y, "Blue", b).what() << endl;
                b = 255;
            }

            data.emplace_back(x, y, r, g, b);

            if (x > maxX) maxX = x;
            if (y > maxY) maxY = y;
        }
    }
    catch (const ColorFileFormatException& e) {
        cerr << e.what() << endl;
        return 1;
    }

    Picture pic(maxX + 1, maxY + 1);
    for (const auto& tup : data) {
        int x = std::get<0>(tup);
        int y = std::get<1>(tup);
        int r = std::get<2>(tup);
        int g = std::get<3>(tup);
        int b = std::get<4>(tup);
        pic.setPixel(x, y, Color(r, g, b));
    }

    cout << pic;

    return 0;
}
*/