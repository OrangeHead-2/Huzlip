# Huzlip

Advanced C++ Geometry & CAD Library

## Features

- 3D vector math, mesh data structures, subdivision, remeshing, spatial indexing (BVH)
- Assembly, templating, and parameterization for CAD workflows
- Utilities: logging, configuration, profiling, robust file system support
- Modern C++20 API, modular design, production-ready

## Quick Start

```sh
git clone https://github.com/OrangeHead-2/Huzlip.git
cd Huzlip/scripts
./build.sh
./run_tests.sh
```

## Directory Layout

- `src/` — Core library source files
- `include/` — Public headers
- `tests/` — Unit/integration tests (doctest)
- `scripts/` — Build, lint, format, coverage scripts
- `docs/` — Detailed documentation

## Building

Requires CMake 3.15+, C++20 compiler.  
All dependencies are handled via system packages or submodules.

## Running Tests

```sh
cd scripts
./run_tests.sh
```

## Documentation

- [docs/architecture.md](docs/architecture.md)
- [docs/api/geometry.md](docs/api/geometry.md)
- [docs/api/templates.md](docs/api/templates.md)
- [docs/api/utils.md](docs/api/utils.md)

## License

Copyright (c) 2025 huzlip authors  
Licensed under the MIT License.
