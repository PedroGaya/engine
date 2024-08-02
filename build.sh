#!/bin/bash

echo "Building JC2D engine..."

cd ./build
cmake -DCMAKE_BUILD_TYPE=Debug ..
make -j8

echo "Done."