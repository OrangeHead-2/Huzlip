#pragma once
#include <vector>
#include <memory>
#include "parameter.h"
#include "component.h"

namespace huzlip::templates {

class Template {
protected:
    std::vector<Parameter> parameters_;
public:
    virtual ~Template() = default;
    const std::vector<Parameter>& parameters() const { return parameters_; }
    void setParameter(const std::string& name, const ParameterValue& value);
    virtual std::shared_ptr<Component> build() const = 0;
};

} // namespace huzlip::templates