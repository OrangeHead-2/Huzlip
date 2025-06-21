#include "math/random.h"
#include <random>
#include <chrono>

/**
 * @file random.cpp
 * @brief Implements thread-safe random number generation.
 */

namespace huzlip::math {

Random::Random() {
    std::random_device rd;
    auto seed = static_cast<unsigned int>(std::chrono::high_resolution_clock::now().time_since_epoch().count());
    rng_.seed(seed ^ rd());
}

double Random::uniform(double min, double max) {
    std::lock_guard<std::mutex> lock(mtx_);
    std::uniform_real_distribution<double> dist(min, max);
    return dist(rng_);
}

int Random::randint(int min, int max) {
    std::lock_guard<std::mutex> lock(mtx_);
    std::uniform_int_distribution<int> dist(min, max);
    return dist(rng_);
}

} // namespace huzlip::math