#include "image.h"

#include <fstream>

using namespace capture;

bool image::open(std::string path)
{
    this->file_path_ = path;
    // check file exists
    std::ifstream ifile(path);
    return (bool)ifile;
}

std::shared_ptr<cv::Mat> image::read()
{
    auto pimg = std::make_shared<cv::Mat>();
    if (!this->is_read_) {
        *pimg = cv::imread(this->file_path_, CV_LOAD_IMAGE_COLOR);
        this->is_read_ = true;
    }
    return pimg;
}