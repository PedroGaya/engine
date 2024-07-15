#include "event.h"
#include <sstream>

namespace JC2D {
    class JC2D_API MouseMovedEvent : public Event {
       public:
        MouseMovedEvent(float X, float Y)
            : m_mouseX(X),
              m_mouseY(Y) {}

        inline float getMouseX() { return m_mouseX; };
        inline float getMouseY() { return m_mouseY; }

        EVENT_CLASS_TYPE(MouseMoved)
        EVENT_CATEGORY_TYPE(EventCategoryMouse | EventCategoryInput)

        std::string toString() const override {
            std::stringstream ss;
            ss << "MouseMovedEvent: " << m_mouseX << ", " << m_mouseY;
            return ss.str();
        }

       private:
        float m_mouseX,
            m_mouseY;
    };

    class JC2D_API MouseScrolledEvent : public Event {
       public:
        MouseScrolledEvent(float xOffset, float yOffset)
            : m_xOffset(xOffset),
              m_yOffset(yOffset) {}

        inline float getMouseX() { return m_xOffset; };
        inline float getMouseY() { return m_yOffset; };

        std::string toString() const override {
            std::stringstream ss;
            ss << "MouseScrolledEvent: " << m_xOffset << ", " << m_yOffset;
            return ss.str();
        }

        EVENT_CLASS_TYPE(MouseScrolled)
        EVENT_CATEGORY_TYPE(EventCategoryMouse | EventCategoryInput)
       private:
        float m_xOffset,
            m_yOffset;
    };

    class JC2D_API MouseButtonEvent : public Event {
       public:
        inline int getMouseButton() const { return m_button; };

        EVENT_CATEGORY_TYPE(EventCategoryMouse | EventCategoryInput)

       protected:
        MouseButtonEvent(int button)
            : m_button(button) {}
        int m_button;
    };

    class JC2D_API MouseButtonPressedEvent : public MouseButtonEvent {
       public:
        MouseButtonPressedEvent(int button)
            : MouseButtonEvent(button) {}
        inline int getMouseButton() const { return m_button; };

        EVENT_CLASS_TYPE(MouseButtonPressed)

        std::string toString() const override {
            std::stringstream ss;
            ss << "MouseButtonPressedEvent: " << m_button;
            return ss.str();
        }
    };

    class JC2D_API MouseButtonReleasedEvent : public MouseButtonEvent {
       public:
        MouseButtonReleasedEvent(int button)
            : MouseButtonEvent(button) {}
        inline int getMouseButton() const { return m_button; };

        EVENT_CLASS_TYPE(MouseButtonReleased)

        std::string toString() const override {
            std::stringstream ss;
            ss << "MouseButtonReleasedEvent: " << m_button;
            return ss.str();
        }
    };
}  // namespace JC2D
