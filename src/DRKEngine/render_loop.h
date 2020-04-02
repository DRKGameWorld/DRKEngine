#pragma once

#include <DRKEngine/window.h>

namespace drk {
    class RenderLoop {
    public:
        explicit RenderLoop(const Window &window);

        void start();

    private:
        Window &window;
    };
}
