#include "geometry/remesh.h"

/**
 * @file remesh.cpp
 * @brief Stub implementations for remeshing utilities.
 *        Actual remeshing algorithms are not implemented here.
 */

namespace huzlip::geometry {

void Remesher::isotropicRemesh(Mesh&, double, size_t) {
    // Not implemented
}

void Remesher::splitLongEdges(Mesh&, double) {
    // Not implemented
}

void Remesher::collapseShortEdges(Mesh&, double) {
    // Not implemented
}

void Remesher::laplacianSmooth(Mesh&, size_t, double) {
    // Not implemented
}

size_t Remesher::removeDegenerateFaces(Mesh&, double) {
    // Not implemented
    return 0;
}

size_t Remesher::removeDuplicateVertices(Mesh&, double) {
    // Not implemented
    return 0;
}

} // namespace huzlip::geometry