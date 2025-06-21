#pragma once
#include <string>
#include <variant>
#include <optional>

namespace huzlip::templates {

using ParameterValue = std::variant<double, int, bool, std::string>;

class Parameter {
    std::string name_;
    ParameterValue value_;
public:
    Parameter(const std::string& name, const ParameterValue& value);
    std::string name() const { return name_; }
    ParameterValue value() const { return value_; }
    void setValue(const ParameterValue& val) { value_ = val; }
    template<typename T>
    std::optional<T> getAs() const {
        if (auto p = std::get_if<T>(&value_)) return *p;
        return std::nullopt;
    }
};

} // namespace huzlip::templates