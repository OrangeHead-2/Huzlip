#include "templates/parameter.h"

/**
 * @file parameter.cpp
 * @brief Implements Parameter abstraction for CAD templates.
 */

namespace huzlip::templates {

Parameter::Parameter(const std::string& name, const ParameterValue& value)
    : name_(name), value_(value) {}

} // namespace huzlip::templates