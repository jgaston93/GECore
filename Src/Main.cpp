#include <cstdio>
#include <chrono>
#include <thread>
#include <glad/glad.h>
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

#include "PhysicsSystem.hpp"

int main(int argc, char **argv)
{
  GLFWwindow *window;

  // Initialize the library
  if (!glfwInit())
    return -1;

  // Create a windowed mode window and its OpenGL context
  window = glfwCreateWindow(640, 480, "Hello World", nullptr, nullptr);
  if (!window)
  {
    glfwTerminate();
    return -1;
  }

  // Make the window's context current
  glfwMakeContextCurrent(window);
  gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);

  // Setup timing information
  std::chrono::time_point<std::chrono::system_clock> current_time = std::chrono::system_clock::now();
  std::chrono::time_point<std::chrono::system_clock> previous_time = current_time;
  unsigned long frame_rate = 60;
  std::chrono::seconds delta_time(1 / frame_rate);

  // Loop until the user closes the window
  while (!glfwWindowShouldClose(window))
  {
    current_time = std::chrono::system_clock::now();
    std::chrono::milliseconds dt = std::chrono::duration_cast<std::chrono::milliseconds>(current_time - previous_time);

    // Render here
    glClear(GL_COLOR_BUFFER_BIT);

    // Swap front and back buffers
    glfwSwapBuffers(window);

    // Poll for and process events
    glfwPollEvents();

    previous_time = current_time;
    std::this_thread::sleep_until(current_time + delta_time);
  }

  glfwTerminate();
  return 0;
}
