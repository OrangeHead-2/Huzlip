#pragma once
#include <string>
#include <chrono>
#include <map>

namespace huzlip::utils {

class Profiler {
    std::map<std::string, double> times_;
    std::map<std::string, size_t> counts_;
    std::chrono::time_point<std::chrono::high_resolution_clock> start_;
    std::string currentLabel_;
public:
    void start(const std::string& label);
    void stop();
    void report() const;
};

} // namespace huzlip::utils