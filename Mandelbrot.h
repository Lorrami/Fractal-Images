#ifndef FRACTAL_IMAGES_MANDELBROT_H
#define FRACTAL_IMAGES_MANDELBROT_H


class Mandelbrot {
public:
    static const int MAX_ITERATIONS = 1000;
public:
    Mandelbrot() = default;
    virtual ~Mandelbrot() = default;

    static int get_iterations(double x, double y);
};


#endif //FRACTAL_IMAGES_MANDELBROT_H
