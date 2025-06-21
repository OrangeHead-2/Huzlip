#include "templates/component.h"

/**
 * @file component.cpp
 * @brief Implements the Component base class for CAD assemblies.
 *        Manages name, properties, and property access methods.
 */

namespace huzlip::templates {

Component::Component(const std::string& name) : name_(name) {}

Component::~Component() = default;

void Component::setProperty(const std::string& key, const std::string& value) {
    properties_[key] = value;
}

std::string Component::getProperty(const std::string& key) const {
    auto it = properties_.find(key);
    return it != properties_.end() ? it->second : "";
}

std::vector<std::string> Component::propertyKeys() const {
    std::vector<std::string> keys;
    for (const auto& kv : properties_)
        keys.push_back(kv.first);
    return keys;
}

} // namespace huzlip::templates