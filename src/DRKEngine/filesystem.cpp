#include "filesystem.h"

drk::FilePath::FilePath(const std::string &path) {
    this->path = path;
}

std::string drk::FilePath::systemPath() {
    if (this->path.starts_with('/')) {
        std::cout << "drk::FilePath::systemPath(): error: Absolute paths not supported!" << std::endl;
        // TODO: make absolute paths, "/" is project root, not system root
    } // else {
#if defined(WIN32) | defined (WIN64)
        return this->path.replace(this->path.begin(), this->path.end(), '/', '\\');
#else
        return this->path;
#endif
    // }
}
