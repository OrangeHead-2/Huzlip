#include "utils/filesystem.h"
#include <fstream>
#include <sstream>
#include <sys/stat.h>
#include <dirent.h>

/**
 * @file filesystem.cpp
 * @brief Implements minimal cross-platform filesystem helpers: directory listing, file IO, and existence checks.
 *        Note: For complex needs, prefer std::filesystem (C++17) or a library.
 */

namespace huzlip::utils {

std::vector<std::string> Filesystem::listFiles(const std::string& dir, bool recursive) {
    std::vector<std::string> files;
    DIR* dp = opendir(dir.c_str());
    if (!dp) return files;
    struct dirent* entry;
    while ((entry = readdir(dp)) != nullptr) {
        std::string name = entry->d_name;
        if (name == "." || name == "..") continue;
        std::string path = dir + "/" + name;
        struct stat st;
        if (stat(path.c_str(), &st) == 0) {
            if (S_ISDIR(st.st_mode) && recursive) {
                auto subfiles = listFiles(path, true);
                files.insert(files.end(), subfiles.begin(), subfiles.end());
            } else if (S_ISREG(st.st_mode)) {
                files.push_back(path);
            }
        }
    }
    closedir(dp);
    return files;
}

std::string Filesystem::readFile(const std::string& path) {
    std::ifstream file(path);
    std::ostringstream ss;
    ss << file.rdbuf();
    return ss.str();
}

void Filesystem::writeFile(const std::string& path, const std::string& data) {
    std::ofstream file(path);
    file << data;
}

bool Filesystem::exists(const std::string& path) {
    struct stat st;
    return stat(path.c_str(), &st) == 0;
}

} // namespace huzlip::utils