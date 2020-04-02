#pragma once

#include <vector>
#include <GL/glew.h>
#include <DRKEngine/shader.h>

namespace drk {
    class PrimitiveObject {
    public:
        PrimitiveObject();
        void init(std::vector<GLfloat> &vertices);
        void draw(Shader &shader);

    protected:
        GLuint VAO = 0, VBO = 0;
    };

    class PrimitiveTriangle : public PrimitiveObject {
    public:
        PrimitiveTriangle();

    protected:

    };
}