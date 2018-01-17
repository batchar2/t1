#pragma once

#include <string>
#include <memory>

#include <opencv2/opencv.hpp>

/**
 * namespace capture
 * @brief factory method
 */
namespace capture
{
    /**
     * @brief Abstract base class for the factory method
     */
    class capture
    {
    public:
        /**
         * @brief Open a file for read
         * @param path - path to file
         * @return success == true
         */
        virtual bool open(std::string path) = 0;
        /**
         * @brief Read frame data
         * @return
         */
        virtual std::shared_ptr<cv::Mat> read() = 0;
    };
}

