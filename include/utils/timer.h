#pragma once
#include <chrono>
#include <string>
#include <sstream>
#include <iomanip>

namespace huzlip::utils {

class Timer {
    std::chrono::time_point<std::chrono::high_resolution_clock> start_;
public:
    Timer() : start_(std::chrono::high_resolution_clock::now()) {}
    void reset() { start_ = std::chrono::high_resolution_clock::now(); }
    double elapsed() const {
        return std::chrono::duration<double>(std::chrono::high_resolution_clock::now() - start_).count();
    }
    std::string elapsedStr() const {
        std::ostringstream oss;
        oss << std::fixed << std::setprecision(6) << elapsed() << " s";
        return oss.str();
    }
};

} // namespace huzlip::utils