cmake_minimum_required(VERSION 3.8)

include(${CMAKE_CURRENT_SOURCE_DIR}/../thirdparty/DonerECS/cmake/utils.cmake)

set(project_name "DonerECS_Asteroids")

project("${project_name}")

add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/../engine" "${CMAKE_BINARY_DIR}/Engine")

file(GLOB_RECURSE header_files "${CMAKE_CURRENT_SOURCE_DIR}/include/*.h")
file(GLOB_RECURSE source_files "${CMAKE_CURRENT_SOURCE_DIR}/source/*.cpp")

add_source_groups("${header_files}")
add_source_groups("${source_files}")

include_directories ("include")
include_directories ("${CMAKE_CURRENT_SOURCE_DIR}/../engine/include")
add_executable("${project_name}" ${header_files} ${source_files})

target_link_libraries("${project_name}" "Engine")

set_target_properties("${project_name}" PROPERTIES LINKER_LANGUAGE CXX)
set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT "${project_name}")
add_definitions(-D_CRT_SECURE_NO_WARNINGS)

set_target_properties("${project_name}" PROPERTIES VS_DEBUGGER_WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}/../")
set_target_properties ("${project_name}" PROPERTIES FOLDER "${project_name}")
