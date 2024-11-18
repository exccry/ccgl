#include "core/core.h"
#include "window/window.h"

int main(void)
{
  if (ccgl_init() != 0)
  {
    return EXIT_FAILURE;
  }

  ccgl_window_t *window = ccgl_window_create(800, 800, "Crisp Graphics Library");
  if (!window)
  {
    ccgl_terminate();
    return EXIT_FAILURE;
  }

  while (!ccgl_window_should_close(window))
  {
    glClear(GL_COLOR_BUFFER_BIT);

    glfwSwapBuffers(window->handle);
    ccgl_window_poll_events();
  }

  ccgl_window_destroy(window);
  ccgl_terminate();
  return EXIT_SUCCESS;
}
