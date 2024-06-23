add_library(System
PhysicsSystem.cpp
UISystem.cpp
)

target_include_directories(System PUBLIC "${CMAKE_SOURCE_DIR}")