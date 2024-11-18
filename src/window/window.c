#include "window/window.h"


ccgl_window_t *ccgl_window_create(int width, int height, const char *title)
{
  ccgl_window_t *window = malloc(sizeof(ccgl_window_t));
  if (!window)
  {
    _log(LL_ERROR, "Failed to allocate memory for window");
    return NULL;
  }

  window->handle = glfwCreateWindow(width, height, title, NULL, NULL);
  if (!window->handle)
  {
    _log(LL_INFO, "Failed to create GLFW window");
    free(window);
    return NULL;
  }

  glfwMakeContextCurrent(window->handle);

  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
  {
    _log(LL_ERROR, "Failed to initialize GLAD");
    return NULL;
  }

  _log(LL_INFO, "Window created successfully");
  return window;
}

void ccgl_window_destroy(ccgl_window_t *window)
{
  if (window)
  {
    glfwDestroyWindow(window->handle);
    free(window);
    _log(LL_INFO, "Window destroyed");
  }
}

void ccgl_window_poll_events(void)
{
  glfwPollEvents();
}

int ccgl_window_should_close(ccgl_window_t *window)
{
  return glfwWindowShouldClose(window->handle);
}
