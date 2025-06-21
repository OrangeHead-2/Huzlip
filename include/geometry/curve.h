#pragma once
#include "vector3d.h"
#include <vector>

namespace huzlip::geometry {

class Curve {
public:
    virtual ~Curve() = default;
    virtual std::vector<Vector3D> discretize(int segments) const = 0;
    virtual Vector3D eval(double t) const = 0;
};

} // namespace huzlip::geometry