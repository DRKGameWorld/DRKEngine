#pragma once

#include <DRKEngine/window.h>

namespace drk {
    class RenderLoop {
    public:
        explicit RenderLoop(const Window &window);
        void start();
        void setBackgroundColor(float red, float green, float blue, float alpha = 1.0);

    private:
        Window &window;

        float background_color_red = 0.0;
        float background_color_green = 0.0;
        float background_color_blue = 0.0;
        float background_color_alpha = 1.0;
    };
}
