# huzlip Architecture

## Overview

huzlip is structured into modular domains:

- `geometry/` — Core geometric primitives and spatial data structures
- `templates/` — CAD component modeling, assembly, and parameterization
- `utils/` — Logging, configuration, profiling, and filesystem helpers

## Design Principles

- **Modularity:** Each domain is independently testable and reusable.
- **Extensibility:** Virtual base classes for curves, surfaces, and components.
- **Performance:** Inline math, cache-friendly structures, modern C++ idioms.

## Dependencies

- C++20 STL
- [doctest](https://github.com/doctest/doctest) for testing

## Build Flow

1. Configure with CMake
2. Compile with your C++20 compiler
3. Run tests and generate documentation

## Extending huzlip

- Add new geometry types in `geometry/`
- Implement new CAD templates in `templates/`
- Utilities are reusable across all modules

See the [API documentation](api/) for details.