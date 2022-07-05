cmake_minimum_required(VERSION 3.22)
project(fractal_images)

set(CMAKE_CXX_STANDARD 14)

set(SOURCES
        "main.cpp"
        "Bitmap.cpp"
        "Mandelbrot.cpp"
        "ZoomList.cpp"
        "FractalPicture.cpp"
        "RGB.cpp")

add_executable(fractal_images ${SOURCES})
