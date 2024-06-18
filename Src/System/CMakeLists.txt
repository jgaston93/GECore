add_library(System SystemManager.cpp PhysicsSystem.cpp)

target_include_directories(System PUBLIC "${CMAKE_SOURCE_DIR}")