#include "event.h"

namespace JC2D {
    class JC2D_API WindowResizeEvent : public Event {
       public:
        WindowResizeEvent(unsigned int width, unsigned int height)
            : m_Width(width),
              m_Height(height) {}

        inline unsigned int getWidth() const { return m_Width; }
        inline unsigned int getHeight() const { return m_Height; }

        EVENT_CLASS_TYPE(WindowResize)
        EVENT_CATEGORY_TYPE(EventCategoryApplication)
       private:
        unsigned int m_Width, m_Height;
    };

    class JC2D_API WindowCloseEvent : public Event {
       public:
        WindowCloseEvent() {}

        EVENT_CLASS_TYPE(WindowClose)
        EVENT_CATEGORY_TYPE(EventCategoryApplication)
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
