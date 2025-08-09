#ifndef PICTURE_H
#define PICTURE_H

#include <vector>
#include "Color.h"
#include <iostream>

class Picture {
private:
    std::vector<std::vector<Color>> pixels;

public:
    Picture(int width, int height);

    void setPixel(int x, int y, const Color& c);

    int getWidth() const;
    int getHeight() const;

    friend std::ostream& operator<<(std::ostream& os, const Picture& pic);
};

#endif
