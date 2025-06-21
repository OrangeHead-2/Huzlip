#pragma once
#include "vector3d.h"
#include <algorithm>

namespace huzlip::geometry {

class AABB {
public:
    Vector3D min;
    Vector3D max;

    AABB();
    AABB(const Vector3D& mn, const Vector3D& mx);
    void expand(const Vector3D& p);
    void expand(const AABB& other);
    bool overlaps(const AABB& other) const;
    bool contains(const Vector3D& p) const;
};

} // namespace huzlip::geometry