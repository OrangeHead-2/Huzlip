# Geometry API

## Vector3D

- 3D vector math with operators, dot/cross, normalization.

## Mesh

- Vertex, face, and adjacency storage.
- `computeAdjacency()` for per-vertex neighborhood queries.

## AABB/BVH

- Axis-aligned bounding box, bounding volume hierarchy for fast spatial queries.

## Remesher, Subdivision, Topology

- Utilities for mesh refinement, smoothing, and analysis.

## Usage Example

```cpp
using namespace huzlip::geometry;
Mesh mesh;
// ... populate mesh ...
mesh.computeAdjacency();
```

See source headers for full details.