#define BOOST_TEST_MODULE similar_test

#include <cstdio>
#include <fstream>

#include <boost/test/unit_test.hpp>

#include "capture/factory.h"
#include "similar/calculation.h"

BOOST_AUTO_TEST_SUITE(similar_test)

    BOOST_AUTO_TEST_CASE(calculation)
    {
        const char test_file[] = "/tmp/tst-empty.jpg";

        std::ofstream file(test_file);
        file.close();

        auto in = capture::factory::create(test_file);
        auto bars = capture::factory::create(test_file);

        similar::calculation calc(in, bars);

        BOOST_CHECK_NO_THROW(calc.run());
    }


BOOST_AUTO_TEST_SUITE_END()