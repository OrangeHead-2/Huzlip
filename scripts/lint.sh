#!/bin/bash
# Lint source files using clang-tidy

SRC_DIRS="../src ../include"
for dir in $SRC_DIRS; do
    find $dir -name '*.cpp' -or -name '*.h' | xargs clang-tidy -p ../build
done