#pragma once
#include <vector>
#include "vector3d.h"

namespace huzlip::geometry {

class Mesh {
public:
    std::vector<Vector3D> vertices;
    std::vector<std::vector<size_t>> faces;
    std::vector<std::vector<size_t>> vertex_adjacency;

    void clear() {
        vertices.clear();
        faces.clear();
        vertex_adjacency.clear();
    }

    void computeAdjacency();
};

} // namespace huzlip::geometry