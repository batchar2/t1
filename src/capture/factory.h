#pragma once

#include "factory.h"

#include "video.h"
#include "image.h"

namespace capture {

    /**
     * @brief Implementing the factory method
     */
    class factory
    {
    public:
        /**
         * @brief Creating a factory responsible for working with the media file
         * @param path - Path to file
         * @return
         */
        static std::shared_ptr<capture> create(std::string path);
    };
}

