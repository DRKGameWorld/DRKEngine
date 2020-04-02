#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <string>
#include <iostream>

namespace drk {
    class Window {
    public:
        explicit Window(const std::string &window_title = "DRKEngine window", bool resizeable = false);
        ~Window();
        bool shouldClose();
        static void pollEvents(); /// Poll window events
        void swap(); /// Swap screens (buffers)
        void clear(float red, float green, float blue, float alpha);

        error_t error = 0;

    private:
        static void errorCallback(int error, const char* description); /// Error callback for GLFW

        GLFWwindow *window;
    };
}
