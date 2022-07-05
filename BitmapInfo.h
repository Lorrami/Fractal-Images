#ifndef FRACTAL_IMAGES_BITMAPINFO_H
#define FRACTAL_IMAGES_BITMAPINFO_H


#include <cstdint>

struct BitmapInfo {
    int32_t info_size{40};
    int32_t width{};
    int32_t height{};
    int16_t planes{1};
    int16_t bits_per_pixel{24};
    int32_t compression{};
    int32_t data_size{};
    int32_t horizontal_resolution{2400};
    int32_t vertical_resolution{2400};
    int32_t colors{};
    int32_t important_colors{};
};


#endif //FRACTAL_IMAGES_BITMAPINFO_H
