#!/bin/bash
# Format all C++ source and header files in the project

find ../src ../include ../tests -regex '.*\.\(cpp\|h\)$' -exec clang-format -i {} +
echo "Formatting complete."