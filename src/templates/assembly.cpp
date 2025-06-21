#include "templates/assembly.h"

/**
 * @file assembly.cpp
 * @brief Implements the Assembly class for organizing CAD component trees.
 */

namespace huzlip::templates {

Assembly::Assembly(std::shared_ptr<Component> rootComponent) 
    : root_(std::make_shared<ComponentTreeNode>(rootComponent)) {}

std::vector<std::shared_ptr<Component>> Assembly::allComponents() const {
    std::vector<std::shared_ptr<Component>> out;
    if (root_) root_->collectComponents(out);
    return out;
}

} // namespace huzlip::templates