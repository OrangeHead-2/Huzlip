# Tests CMake for huzlip

add_executable(huzlip_tests
    test_main.cpp
    test_geometry.cpp
    test_utils.cpp
    test_templates.cpp
)

target_link_libraries(huzlip_tests PRIVATE huzlip)
target_include_directories(huzlip_tests PRIVATE ${PROJECT_SOURCE_DIR}/include)

add_test(NAME huzlip_tests COMMAND huzlip_tests)