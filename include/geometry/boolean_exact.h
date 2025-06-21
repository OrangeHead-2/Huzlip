#pragma once
#include "mesh.h"
#include <string>

namespace huzlip::geometry {

enum class BooleanType { Union, Intersection, Difference, SymmetricDifference };

class ExactBooleanEngine {
public:
    static bool compute(const Mesh& a, const Mesh& b, BooleanType type, Mesh& out, std::string* errorMsg = nullptr);
};

} // namespace huzlip::geometry