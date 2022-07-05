#ifndef FRACTAL_IMAGES_BITMAP_H
#define FRACTAL_IMAGES_BITMAP_H

#include <iostream>
#include <string>

class Bitmap {
private:
    int m_width{};
    int m_height{};
    std::shared_ptr<uint8_t[]> m_pixels;
public:
    Bitmap() = default;
    Bitmap(int width, int height);

    void set_pixel(int x, int y, uint8_t red, uint8_t green, uint8_t blue);

    bool write(const std::string& file_name);

    virtual ~Bitmap() = default;
};


#endif //FRACTAL_IMAGES_BITMAP_H
