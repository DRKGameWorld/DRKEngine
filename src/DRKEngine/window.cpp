#include "window.h"

drk::Window::Window(const std::string &window_title, bool resizeable) {
//    std::cout << "!!!WINDOW INIT!!!" << std::endl;
    glfwSetErrorCallback(errorCallback);

    glfwInit();

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_ANY_PROFILE);

    if (resizeable) {
        glfwWindowHint(GLFW_RESIZABLE, GL_TRUE);
    } else {
        glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
    }

    this->window = glfwCreateWindow(800, 600, window_title.c_str(), nullptr, nullptr);
    if (this->window == nullptr) {
//        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        this->error = 1;
        return;
    }
    glfwMakeContextCurrent(this->window);

    glewExperimental = GL_TRUE;
    if (glewInit() != GLEW_OK) {
//        std::cout << "Failed to initialize GLEW" << std::endl;
        this->error = 2;
        return;
    }

    int width, height;
    glfwGetFramebufferSize(this->window, &width, &height);

    glViewport(0, 0, width, height);
}

drk::Window::~Window() {
    glfwTerminate();
}

void drk::Window::errorCallback(int error, const char* description) {
    std::cout << "GLFW Error(" << error << "): " << description << std::endl;
}

bool drk::Window::shouldClose() {
    return glfwWindowShouldClose(this->window);
}

void drk::Window::pollEvents() {
    glfwPollEvents();
}

void drk::Window::swap() {
    glfwSwapBuffers(this->window);
}

void drk::Window::clear(float red, float green, float blue, float alpha) {
    glClearColor(red, green, blue, alpha);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}
