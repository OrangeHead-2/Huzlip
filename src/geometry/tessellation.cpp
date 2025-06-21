#include "geometry/tessellation.h"

/**
 * @file tessellation.cpp
 * @brief Implements tessellation for curves (polyline mesh).
 */

namespace huzlip::geometry {

Mesh Tessellation::tessellateCurve(const Curve& curve, int segments) {
    Mesh mesh;
    auto pts = curve.discretize(segments);
    mesh.vertices = pts;
    for (size_t i = 1; i < pts.size(); ++i)
        mesh.faces.push_back({i - 1, i});
    return mesh;
}

} // namespace huzlip::geometry