#include "primitives.h"

drk::PrimitiveObject::PrimitiveObject() {
    std::vector<GLfloat> vertices = {};
    this->init(vertices);
}

inline void drk::PrimitiveObject::init(std::vector<GLfloat> &v) {
    GLfloat vertices[v.size()];
    for (int i = 0; i < v.size(); i++) {
        vertices[i] = v[i];
    }

    glGenVertexArrays(1, &this->VAO);
    glGenBuffers(1, &this->VBO);

    glBindVertexArray(this->VAO);

    glBindBuffer(GL_ARRAY_BUFFER, this->VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*) nullptr);
    glEnableVertexAttribArray(0);

//    glBindBuffer(GL_ARRAY_BUFFER, 0);

    glBindVertexArray(0);
}

void drk::PrimitiveObject::draw(Shader &shader) {
    shader.use();
    glBindVertexArray(this->VAO);
    glDrawArrays(GL_TRIANGLES, 0, 3);
    glBindVertexArray(0);
}

drk::PrimitiveTriangle::PrimitiveTriangle() {
    std::vector<GLfloat>vertices = {
            -0.5f, -0.5f, 0.0f, // Left
             0.5f, -0.5f, 0.0f, // Right
             0.0f,  0.5f, 0.0f  // Top
    };
    this->init(vertices);
}
