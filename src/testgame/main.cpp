#include <DRKEngine/DRKEngine.h>

#include <iostream>

int main() {
    drk::Window window;
    if (window.error) {
        std::cout << "Error code: " << window.error << std::endl;
        return -1;
    }
    std::cout << "Window initialized. Starting render loop..." << std::endl;
    drk::RenderLoop renderLoop(window);
    renderLoop.start();
}

