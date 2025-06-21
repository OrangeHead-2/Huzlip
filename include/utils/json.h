#pragma once
#include <string>
#include <map>
#include <vector>
#include <variant>
#include <optional>

namespace huzlip::utils {

using JsonValue = std::variant<
    std::nullptr_t, 
    bool, 
    int, 
    double, 
    std::string, 
    std::vector<std::variant<std::nullptr_t, bool, int, double, std::string>>, 
    std::map<std::string, std::variant<std::nullptr_t, bool, int, double, std::string>>
>;

class Json {
public:
    static std::optional<JsonValue> parse(const std::string& jsonStr);
    static std::string stringify(const JsonValue& value);
};

} // namespace huzlip::utils