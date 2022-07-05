#ifndef FRACTAL_IMAGES_ZOOMLIST_H
#define FRACTAL_IMAGES_ZOOMLIST_H

#include "Zoom.h"

#include <vector>
#include <utility>

class ZoomList {
private:
    double m_x_center{};
    double m_y_center{};
    double m_scale{1.0};

    int m_width{};
    int m_height{};
    std::vector<Zoom> zooms{};
public:
    ZoomList() = default;
    ZoomList(int width, int height);

    void add(const Zoom& zoom);

    std::pair<double, double> get_fractals(int x, int y) const;
};


#endif //FRACTAL_IMAGES_ZOOMLIST_H
