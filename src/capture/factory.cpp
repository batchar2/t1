#include "factory.h"


std::shared_ptr<capture::capture> capture::factory::create(std::string path)
{
    std::shared_ptr<capture> cap;

    std::string file_ext = path.substr(path.find_last_of(".") + 1);
    if (file_ext == "jpeg" || file_ext == "jpg" || file_ext == "png" || file_ext == "gif") {
        cap =  std::make_shared<image>();
    } else if (file_ext == "avi" || file_ext == "mp4") {
        cap = std::make_shared<video>();
    } else {
        throw std::invalid_argument("File " + path + " is an unknown type");
    }

    if (!cap->open(path)) {
        throw std::invalid_argument("File " + path + " not found" );
    }
    return cap;
}