#include "./input.h"
#include "./application.h"
#include "./logger/logger.h"
namespace JC2D {
    Input* Input::s_instance = new Input();

    std::set<int> Input::m_inputBuffer;
    std::set<int> Input::m_previousInputBuffer;

    bool Input::m_shouldClear = false;

    void Input::pushToBuffer(int action) {
        m_inputBuffer.insert(action);
    }

    void Input::clearBuffer() {
        auto window = Application::get().getWindow().getNativeWindow();

        m_previousInputBuffer.clear();

        for (auto it = m_inputBuffer.begin(); it != m_inputBuffer.end();) {
            int value = *it;
            m_previousInputBuffer.insert(value);

            bool isMouseButton = value >= GLFW_MOUSE_BUTTON_1 && value <= GLFW_MOUSE_BUTTON_LAST;

            auto state = isMouseButton ? glfwGetMouseButton(window, value) : glfwGetKey(window, value);
            if (state != GLFW_PRESS) {
                it = m_inputBuffer.erase(it);
            } else {
                ++it;
            }
        }
    }

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
    bool Input::isKeyJustPressed(int keycode) {
        bool isInBuffer = m_inputBuffer.find(keycode) != m_inputBuffer.end();
        bool isInPreviousBuffer = m_previousInputBuffer.find(keycode) != m_previousInputBuffer.end();

        return (isInBuffer && !isInPreviousBuffer);
    }
    bool Input::isKeyJustReleased(int keycode) {
        bool isInBuffer = m_inputBuffer.find(keycode) != m_inputBuffer.end();
        bool isInPreviousBuffer = m_previousInputBuffer.find(keycode) != m_previousInputBuffer.end();

        return (!isInBuffer && isInPreviousBuffer);
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
    bool Input::isMouseButtonJustPressed(int button) {
        bool isInBuffer = m_inputBuffer.find(button) != m_inputBuffer.end();
        bool isInPreviousBuffer = m_previousInputBuffer.find(button) != m_previousInputBuffer.end();

        return (isInBuffer && !isInPreviousBuffer);
    }
    bool Input::isMouseButtonJustReleased(int button) {
        bool isInBuffer = m_inputBuffer.find(button) != m_inputBuffer.end();
        bool isInPreviousBuffer = m_previousInputBuffer.find(button) != m_previousInputBuffer.end();

        return (!isInBuffer && isInPreviousBuffer);
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