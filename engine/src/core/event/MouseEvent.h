#include "event.h"

namespace JC2D {
    class JC2D_API MouseMovedEvent : public Event {
       public:
        MouseMovedEvent(float X, float Y)
            : m_MouseX(X),
              m_MouseY(Y) {}

        inline float GetMouseX() { return m_MouseX; };
        inline float GetMouseY() { return m_MouseY; }

        EVENT_CLASS_TYPE(MouseMoved)
        EVENT_CATEGORY_TYPE(EventCategoryMouse | EventCategoryInput)
       private:
        float m_MouseX,
            m_MouseY;
    };

    class JC2D_API MouseScrolledEvent : public Event {
       public:
        MouseScrolledEvent(float xOffset, float yOffset)
            : m_xOffset(xOffset),
              m_yOffset(yOffset) {}

        inline float GetMouseX() { return m_xOffset; };
        inline float GetMouseY() { return m_yOffset; };

        EVENT_CLASS_TYPE(MouseScrolled)
        EVENT_CATEGORY_TYPE(EventCategoryMouse | EventCategoryInput)
       private:
        float m_xOffset,
            m_yOffset;
    };

    class JC2D_API MouseButtonEvent : public Event {
       public:
        inline int GetMouseButton() const { return m_Button; };

        EVENT_CATEGORY_TYPE(EventCategoryMouse | EventCategoryInput)
       protected:
        MouseButtonEvent(int button)
            : m_Button(button) {}
        int m_Button;
    };

    class JC2D_API MouseButtonPressedEvent : public MouseButtonEvent {
       public:
        MouseButtonPressedEvent(int button)
            : MouseButtonEvent(button) {}
        inline int GetMouseButton() const { return m_Button; };

        EVENT_CLASS_TYPE(MouseButtonPressed)
    };

    class JC2D_API MouseButtonReleasedEvent : public MouseButtonEvent {
       public:
        MouseButtonReleasedEvent(int button)
            : MouseButtonEvent(button) {}
        inline int GetMouseButton() const { return m_Button; };

        EVENT_CLASS_TYPE(MouseButtonReleased)
    };
}  // namespace JC2D
