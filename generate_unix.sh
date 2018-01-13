#!/bin/bash

ROOT=`pwd`
echo ${ROOT}
set PROJECT_PATH="${ROOT}/project"
echo ${PROJECT_PATH}
EXTRA_CMAKE_PARAMETERS=$1

if [ ! -d ${PROJECT_PATH} ]; then
    mkdir -p ${PROJECT_PATH}
fi

cd ${PROJECT_PATH}

cmake "../asteroids" -DMAX_ENTITIES=4096 -DMAX_TAGS=64 -DBUILD_SHARED_LIBS=0 ${EXTRA_CMAKE_PARAMETERS}
