#pragma once
#include <string>
#include <vector>

namespace huzlip::utils {

class Filesystem {
public:
    static std::vector<std::string> listFiles(const std::string& dir, bool recursive = false);
    static std::string readFile(const std::string& path);
    static void writeFile(const std::string& path, const std::string& data);
    static bool exists(const std::string& path);
};

} // namespace huzlip::utils