#pragma once
#include "component_tree.h"

namespace huzlip::templates {

class Assembly {
    std::shared_ptr<ComponentTreeNode> root_;
public:
    explicit Assembly(std::shared_ptr<Component> rootComponent);
    std::shared_ptr<ComponentTreeNode> root() const { return root_; }
    std::vector<std::shared_ptr<Component>> allComponents() const;
};

} // namespace huzlip::templates