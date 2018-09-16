@echo off

set project_folder=".\project"
set root=%cd%
set extra_cmake_parameters=%1

IF NOT EXIST %project_folder% (
    mkdir %project_folder%
)

cd %project_folder%

cmake "..\asteroids" -DMAX_GAME_OBJECTS=4096 -DMAX_TAGS=64 -DBUILD_SHARED_LIBS=0 %extra_cmake_parameters%

cd %root%
