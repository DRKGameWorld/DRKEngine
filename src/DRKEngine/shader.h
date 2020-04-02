#pragma once

#include "filesystem.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
//#include <iostream>
//#include <string>

namespace drk {
    class Shader {
    public:
        Shader(FilePath vertex_path, FilePath fragment_path);
        void use();

    private:
        GLuint program;
    };
}