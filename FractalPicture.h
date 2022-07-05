#ifndef FRACTAL_IMAGES_FRACTALPICTURE_H
#define FRACTAL_IMAGES_FRACTALPICTURE_H

#include "ZoomList.h"
#include "Bitmap.h"
#include "Mandelbrot.h"
#include "RGB.h"

#include <vector>

class FractalPicture {
private:
    ZoomList zoom_list{};
    Bitmap bitmap{};
    int m_width{};
    int m_height{};
    std::unique_ptr<int[]> m_histogram;
    std::unique_ptr<int[]> m_fractal;
    std::vector<int> m_ranges{};
    std::vector<RGB> m_colors{};
    std::vector<int> m_total_ranges{};
    bool m_got_first_range{false};
private:
    void zoom();

    void get_histogram();

    void create_image(const std::string& file_name);

    void calculate_range_totals();

    int get_range(int iterations) const;
public:
    FractalPicture(int width, int height);

    void add_range(double range_end, const RGB& rgb);

    void run(const std::string& file_name);
};


#endif //FRACTAL_IMAGES_FRACTALPICTURE_H
