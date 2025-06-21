#include "templates/template.h"

/**
 * @file template.cpp
 * @brief Implements setParameter for Template base class.
 */

namespace huzlip::templates {

void Template::setParameter(const std::string& name, const ParameterValue& value) {
    for (auto& param : parameters_) {
        if (param.name() == name) {
            param.setValue(value);
            return;
        }
    }
}

} // namespace huzlip::templates