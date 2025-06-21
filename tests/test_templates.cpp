#include "doctest/doctest.h"
#include "templates/parameter.h"
#include "templates/component.h"
#include "templates/component_tree.h"
#include "templates/assembly.h"

using namespace huzlip::templates;

class DummyComponent : public Component {
public:
    DummyComponent(const std::string& name) : Component(name) {}
    std::shared_ptr<Component> clone() const override {
        return std::make_shared<DummyComponent>(*this);
    }
};

TEST_CASE("Parameter stores values") {
    Parameter p("foo", 42);
    CHECK(p.name() == "foo");
    CHECK(p.getAs<int>() == 42);
}

TEST_CASE("Assembly collects all components") {
    auto root = std::make_shared<DummyComponent>("root");
    Assembly assembly(root);
    auto comps = assembly.allComponents();
    CHECK(comps.size() == 1);
    CHECK(comps[0]->name() == "root");
}