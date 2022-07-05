#ifndef FRACTAL_IMAGES_BITMAPFILE_H
#define FRACTAL_IMAGES_BITMAPFILE_H


#include <cstdint>

#pragma pack(2)
struct BitmapFile {
    char header[2]{'B', 'M'};
    int32_t file_size{};
    int32_t reserved{0};
    int32_t data_off_set{};
};


#endif //FRACTAL_IMAGES_BITMAPFILE_H
