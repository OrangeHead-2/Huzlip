#pragma once
#include <string>
#include <unordered_map>

namespace huzlip::utils {

class Config {
    std::unordered_map<std::string, std::string> kv_;
public:
    void set(const std::string& key, const std::string& value) { kv_[key] = value; }
    std::string get(const std::string& key, const std::string& def = "") const {
        auto it = kv_.find(key);
        return it != kv_.end() ? it->second : def;
    }
    bool contains(const std::string& key) const { return kv_.count(key) > 0; }
};

} // namespace huzlip::utils