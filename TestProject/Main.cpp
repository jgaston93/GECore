#include <cstdio>
#include <chrono>
#include <thread>
#include <string.h>
#include <glad/glad.h>
#define GLFW_INCLUDE_NONE
#include <GLFW/glfw3.h>

#include "Scene/SceneManager.hpp"
#include "System/SystemManager.hpp"
#include "Texture/TextureManager.hpp"
#include "Input/InputManager.hpp"

#include "Scripts/TestScript.hpp"


void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
  InputKey k = getInputKey(key);

  if(k != InputKey::Max)
  {
    if(action == GLFW_PRESS)
    {
      InputManager::setKey(k, true);
    }
    else if (action == GLFW_RELEASE)
    {
      InputManager::setKey(k, false);
    }
  }
}

int main(int argc, char **argv)
{
  GLFWwindow *window;

  // Initialize the library
  if (!glfwInit())
    return -1;

  // Create a windowed mode window and its OpenGL context
  window = glfwCreateWindow(640, 480, "TestProject", nullptr, nullptr);
  if (!window)
  {
    glfwTerminate();
    return -1;
  }

  // Make the window's context current
  glfwMakeContextCurrent(window);
  gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
  glfwSetKeyCallback(window, key_callback);
  
  char texture_filepath[256];
  strcpy(texture_filepath, argv[0]);
  unsigned long length = strlen(texture_filepath);
  while (length > 0 && texture_filepath[length] != '\\')
  {
    length--;
  }
  texture_filepath[length + 1] = '\0';

  char texture_filename[256];

  
  strcpy(texture_filename, texture_filepath);
  strcat(texture_filename, "Textures/TestTexture.png");
  TextureManager::loadTexture("TestTexture", texture_filename);
  

  SystemManager system_manager;

  EntityManager *entity_manager = nullptr;
  ComponentManager *component_manager = nullptr;
  Entity entity = 0;
  Signature signature = 0;
  
  Scene scene_0(0);
  entity_manager = scene_0.getEntityManager();
  component_manager = scene_0.getComponentManager();
  
  entity = entity_manager->createEntity();
  signature = 0;
  
  
  signature |= POSITION_SIGNATURE_MASK;
  Position position;
  position.x = 0;
  position.y = 0.3;
  position.z = 0;
  component_manager->addComponent(entity, position);
  
  signature |= ROTATION_SIGNATURE_MASK;
  Rotation rotation;
  rotation.x = 0;
  rotation.y = 0;
  rotation.z = 0;
  component_manager->addComponent(entity, rotation);
  
  signature |= SCALE_SIGNATURE_MASK;
  Scale scale;
  scale.x = 0;
  scale.y = 0;
  scale.z = 0;
  component_manager->addComponent(entity, scale);
  
  signature |= BOUNDINGBOX_SIGNATURE_MASK;
  BoundingBox boundingbox;
  boundingbox.x = 1;
  boundingbox.y = 0.5;
  boundingbox.z = 0;
  component_manager->addComponent(entity, boundingbox);
  
  signature |= TEXTURE_SIGNATURE_MASK;
  Texture texture;
  strcpy(texture.texture_name, "TestTexture");
  texture.x = 0.0;
  texture.y = 0.0;
  texture.u = 0.1953125;
  texture.v = 0.09765625;
  component_manager->addComponent(entity, texture);
  
  signature |= COORDINATEREFERENCE_SIGNATURE_MASK;
  CoordinateReference coordinatereference;
  coordinatereference.coordinate_space = CoordinateSpace::Screen;
  component_manager->addComponent(entity, coordinatereference);
  
  signature |= SCRIPT_SIGNATURE_MASK;
  Script script;
  script.script = new TestScript(0);
  component_manager->addComponent(entity, script);
  
  
  entity_manager->setSignature(entity, signature);
  
  SceneManager::getSceneManager()->addScene(&scene_0);
  

  system_manager.init();

  SceneManager::getSceneManager()->setSystemManager(&system_manager);
  SceneManager::getSceneManager()->loadScene(0);


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
    
    system_manager.update(dt.count());

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