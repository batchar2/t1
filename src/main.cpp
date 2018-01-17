#include <iostream>

#include "capture/factory.h"
#include "similar/calculation.h"


int main(int argc, char **argv)
{
    try {
        if (argc != 3) {
            throw std::invalid_argument("Incorrect arguments. Use:");
        }
        auto input = capture::factory::create(argv[1]);
        auto color_bars = capture::factory::create(argv[2]);

        similar::calculation calc(input, color_bars);
        calc.run();
    }
    catch (const std::invalid_argument& ia) {
        std::cerr << ia.what() << std::endl;
        std::cerr << argv[0]
                  << " input-file.[jpg|jpeg|png|avi|mp4|gif] "
                  << " color-bars.[jpg|jpeg|png|avi|mp4|gif] "
                  << std::endl;
        return 1;
    }
    return 0;
}