cmake_minimum_required(VERSION 3.13)
project(C2G)
set(CMAKE_CXX_STANDARD 14)

set(CMAKE_EXPORT_COMPILE_COMMANDS on)

set(CMAKE_PREFIX_PATH "/c/msys64/mingw64/x86_64-w64-mingw32/lib/cmake/glfw3")

find_package(glfw3 3.3 REQUIRED)
find_package(OpenGL REQUIRED)

add_subdirectory(Entity)
add_subdirectory(System)
add_subdirectory(Scene)

add_executable(C2G Main.cpp "${CMAKE_SOURCE_DIR}/../../glad/src/glad.c")

target_include_directories(C2G PUBLIC "${CMAKE_SOURCE_DIR}/../../glad/include/")

target_link_options(C2G PUBLIC -static-libgcc -static-libstdc++ -static) # -mwindows)
target_link_libraries(C2G Entity System Scene glfw OpenGL::GL)
