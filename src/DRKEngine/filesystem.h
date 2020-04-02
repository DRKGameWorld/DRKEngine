#pragma once

#include <string>
#include <iostream>

namespace drk {
    class FilePath {
    public:
        explicit FilePath(const std::string &path);
        std::string systemPath();
//        std::string basename();
//        std::string absolute();
//        std::string dirname(bool absolute = false);

    private:
        std::string path;
    };
}