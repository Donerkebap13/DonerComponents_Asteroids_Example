#!/bin/bash

set PROJECT_FOLDER=".\project"
EXTRA_CMAKE_PARAMETERS=$1

if [ ! -d ${PROJECT_FOLDER} ]; then
    mkdir -p ${PROJECT_FOLDER}
fi

cd ${PROJECT_FOLDER}

cmake "..\asteroids" -DMAX_ENTITIES=4096 -DMAX_TAGS=64 -DBUILD_SHARED_LIBS=0 ${EXTRA_CMAKE_PARAMETERS}
