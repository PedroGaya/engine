#include "event.h"
#include <sstream>

namespace JC2D {
    class JC2D_API KeyEvent : public Event {
       public:
        inline int getKeyCode() { return m_keyCode; }

        EVENT_CATEGORY_TYPE(EventCategoryKeyboard | EventCategoryInput)
       protected:
        KeyEvent(int keyCode)
            : m_keyCode(keyCode) {}

        int m_keyCode;
    };

    class JC2D_API KeyPressedEvent : public KeyEvent {
       public:
        KeyPressedEvent(int keyCode, int repeatCount)
            : KeyEvent(keyCode),
              m_RepeatCount(repeatCount) {}

        inline int GetRepeatCount() { return m_RepeatCount; }

        EVENT_CLASS_TYPE(KeyPressed)

        std::string toString() const override {
            std::stringstream ss;
            ss << "KeyPressedEvent: " << m_keyCode << " Repeat: " << m_RepeatCount;
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

        std::string toString() const override {
            std::stringstream ss;
            ss << "KeyReleasedEvent: " << m_keyCode;
            return ss.str();
        }
    };
}  // namespace JC2D
