#include "geometry/bvh.h"
#include <algorithm>
#include <limits>

/**
 * @file bvh.cpp
 * @brief Implements the BVH class for spatial queries on 3D point sets.
 *        Stub for more advanced use.
 */

namespace huzlip::geometry {

BVH::BVH(const std::vector<Vector3D>& points) {
    if (points.empty()) return;
    Vector3D min = points[0], max = points[0];
    for (const auto& p : points) {
        min.x = std::min(min.x, p.x); min.y = std::min(min.y, p.y); min.z = std::min(min.z, p.z);
        max.x = std::max(max.x, p.x); max.y = std::max(max.y, p.y); max.z = std::max(max.z, p.z);
    }
    root_ = std::make_unique<BVHNode>(min, max);
    root_->primitiveIndices.resize(points.size());
    for (size_t i = 0; i < points.size(); ++i)
        root_->primitiveIndices[i] = i;
}

void BVH::buildRecursive(BVHNode*, const std::vector<Vector3D>&, size_t) {
    // Not implemented: stub for subdivision
}

std::vector<size_t> BVH::query(const Vector3D& min, const Vector3D& max) const {
    // Not implemented: returns all indices for now
    if (!root_) return {};
    return root_->primitiveIndices;
}

} // namespace huzlip::geometry