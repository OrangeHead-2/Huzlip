#pragma once
#include "mesh.h"
#include <cstddef>

namespace huzlip::geometry {

class Remesher {
public:
    static void isotropicRemesh(Mesh& mesh, double targetLen, size_t iterations = 5);
    static void splitLongEdges(Mesh& mesh, double maxLen);
    static void collapseShortEdges(Mesh& mesh, double minLen);
    static void laplacianSmooth(Mesh& mesh, size_t iterations = 1, double lambda = 0.5);
    static size_t removeDegenerateFaces(Mesh& mesh, double areaTol = 1e-10);
    static size_t removeDuplicateVertices(Mesh& mesh, double tol = 1e-7);
};

} // namespace huzlip::geometry