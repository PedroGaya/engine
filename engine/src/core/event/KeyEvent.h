#include "event.h"

namespace JC2D {
    class JC2D_API KeyEvent : public Event {
       public:
        inline int GetKeyCode() { return m_KeyCode; }

        EVENT_CATEGORY_TYPE(EventCategoryKeyboard | EventCategoryInput)
       protected:
        KeyEvent(int keyCode)
            : m_KeyCode(keyCode) {}

        int m_KeyCode;
    };

    class JC2D_API KeyPressedEvent : public KeyEvent {
       public:
        KeyPressedEvent(int keyCode, int repeatCount)
            : KeyEvent(keyCode),
              m_RepeatCount(repeatCount) {}

        inline int GetRepeatCount() { return m_RepeatCount; }

        EVENT_CLASS_TYPE(KeyPressed)

        std::string ToString() const override {
            std::stringstream ss;
            ss << "KeyPressedEvent: " << m_KeyCode << " Repeat: " << m_RepeatCount;
            return ss.str();
        }

       private:
        int m_RepeatCount;
    };

    class JC2D_API KeyReleasedEvent : public KeyEvent {
       public:
        KeyReleasedEvent(int keyCode)
            : KeyEvent(keyCode) {}

        EVENT_CLASS_TYPE(KeyReleased)

        std::string ToString() const override {
            std::stringstream ss;
            ss << "KeyReleasedEvent: " << m_KeyCode;
            return ss.str();
        }
    };
}  // namespace JC2D
