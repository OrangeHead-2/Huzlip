#pragma once
#include <memory>
#include <vector>
#include <string>
#include "component.h"

namespace huzlip::templates {

class ComponentTreeNode : public std::enable_shared_from_this<ComponentTreeNode> {
    std::shared_ptr<Component> component_;
    std::vector<std::shared_ptr<ComponentTreeNode>> children_;
    std::weak_ptr<ComponentTreeNode> parent_;
public:
    explicit ComponentTreeNode(std::shared_ptr<Component> comp);
    void addChild(std::shared_ptr<ComponentTreeNode> child);
    void setParent(std::shared_ptr<ComponentTreeNode> parent);
    std::shared_ptr<ComponentTreeNode> parent() const;
    std::shared_ptr<Component> component() const { return component_; }
    const std::vector<std::shared_ptr<ComponentTreeNode>>& children() const { return children_; }
    void collectComponents(std::vector<std::shared_ptr<Component>>& out) const;
};

} // namespace huzlip::templates