#include "geometry/aabb.h"

/**
 * @file aabb.cpp
 * @brief Implements the Axis-Aligned Bounding Box (AABB) class for geometry.
 *        Used for collision, spatial queries, and BVH construction.
 */

#include <limits>

namespace huzlip::geometry {

AABB::AABB()
    : min(Vector3D(std::numeric_limits<double>::max(),
                   std::numeric_limits<double>::max(),
                   std::numeric_limits<double>::max())),
      max(Vector3D(-std::numeric_limits<double>::max(),
                   -std::numeric_limits<double>::max(),
                   -std::numeric_limits<double>::max())) {}

AABB::AABB(const Vector3D& mn, const Vector3D& mx)
    : min(mn), max(mx) {}

void AABB::expand(const Vector3D& p) {
    min.x = std::min(min.x, p.x); min.y = std::min(min.y, p.y); min.z = std::min(min.z, p.z);
    max.x = std::max(max.x, p.x); max.y = std::max(max.y, p.y); max.z = std::max(max.z, p.z);
}

void AABB::expand(const AABB& other) {
    expand(other.min);
    expand(other.max);
}

bool AABB::overlaps(const AABB& other) const {
    return (min.x <= other.max.x && max.x >= other.min.x) &&
           (min.y <= other.max.y && max.y >= other.min.y) &&
           (min.z <= other.max.z && max.z >= other.min.z);
}

bool AABB::contains(const Vector3D& p) const {
    return (p.x >= min.x && p.x <= max.x) &&
           (p.y >= min.y && p.y <= max.y) &&
           (p.z >= min.z && p.z <= max.z);
}

} // namespace huzlip::geometry