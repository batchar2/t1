cmake_minimum_required(VERSION 3.0)
project(test)

find_package(OpenCV REQUIRED)
find_package(Boost COMPONENTS unit_test_framework REQUIRED)

set(CMAKE_CXX_STANDARD 11)

ADD_DEFINITIONS(-DBOOST_TEST_DYN_LINK)

include_directories("../src")

file(GLOB
        PROJECT_CAPTURE_SOURCES
        "../src/capture/*.h"
        "../src/capture/*.cpp")

file(GLOB
        SIMILAR_SOURCES
        "../src/similar/*.h"
        "../src/similar/*.cpp")

add_executable(capture_test capture_test.cpp ${PROJECT_CAPTURE_SOURCES})
target_link_libraries(capture_test ${Boost_LIBRARIES} ${OpenCV_LIBS})
add_test(NAME capture_test COMMAND capture_test)


add_executable(similar_test similar_test.cpp ${PROJECT_CAPTURE_SOURCES} ${SIMILAR_SOURCES})
target_link_libraries(similar_test ${Boost_LIBRARIES} ${OpenCV_LIBS})
add_test(NAME similar_test COMMAND similar_test)

