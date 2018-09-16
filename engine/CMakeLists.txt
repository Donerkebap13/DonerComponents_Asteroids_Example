cmake_minimum_required(VERSION 3.8)

include(${CMAKE_CURRENT_SOURCE_DIR}/../thirdparty/DonerComponents/cmake/utils.cmake)

set(project_name "Engine")

project("${project_name}")

set(third_party_path "${CMAKE_CURRENT_SOURCE_DIR}/../thirdparty")

add_subdirectory("${third_party_path}/DonerComponents/DonerComponents" "${CMAKE_BINARY_DIR}/DonerComponents")
add_subdirectory("${third_party_path}/SFML" "${CMAKE_BINARY_DIR}/SFML")

file(GLOB_RECURSE header_files "${CMAKE_CURRENT_SOURCE_DIR}/include/*.h")
file(GLOB_RECURSE source_files "${CMAKE_CURRENT_SOURCE_DIR}/source/*.cpp")

add_source_groups("${header_files}")
add_source_groups("${source_files}")

add_library("${project_name}" STATIC ${header_files} ${source_files})

target_include_directories("${project_name}" PUBLIC "include")
target_include_directories("${project_name}" PUBLIC "${third_party_path}/DonerComponents/DonerComponents/include")
target_include_directories("${project_name}" PUBLIC "${third_party_path}/SFML/include")

target_link_libraries("${project_name}" 
	"DonerComponents" 	
	"sfml-window"
	"sfml-system"
	"sfml-network"
	"sfml-graphics"
	"sfml-audio"
	)
	
add_definitions(-DSFML_STATIC)
target_compile_definitions("sfml-audio" PRIVATE _HAS_AUTO_PTR_ETC=1)

set_target_properties("${project_name}" PROPERTIES LINKER_LANGUAGE CXX)
add_definitions(-D_CRT_SECURE_NO_WARNINGS)

set_target_properties ("${project_name}" PROPERTIES FOLDER "DonerComponents")
