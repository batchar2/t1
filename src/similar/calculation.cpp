#include "calculation.h"


using namespace similar;

similar::calculation::calculation(std::shared_ptr<capture::capture> &cap,
                          std::shared_ptr<capture::capture> &color_bars_cap) :
    cap_(cap),
    color_bars_cap_(color_bars_cap)
{
}

void similar::calculation::run()
{
    std::shared_ptr<cv::Mat> img;
    std::shared_ptr<cv::Mat> color_bars = this->color_bars_cap_->read();

    if (!color_bars->empty()) {
        uint frame_number = 0;
        while (img=cap_->read(), !img->empty()) {
            uint similar_number = this->iterate(img, color_bars);
            std::cerr << frame_number++
                      << " similar = "
                      << similar_number
                      << std::endl;
        }
    }
}

std::uint64_t similar::calculation::iterate(const std::shared_ptr<cv::Mat> &img,
                                            const std::shared_ptr<cv::Mat> &color_bars)
{
    // resize image
    if (img->cols != color_bars->cols || img->rows != color_bars->rows) {
        cv::resize(*img, *img, color_bars->size());
    }
    long unsigned int calc = 0;
    const int cn = img->channels();
    for(int i = 0; i < img->rows; i++) {
        for(int j = 0; j < img->cols; j++) {
            auto bgr_img = img->at<cv::Vec3b>(i, j);
            auto bgr_bars = color_bars->at<cv::Vec3b>(i, j);
            calc += std::abs(bgr_img[0] - bgr_bars[0]);
            calc += std::abs(bgr_img[1] - bgr_bars[1]);
            calc += std::abs(bgr_img[2] - bgr_bars[2]);
        }
    }

    return calc / (img->cols * img->rows * 3);
}
