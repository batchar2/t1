#pragma once

#include "capture.h"

namespace capture
{
    /**
     * @brief Image processing
     */
    class image : public capture::capture
    {
    private:
        /**
         * @brief path to file
         */
        std::string file_path_;
        /**
         * @brief the image file is read once
         */
        bool is_read_ = false;
    public:
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

