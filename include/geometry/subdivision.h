#pragma once
#include "mesh.h"
#include <cstddef>

namespace huzlip::geometry {

class Subdivision {
public:
    static void loopSubdivision(Mesh& mesh, size_t iterations = 1);
    static void catmullClarkSubdivision(Mesh& mesh, size_t iterations = 1);
};

} // namespace huzlip::geometry