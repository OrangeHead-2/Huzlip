#include "utils/profiler.h"
#include <iostream>
#include <iomanip>

/**
 * @file profiler.cpp
 * @brief Implements a lightweight profiler for timing labeled code blocks.
 *        Aggregates timing data and call counts for reporting.
 */

namespace huzlip::utils {

void Profiler::start(const std::string& label) {
    currentLabel_ = label;
    start_ = std::chrono::high_resolution_clock::now();
}

void Profiler::stop() {
    auto end = std::chrono::high_resolution_clock::now();
    double seconds = std::chrono::duration<double>(end - start_).count();
    times_[currentLabel_] += seconds;
    counts_[currentLabel_]++;
    currentLabel_.clear();
}

void Profiler::report() const {
    std::cout << "Profiler Report:\n";
    for (const auto& kv : times_) {
        const std::string& label = kv.first;
        double total = kv.second;
        size_t count = counts_.at(label);
        std::cout << std::setw(20) << std::left << label << " "
                  << std::setw(10) << total << " s (calls: " << count << " avg: " << (total / count) << " s)" << std::endl;
    }
}

} // namespace huzlip::utils