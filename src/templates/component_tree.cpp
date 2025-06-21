#include "templates/component_tree.h"

/**
 * @file component_tree.cpp
 * @brief Implements the ComponentTreeNode class for hierarchical CAD assemblies.
 */

namespace huzlip::templates {

ComponentTreeNode::ComponentTreeNode(std::shared_ptr<Component> comp)
    : component_(std::move(comp)) {}

void ComponentTreeNode::addChild(std::shared_ptr<ComponentTreeNode> child) {
    children_.push_back(child);
    child->setParent(shared_from_this());
}

void ComponentTreeNode::setParent(std::shared_ptr<ComponentTreeNode> parent) {
    parent_ = parent;
}

std::shared_ptr<ComponentTreeNode> ComponentTreeNode::parent() const {
    return parent_.lock();
}

void ComponentTreeNode::collectComponents(std::vector<std::shared_ptr<Component>>& out) const {
    if (component_) out.push_back(component_);
    for (const auto& child : children_)
        child->collectComponents(out);
}

} // namespace huzlip::templates