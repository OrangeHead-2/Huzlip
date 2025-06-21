#pragma once
#include "vector3d.h"
#include <vector>

namespace huzlip::geometry {

class Surface {
public:
    virtual ~Surface() = default;
    virtual Vector3D eval(double u, double v) const = 0;
    virtual std::vector<std::vector<Vector3D>> discretize(int uSeg, int vSeg) const = 0;
};

} // namespace huzlip::geometry