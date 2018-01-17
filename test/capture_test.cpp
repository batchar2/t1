#define BOOST_TEST_MODULE capture_test

#include <cstdio>
#include <fstream>

#include <boost/test/unit_test.hpp>

#include "capture/factory.h"


BOOST_AUTO_TEST_SUITE(capture_test)


    BOOST_AUTO_TEST_CASE(fatory_method)
    {
        BOOST_CHECK_THROW(capture::factory::create("trash"), std::invalid_argument);

        std::vector<std::string> test_files = {
                "/tmp/empty.jpg",
                "/tmp/empty.jpeg",
                "/tmp/empty.png",
                "/tmp/empty.gif",
                //"/tmp/empty.mp4",
                //"/tmp/empty.avi"
        };
        // remove files
        for (auto test_file: test_files) {
            remove(test_file.c_str());
            BOOST_CHECK_THROW(capture::factory::create(test_file), std::invalid_argument);
        }
        // create empty file
        for (auto test_file : test_files) {
            std::ofstream file(test_file);
            file.close();
            BOOST_CHECK_NO_THROW(capture::factory::create(test_file));
        }
    }

BOOST_AUTO_TEST_SUITE_END()