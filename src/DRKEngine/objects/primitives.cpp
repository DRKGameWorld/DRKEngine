#include "primitives.h"

drk::PrimitiveObject::PrimitiveObject() {
    glGenVertexArrays(1, &this->VAO);
    glGenBuffers(1, &this->VBO);

    glBindVertexArray(this->VAO);

    glBindBuffer(GL_ARRAY_BUFFER, this->VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(this->getVertices()), this->getVertices(), GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*) nullptr);
    glEnableVertexAttribArray(0);

//    glBindBuffer(GL_ARRAY_BUFFER, 0);

    glBindVertexArray(0);
}

GLfloat * drk::PrimitiveObject::getVertices() {
    return this->vertices.data();
}

void drk::PrimitiveObject::draw(Shader &shader) {
    shader.use();
    glBindVertexArray(this->VAO);
    glDrawArrays(GL_TRIANGLES, 0, 3);
    glBindVertexArray(0);
}

drk::PrimitiveTriangle::PrimitiveTriangle() : PrimitiveObject() {
    this->vertices = {
            -0.5, -0.5, 0.0,
             0.5, -0.5, 0.0,
             0.0,  0.5, 0.0
    };
}
