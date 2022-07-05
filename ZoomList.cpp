#include "ZoomList.h"

ZoomList::ZoomList(int width, int height) :
    m_width(width), m_height(height) {
}

void ZoomList::add(const Zoom &zoom) {
    zooms.push_back(zoom);

    m_x_center += (zoom.x - m_width / 2)  * m_scale;
    m_y_center += (zoom.y - m_height / 2)  * m_scale;

    m_scale *= zoom.scale;
}

std::pair<double, double> ZoomList::get_fractals(int x, int y) {
    double x_fractal = (x - m_width / 2) * m_scale + m_x_center;
    double y_fractal = (y - m_height / 2) * m_scale + m_y_center;
    return {x_fractal, y_fractal};
}
