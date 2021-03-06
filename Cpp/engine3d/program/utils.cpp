#include <stdio.h>
#include "utils.h"

using namespace engine3d;

const std::string Utils::InfoLog(GLuint object,
		PFNGLGETSHADERIVPROC glGet__iv,
		PFNGLGETSHADERINFOLOGPROC glGet__InfoLog) {
    GLint log_length;
    glGet__iv(object, GL_INFO_LOG_LENGTH, &log_length);
    char log[log_length];
    glGet__InfoLog(object, log_length, NULL, log);
    return std::string(log);
}
