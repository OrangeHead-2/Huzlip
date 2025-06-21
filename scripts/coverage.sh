#!/bin/bash
# Generate code coverage report

cd ../build
cmake .. -DHUZLIP_ENABLE_COVERAGE=ON
make -j$(nproc)
lcov --capture --directory . --output-file coverage.info
genhtml coverage.info --output-directory coverage_html
echo "Coverage report generated in build/coverage_html/index.html"