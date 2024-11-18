#include "core/core.h"

int ccgl_init(void)
{
  if (!glfwInit())
  {
    _log(LL_INFO, "Failed to initialize GLFW");
    return -1;
  }

  _log(LL_INFO, "GLFW initialized successfully");
  return 0;
}

void ccgl_terminate(void)
{
  glfwTerminate();
  _log(LL_INFO, "GLWF terminated");
}
