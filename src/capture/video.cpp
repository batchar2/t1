#include "video.h"

using namespace capture;

video::~video()
{
    this->cap_->release();
}

bool video::open(std::string path)
{
    this->cap_ = new cv::VideoCapture(path);
    return this->cap_->isOpened();
}

std::shared_ptr<cv::Mat> video::read()
{
    auto pimg = std::make_shared<cv::Mat>();
    *this->cap_ >> *pimg;
    return pimg;
}

