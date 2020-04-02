#include "render_loop.h"

void drk::RenderLoop::start() {
    while (!this->window.shouldClose()) {
        drk::Window::pollEvents();

        // Draw...

        this->window.swap();
    }
}

drk::RenderLoop::RenderLoop(const drk::Window &window) : window(const_cast<Window &>(window)) {
    this->window = window;
}
