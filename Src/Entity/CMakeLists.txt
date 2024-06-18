add_library(Entity EntityManager.cpp)

target_include_directories(Entity PUBLIC "${CMAKE_SOURCE_DIR}/Component")