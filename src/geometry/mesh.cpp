#include "geometry/mesh.h"
#include <set>
#include <algorithm>

/**
 * @file mesh.cpp
 * @brief Implements adjacency computation for Mesh class.
 *        Calculates per-vertex adjacency for efficient mesh operations.
 */

namespace huzlip::geometry {

void Mesh::computeAdjacency() {
    vertex_adjacency.clear();
    vertex_adjacency.resize(vertices.size());
    for (const auto& face : faces) {
        size_t n = face.size();
        for (size_t i = 0; i < n; ++i) {
            size_t vi = face[i];
            size_t vj = face[(i+1)%n];
            if (vi < vertex_adjacency.size() && vj < vertex_adjacency.size()) {
                if (std::find(vertex_adjacency[vi].begin(), vertex_adjacency[vi].end(), vj) == vertex_adjacency[vi].end())
                    vertex_adjacency[vi].push_back(vj);
                if (std::find(vertex_adjacency[vj].begin(), vertex_adjacency[vj].end(), vi) == vertex_adjacency[vj].end())
                    vertex_adjacency[vj].push_back(vi);
            }
        }
    }
}

} // namespace huzlip::geometry