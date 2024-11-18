#pragma once

#include <stdlib.h>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "log/log.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct ccgl_window
{ 
  GLFWwindow *handle;
} ccgl_window_t;

ccgl_window_t *ccgl_window_create(int width, int height, const char *title);

void ccgl_window_destroy(ccgl_window_t *window);

void ccgl_window_poll_events(void);

int ccgl_window_should_close(ccgl_window_t *window);

#ifdef __cplusplus
}
#endif
