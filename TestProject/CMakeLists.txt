cmake_minimum_required(VERSION 3.13)
project(TestProject)
set(CMAKE_CXX_STANDARD 14)

set(CMAKE_EXPORT_COMPILE_COMMANDS on)

find_package(glfw3 3.3 REQUIRED)
find_package(OpenGL REQUIRED)

add_library(Core STATIC IMPORTED)
set_target_properties(Core PROPERTIES
IMPORTED_LOCATION "../GECore/CoreBuild/libCore.a")

add_executable(TestProject main.cpp)

target_include_directories(TestProject PUBLIC
"../GECore/Core/Src/../../glad/include/"
"../GECore/Core/Src"
"../GECore/Core/Src/Entity")

target_link_libraries(TestProject Core glfw)

file(COPY ${CMAKE_SOURCE_DIR}/textures/ DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/textures/)