cmake_minimum_required(VERSION 3.13)
project(Core)
set(CMAKE_CXX_STANDARD 14)

set(CMAKE_EXPORT_COMPILE_COMMANDS on)

find_package(glfw3 3.3 REQUIRED)
find_package(OpenGL REQUIRED)

add_subdirectory(Entity)
add_subdirectory(Component)
add_subdirectory(System)
add_subdirectory(Scene)

add_library(Core "${CMAKE_SOURCE_DIR}/../../glad/src/glad.c")

target_include_directories(Core PUBLIC "${CMAKE_SOURCE_DIR}/../../glad/include/")

target_link_options(Core PUBLIC -static-libgcc -static-libstdc++ -static) # -mwindows)
target_link_libraries(Core Entity Component System Scene glfw OpenGL::GL)
