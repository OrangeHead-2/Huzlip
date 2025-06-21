cmake_minimum_required(VERSION 3.15)
project(huzlip LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Enable testing and code coverage
include(CTest)
option(HUZLIP_ENABLE_COVERAGE "Enable coverage support" OFF)

# huzlip library
add_subdirectory(src)

# Tests
enable_testing()
add_subdirectory(tests)

# Optional: Install targets
install(DIRECTORY include/ DESTINATION include)