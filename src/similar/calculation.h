#pragma once

#include "capture/capture.h"

/**
 * namespace similar
 * @brief The namespace for calculating similar files
 */
namespace similar {
    /**
     * @brief Calculating similar files
     */
    class calculation
    {
    private:
        /**
         * @brief input stream
         */
        std::shared_ptr<capture::capture> cap_;
        /**
         * @brief ColorBars stream
         */
        std::shared_ptr<capture::capture> color_bars_cap_;
    public:
        /**
         * @brief Constructor
         * @param cap - input stream
         * @param color_bars_cap - colorbar stream
         */
        calculation(std::shared_ptr<capture::capture> &cap,
                std::shared_ptr<capture::capture> &color_bars_cap);
        /**
         * The method starts calculating the proximity of files
         */
        void run();
    protected:
        /**
         * @brief The function implements the calculation of the proximity of files. Called cyclically
         * @param img - input image
         * @param color_bars - colorbars image
         * @return - Meaning of file proximity
         */
        virtual std::uint64_t iterate(const std::shared_ptr<cv::Mat> &img,
                                      const std::shared_ptr<cv::Mat> &color_bars);
    };
}