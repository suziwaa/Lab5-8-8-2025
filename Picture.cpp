#include "Picture.h"

Picture::Picture(int width, int height) {
    pixels.resize(height, std::vector<Color>(width, Color(255, 255, 255))); // all white
}

void Picture::setPixel(int x, int y, const Color& c) {
    if (y >= 0 && y < (int)pixels.size() && x >= 0 && x < (int)pixels[0].size()) {
        pixels[y][x] = c;
    }
}

int Picture::getWidth() const {
    if (pixels.empty()) return 0;
    return (int)pixels[0].size();
}

int Picture::getHeight() const {
    return (int)pixels.size();
}

std::ostream& operator<<(std::ostream& os, const Picture& pic) {
    for (const auto& row : pic.pixels) {
        for (const auto& c : row) {
            os << c;
        }
        os << '\n';
    }
    return os;
}
