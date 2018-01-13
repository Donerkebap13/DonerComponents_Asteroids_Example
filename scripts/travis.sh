#!/bin/bash

sh generate_unix.sh
cd "project"

./configure --enable-gcov
make VERBOSE=1 -j8
