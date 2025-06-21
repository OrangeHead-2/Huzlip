#include "doctest/doctest.h"
#include "geometry/vector3d.h"
#include "geometry/mesh.h"

using namespace huzlip::geometry;

TEST_CASE("Vector3D basic arithmetic") {
    Vector3D v1(1,2,3), v2(4,5,6);
    CHECK((v1 + v2).x == 5);
    CHECK((v1 - v2).y == -3);
    CHECK((v1 * 2).z == 6);
    CHECK((2 * v2).x == 8);
    CHECK(v1.dot(v2) == doctest::Approx(32));
    CHECK(v1.cross(v2).x == doctest::Approx(-3));
}

TEST_CASE("Mesh adjacency computation") {
    Mesh mesh;
    mesh.vertices = { {0,0,0}, {1,0,0}, {0,1,0} };
    mesh.faces = { {0,1,2} };
    mesh.computeAdjacency();
    CHECK(mesh.vertex_adjacency[0].size() == 2);
    CHECK(mesh.vertex_adjacency[1].size() == 2);
}