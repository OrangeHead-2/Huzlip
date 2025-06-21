#pragma once
#include "mesh.h"
#include <unordered_set>
#include <vector>
#include <utility>
#include <queue>

namespace huzlip::geometry {

class TopologyUtils {
public:
    static std::vector<std::unordered_set<size_t>> connectedComponents(const Mesh& mesh);
    static std::vector<std::pair<size_t, size_t>> findBoundaryEdges(const Mesh& mesh);
    static bool isManifold(const Mesh& mesh);
    static void repairMesh(Mesh& mesh);
};

} // namespace huzlip::geometry