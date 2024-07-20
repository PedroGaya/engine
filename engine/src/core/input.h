#pragma once

#include "../jc2dpch.h"
#include "../defines.h"

namespace JC2D {
    class JC2D_API Input {
       public:
        static bool isKeyPressed(int keycode);
        static bool isKeyReleased(int keycode);
        static bool isKeyJustPressed(int keycode);
        static bool isKeyJustReleased(int keycode);

        static bool isMouseButtonPressed(int button);
        static bool isMouseButtonReleased(int button);
        static bool isMouseButtonJustPressed(int button);
        static bool isMouseButtonJustReleased(int button);

        static std::pair<double, double> getMousePos();
        static double getMouseX();
        static double getMouseY();

        static void pushToBuffer(int action);
        static void clearBuffer();

       private:
        static bool m_shouldClear;

        static std::set<int> m_inputBuffer;
        static std::set<int> m_previousInputBuffer;

        static Input* s_instance;
    };
}  // namespace JC2D