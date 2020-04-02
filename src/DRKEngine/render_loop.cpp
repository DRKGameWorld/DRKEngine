#include "render_loop.h"

void drk::RenderLoop::start() {
    while (!this->window.shouldClose()) {
        drk::Window::pollEvents();

        // Draw...
        window.clear(
                this->background_color_red,
                this->background_color_green,
                this->background_color_blue,
                this->background_color_alpha);

        this->window.swap();
    }
}

drk::RenderLoop::RenderLoop(const drk::Window &window) : window(const_cast<Window &>(window)) {
    this->window = window;
}

void drk::RenderLoop::setBackgroundColor(float red, float green, float blue, float alpha) {
    this->background_color_red = red;
    this->background_color_green = green;
    this->background_color_blue = blue;
    this->background_color_alpha = alpha;
}