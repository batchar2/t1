#pragma once

#include "capture.h"

namespace capture
{
    /**
     * @brief Video processing
     */
    class video : public capture::capture
    {
    private:
        cv::VideoCapture *cap_;
    public:
        /**
         * @brief Desctructor (closes the video file)
         */
        ~video();
        /**
         * @brief Open a file for read
         * @param path - path to file
         * @return success == true
         */
        virtual bool open(std::string path) override;
        /**
         * @brief Read frame data
         * @return
         */
        virtual std::shared_ptr<cv::Mat> read() override;
    };
}

