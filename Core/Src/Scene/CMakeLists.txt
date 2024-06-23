add_library(Scene Scene.cpp SceneManager.cpp)

target_include_directories(Scene PUBLIC "${CMAKE_SOURCE_DIR}" "${CMAKE_SOURCE_DIR}/Entity")
