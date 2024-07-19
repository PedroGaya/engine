#include "./input.h"
#include "./application.h"

namespace JC2D {
    Input* Input::s_instance = new Input();

    bool Input::isKeyPressed(int keycode) {
        auto window = Application::get().getWindow().getNativeWindow();
        auto state = glfwGetKey(window, keycode);
        return state == GLFW_PRESS || state == GLFW_REPEAT;
    }

    bool Input::isKeyReleased(int keycode) {
        auto window = Application::get().getWindow().getNativeWindow();
        auto state = glfwGetKey(window, keycode);
        return state == GLFW_RELEASE;
    }

    bool Input::isMouseButtonPressed(int button) {
        auto window = Application::get().getWindow().getNativeWindow();
        auto state = glfwGetMouseButton(window, button);
        return state == GLFW_PRESS;
    }

    bool Input::isMouseButtonReleased(int button) {
        auto window = Application::get().getWindow().getNativeWindow();
        auto state = glfwGetMouseButton(window, button);
        return state == GLFW_RELEASE;
    }

    std::pair<double, double> Input::getMousePos() {
        auto window = Application::get().getWindow().getNativeWindow();
        double xpos = 0., ypos = 0.;
        glfwGetCursorPos(window, &xpos, &ypos);

        return {xpos, ypos};
    }

    double Input::getMouseX() {
        auto [x, y] = Input::getMousePos();
        return x;
    }

    double Input::getMouseY() {
        auto [x, y] = Input::getMousePos();
        return y;
    }
}  // namespace JC2D