#ifndef FRACTAL_IMAGES_ZOOM_H
#define FRACTAL_IMAGES_ZOOM_H


struct Zoom {
    int x{};
    int y{};
    double scale{};
    Zoom(int x, int y, double scale) :
        x(x), y(y), scale(scale) { }
};


#endif //FRACTAL_IMAGES_ZOOM_H
