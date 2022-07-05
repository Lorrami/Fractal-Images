#include "FractalPicture.h"

#include <utility>

FractalPicture::FractalPicture(int width, int height) :
    m_width(width), m_height(height) {
    zoom_list = {m_width, m_height};
    bitmap = {m_width, m_height};
    m_histogram = std::make_unique<int[]>(Mandelbrot::MAX_ITERATIONS);
    m_fractal = std::make_unique<int[]>(m_width * m_height);
}

void FractalPicture::zoom() {
    zoom_list.add(Zoom(m_width/2, m_height/2, 4.0/m_width));
    zoom_list.add(Zoom(295, m_height - 202, 0.1));
}

void FractalPicture::get_histogram() {
    for (auto y = 0; y < m_height; y++) {
        for (auto x = 0; x < m_width; x++) {
            std::pair<double, double> fractals = zoom_list.get_fractals(x, y);

            int iterations = Mandelbrot::get_iterations(fractals.first, fractals.second);
            if (iterations != Mandelbrot::MAX_ITERATIONS) {
                m_histogram[iterations]++;
            }
            m_fractal[y * m_width + x] = iterations;
        }
    }
}

void FractalPicture::create_image(const std::string& file_name) {
    int total = 0;
    for (auto i = 0; i < Mandelbrot::MAX_ITERATIONS; i++) {
        total += m_histogram[i];
    }
    calculate_range_totals();

    for (auto y = 0; y < m_height; y++) {
        for (auto x = 0; x < m_width; x++) {
            int iterations = m_fractal[y * m_width + x];
            int range = get_range(iterations);
            int total_ranges = m_total_ranges[range];
            int range_start = m_ranges[range];

            RGB& first_color = m_colors[range];
            RGB& last_color = m_colors[range + 1];
            RGB diff = last_color - first_color;

            uint8_t red;
            uint8_t green;
            uint8_t blue;

            if (iterations != Mandelbrot::MAX_ITERATIONS) {
                int total_pixels = 0;
                for (auto i = range_start; i <= iterations; i++) {
                    total_pixels += m_histogram[i];
                }

                red = uint8_t(first_color.r + diff.r*(double)total_pixels / total_ranges);
                green = uint8_t(first_color.g + diff.g*(double)total_pixels / total_ranges);
                blue = uint8_t(first_color.b + diff.b*(double)total_pixels / total_ranges);

                bitmap.set_pixel(x, y, red, green, blue);
            }
        }
    }
    bitmap.write(file_name);
}

int FractalPicture::get_range(int iterations) const {
    int range = 0;
    for (int i = 1; i < m_ranges.size(); i++) {
        range = i;
        if (m_ranges[i] > iterations) {
            break;
        }
    }
    range--;

    return range;
}

void FractalPicture::calculate_range_totals() {
    int range_index{};
    for (auto i = 0; i < Mandelbrot::MAX_ITERATIONS; i++) {
        int pixels = m_histogram[i];
        if (i >= m_ranges[range_index + 1]) {
            range_index++;
        }
        m_total_ranges[range_index] += pixels;
    }
}

void FractalPicture::add_range(double range_end, const RGB& rgb) {
    m_ranges.push_back((int)(range_end * Mandelbrot::MAX_ITERATIONS));
    m_colors.push_back(rgb);

    if (m_got_first_range) {
        m_total_ranges.push_back(0);
    }
    m_got_first_range = true;
}

void FractalPicture::run(const std::string& file_name) {
    zoom();

    get_histogram();

    create_image(file_name);
}
