#pragma once

#include "../jc2dpch.h"
#include "../defines.h"

namespace JC2D {
    class JC2D_API Input {
       public:
        static bool isKeyPressed(int keycode);
        static bool isKeyReleased(int keycode);
        static bool isMouseButtonPressed(int button);
        static bool isMouseButtonReleased(int button);

        static std::pair<double, double> getMousePos();
        static double getMouseX();
        static double getMouseY();

       private:
        static Input* s_instance;
    };
}  // namespace JC2D