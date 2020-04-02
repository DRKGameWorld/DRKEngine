#pragma once

#include <vector>
#include <GL/glew.h>
#include <DRKEngine/shader.h>

namespace drk {
    class PrimitiveObject {
    public:
        PrimitiveObject();
        GLfloat* getVertices();
        void draw(Shader &shader);

    protected:
        std::vector<GLfloat> vertices;
        GLuint VAO = 0, VBO = 0;
    };

    class PrimitiveTriangle : public PrimitiveObject {
    public:
        PrimitiveTriangle();
    };
}