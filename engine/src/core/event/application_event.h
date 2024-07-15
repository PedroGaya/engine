#include "event.h"
#include <sstream>

namespace JC2D {
    class JC2D_API WindowResizeEvent : public Event {
       public:
        WindowResizeEvent(unsigned int width, unsigned int height)
            : m_width(width),
              m_height(height) {}

        inline unsigned int getWidth() const { return m_width; }
        inline unsigned int getHeight() const { return m_height; }

        std::string toString() const override {
            std::stringstream ss;
            ss << "WindowResizeEvent: " << m_width << ", " << m_height;
            return ss.str();
        }

        EVENT_CLASS_TYPE(WindowResize)
        EVENT_CATEGORY_TYPE(EventCategoryApplication)
       private:
        unsigned int m_width, m_height;
    };

    class JC2D_API WindowCloseEvent : public Event {
       public:
        WindowCloseEvent() {}

        EVENT_CLASS_TYPE(WindowClose)
        EVENT_CATEGORY_TYPE(EventCategoryApplication)

        std::string toString() const override {
            std::stringstream ss;
            ss << "WindowCloseEvent";
            return ss.str();
        }
    };

    class JC2D_API AppTickEvent : public Event {
       public:
        AppTickEvent() {}

        EVENT_CLASS_TYPE(AppTick)
        EVENT_CATEGORY_TYPE(EventCategoryApplication)
    };

    class JC2D_API AppUpdateEvent : public Event {
       public:
        AppUpdateEvent() {}

        EVENT_CLASS_TYPE(AppUpdate)
        EVENT_CATEGORY_TYPE(EventCategoryApplication)
    };

    class JC2D_API AppRenderEvent : public Event {
       public:
        AppRenderEvent() {}

        EVENT_CLASS_TYPE(AppRender)
        EVENT_CATEGORY_TYPE(EventCategoryApplication)
    };

}  // namespace JC2D
