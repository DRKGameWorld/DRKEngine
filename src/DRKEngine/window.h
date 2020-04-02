#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <string>
#include <iostream>

namespace drk {
    class Window {
    public:
//        friend class RenderLoop;
        explicit Window(const std::string &window_title = "DRKEngine window", bool resizeable = false);
        ~Window();
        bool shouldClose();
        static void pollEvents();
        static void errorCallback(int error, const char* description);
        void swap();

        error_t error = 0;

    private:
        GLFWwindow *window;
    };
}
