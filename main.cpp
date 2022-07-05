#include "FractalPicture.h"
#include "RGB.h"

#include <iostream>

int main() {
    int const WIDTH = 800;
    int const HEIGHT = 600;

    FractalPicture fractal_picture(WIDTH, HEIGHT);

    fractal_picture.add_range(0.0, RGB(0, 0, 255));
    fractal_picture.add_range(0.05, RGB(255, 99, 71));
    fractal_picture.add_range(0.08, RGB(255, 215, 0));
    fractal_picture.add_range(1.0, RGB(255, 255, 255));

    fractal_picture.run("test.bmp");

    std::cout << "777" << std::endl;
    return 777;
}
