#!/bin/bash
# Build the huzlip project

set -e
mkdir -p ../build
cd ../build
cmake ..
make -j$(nproc)