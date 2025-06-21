#pragma once
#include <string>
#include <iostream>
#include <mutex>

namespace huzlip::utils {

class Logger {
    static std::mutex mtx_;
public:
    static void info(const std::string& msg);
    static void warn(const std::string& msg);
    static void error(const std::string& msg);
};

} // namespace huzlip::utils