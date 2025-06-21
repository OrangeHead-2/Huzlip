#pragma once
#include <vector>
#include <memory>
#include "vector3d.h"
#include <limits>

namespace huzlip::geometry {

struct BVHNode {
    Vector3D min, max;
    std::vector<size_t> primitiveIndices;
    std::unique_ptr<BVHNode> left, right;
    BVHNode(const Vector3D& mi, const Vector3D& ma) : min(mi), max(ma) {}
};

class BVH {
    std::unique_ptr<BVHNode> root_;
    void buildRecursive(BVHNode* node, const std::vector<Vector3D>& points, size_t depth);
public:
    BVH(const std::vector<Vector3D>& points);
    std::vector<size_t> query(const Vector3D& min, const Vector3D& max) const;
};

} // namespace huzlip::geometry