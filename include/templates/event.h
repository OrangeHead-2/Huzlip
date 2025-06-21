#pragma once
#include <functional>
#include <vector>
#include <mutex>

namespace huzlip::templates {

template<typename... Args>
class Event {
    std::vector<std::function<void(Args...)>> listeners_;
    std::mutex mtx_;
public:
    void connect(std::function<void(Args...)> slot) {
        std::lock_guard<std::mutex> lock(mtx_);
        listeners_.push_back(std::move(slot));
    }
    void emit(Args... args) {
        std::lock_guard<std::mutex> lock(mtx_);
        for (auto& fn : listeners_)
            fn(args...);
    }
};

} // namespace huzlip::templates