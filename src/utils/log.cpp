#include "utils/log.h"
#include <iostream>
#include <mutex>

/**
 * @file log.cpp
 * @brief Implements thread-safe logging for info, warning, and error messages.
 *        Provides synchronized output for multi-threaded applications.
 */

namespace huzlip::utils {

// Define the static mutex for synchronized logging
std::mutex Logger::mtx_;

void Logger::info(const std::string& msg) {
    std::lock_guard<std::mutex> lock(mtx_);
    std::cout << "[INFO] " << msg << std::endl;
}

void Logger::warn(const std::string& msg) {
    std::lock_guard<std::mutex> lock(mtx_);
    std::cout << "[WARNING] " << msg << std::endl;
}

void Logger::error(const std::string& msg) {
    std::lock_guard<std::mutex> lock(mtx_);
    std::cerr << "[ERROR] " << msg << std::endl;
}

} // namespace huzlip::utils