#pragma once
#include <random>
#include <mutex>
#include <limits>

namespace huzlip::math {

class Random {
    std::mt19937 rng_;
    std::mutex mtx_;
public:
    Random();
    double uniform(double min, double max);
    int randint(int min, int max);
};

} // namespace huzlip::math