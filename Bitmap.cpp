#include "Bitmap.h"
#include "BitmapInfo.h"
#include "BitmapFile.h"

#include <fstream>

Bitmap::Bitmap(int width, int height) :
    m_width(width),
    m_height(height),
    m_pixels(new uint8_t[width * height * 3]{}) { }

void Bitmap::set_pixel(int x, int y, uint8_t red, uint8_t green, uint8_t blue) {
    uint8_t *pixel = m_pixels.get();

    pixel += (y * 3) * m_width + (x * 3);

    pixel[0] = blue;
    pixel[1] = green;
    pixel[2] = red;
}

bool Bitmap::write(const std::string& file_name) {
    BitmapFile bitmap_file;
    BitmapInfo bitmap_info;

    bitmap_file.file_size = sizeof(BitmapFile) + sizeof(BitmapInfo) + m_width * m_height * 3;
    bitmap_file.data_off_set = sizeof(BitmapFile) + sizeof(BitmapInfo);

    bitmap_info.width = m_width;
    bitmap_info.height = m_height;

    std::ofstream file;
    file.open(file_name, std::ios::out | std::ios::binary);

    if (!file) {
        return false;
    }

    file.write((char*)&bitmap_file, sizeof(bitmap_file));
    file.write((char*)&bitmap_info, sizeof(bitmap_info));
    file.write((char*)m_pixels.get(), m_width * m_height * 3);

    file.close();

    return true;
}
