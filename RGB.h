#ifndef FRACTAL_IMAGES_RGB_H
#define FRACTAL_IMAGES_RGB_H


struct RGB {
    RGB(double r, double g, double b);

    double r{};
    double g{};
    double b{};

};

RGB operator-(const RGB& first, const RGB& second);


#endif //FRACTAL_IMAGES_RGB_H
