#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "log/log.h"

#ifdef __cplusplus
extern "C" {
#endif

int ccgl_init(void);

void ccgl_terminate(void);

#ifdef __cplusplus
}
#endif
