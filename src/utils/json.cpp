#include "utils/json.h"

/**
 * @file json.cpp
 * @brief Minimal stub for JSON parsing and stringification.
 *        For production use, prefer a full JSON library (e.g. nlohmann/json).
 */

namespace huzlip::utils {

std::optional<JsonValue> Json::parse(const std::string& jsonStr) {
    // Stub: Parsing not implemented, return empty
    (void)jsonStr;
    return std::nullopt;
}

std::string Json::stringify(const JsonValue& value) {
    // Stub: Stringify not implemented, return empty
    (void)value;
    return "";
}

} // namespace huzlip::utils