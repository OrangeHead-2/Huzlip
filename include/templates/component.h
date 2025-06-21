#pragma once
#include <string>
#include <memory>
#include <unordered_map>

namespace huzlip::templates {

class Component {
protected:
    std::string name_;
    std::unordered_map<std::string, std::string> properties_;
public:
    explicit Component(const std::string& name);
    virtual ~Component();
    std::string name() const { return name_; }
    void setProperty(const std::string& key, const std::string& value);
    std::string getProperty(const std::string& key) const;
    std::vector<std::string> propertyKeys() const;
    virtual std::shared_ptr<Component> clone() const = 0;
};

} // namespace huzlip::templates