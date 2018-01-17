cmake_minimum_required(VERSION 3.0)
project(similar)

set(CMAKE_CXX_STANDARD 11)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")

find_package(OpenCV REQUIRED)

include_directories(".")

add_executable(similar
        main.cpp
        capture/factory.cpp
        capture/factory.h
        capture/video.h
        capture/image.h
        capture/video.cpp
        capture/image.cpp
        capture/capture.h
        similar/calculation.cpp
        similar/calculation.h)

target_link_libraries(similar ${OpenCV_LIBS})