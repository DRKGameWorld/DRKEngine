#include <sstream>
#include <glm/gtc/type_ptr.hpp>
#include <fstream>
#include <string>
#include "shader.h"

drk::Shader::Shader(drk::FilePath vertex_path, drk::FilePath fragment_path) {
    // 1. Получаем исходный код шейдера из filePath
    std::string vertexCode;
    std::string fragmentCode;
    std::ifstream vShaderFile;
    std::ifstream fShaderFile;
    // Удостоверимся, что ifstream объекты могут выкидывать исключения
    vShaderFile.exceptions(std::ifstream::badbit);
    fShaderFile.exceptions(std::ifstream::badbit);
    try {
        // Открываем файлы
        vShaderFile.open(vertex_path.systemPath());
        fShaderFile.open(fragment_path.systemPath());
        std::stringstream vShaderStream, fShaderStream;
        // Считываем данные в потоки
        vShaderStream << vShaderFile.rdbuf();
        fShaderStream << fShaderFile.rdbuf();
        // Закрываем файлы
        vShaderFile.close();
        fShaderFile.close();
        // Преобразовываем потоки в массив GLchar
        vertexCode = vShaderStream.str();
        fragmentCode = fShaderStream.str();
    } catch (std::ifstream::failure &e) {
        std::cout << "Error: can't read shader source file" << std::endl;
    }
    const GLchar *vShaderCode = vertexCode.c_str();
    const GLchar *fShaderCode = fragmentCode.c_str();
    // 2. Сборка шейдеров
    GLuint vertex, fragment;
    GLint success;
    GLchar infoLog[512];

    // Вершинный шейдер
    vertex = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertex, 1, &vShaderCode, nullptr);
    glCompileShader(vertex);

    // Если есть ошибки - вывести их
    glGetShaderiv(vertex, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(vertex, 512, nullptr, infoLog);
        std::cout << "Error: vertex shader program compilation failed\n" << infoLog << std::endl;
    }

    // Фрагментный шейдер
    fragment = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragment, 1, &fShaderCode, nullptr);
    glCompileShader(fragment);

    // Если есть ошибки - вывести их
    glGetShaderiv(fragment, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(fragment, 512, nullptr, infoLog);
        std::cout << "Error: fragment shader program compilation failed\n" << infoLog << std::endl;
    }

    // Шейдерная программа
    this->program = glCreateProgram();
    glAttachShader(this->program, vertex);
    glAttachShader(this->program, fragment);
    glLinkProgram(this->program);

    // Если есть ошибки - вывести их
    glGetProgramiv(this->program, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(this->program, 512, nullptr, infoLog);
        std::cout << "Error: shader program linking failed\n" << infoLog << std::endl;
    }

    // Удаляем шейдеры, поскольку они уже в программе и нам больше не нужны.
    glDeleteShader(vertex);
    glDeleteShader(fragment);
}


void drk::Shader::use() {
    glUseProgram(this->program);
}
