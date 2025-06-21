#pragma once
#include "mesh.h"
#include "curve.h"

namespace huzlip::geometry {

class Tessellation {
public:
    static Mesh tessellateCurve(const Curve& curve, int segments);
};

} // namespace huzlip::geometry