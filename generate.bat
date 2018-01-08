@echo off

set project_folder=".\projects"
set root=%cd%
set extra_cmake_parameters=%1

IF NOT EXIST %project_folder% (
    mkdir %project_folder%
)

cd %project_folder%

cmake "..\asteroids" -DMAX_ENTITIES=4096 -DMAX_TAGS=64 -DBUILD_STATIC_LIBS=1 -DBUILD_SHARED_LIBS=0

cd %root%
