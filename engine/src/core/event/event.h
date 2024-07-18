#pragma once

#include "../../jc2dpch.h"
#include "../../defines.h"

namespace JC2D {
    enum class EventType {
        None = 0,
        WindowClose,
        WindowResize,
        WindowFocus,
        WindowLostFocus,
        WindowMoved,
        AppTick,
        AppUpdate,
        AppRender,
        KeyPressed,
        KeyReleased,
        MouseButtonPressed,
        MouseButtonReleased,
        MouseMoved,
        MouseScrolled
    };

#define EVENT_CLASS_TYPE(type)                                                  \
    static EventType getStaticType() { return EventType::type; }                \
    virtual EventType getEventType() const override { return getStaticType(); } \
    virtual const char* getName() const override { return #type; }

#define EVENT_CATEGORY_TYPE(category) \
    virtual int getCategoryFlags() const override { return category; }

    enum EventCategory {
        None = 0,
        EventCategoryApplication = BIT(0),
        EventCategoryInput = BIT(1),
        EventCategoryKeyboard = BIT(2),
        EventCategoryMouse = BIT(3),
        EventCategoryMouseButton = BIT(4)
    };

    class JC2D_API Event {
        friend class EventDispatcher;

       public:
        virtual EventType getEventType() const = 0;
        virtual const char* getName() const = 0;
        virtual int getCategoryFlags() const = 0;
        virtual std::string toString() const { return getName(); };

        inline bool isInCategory(EventCategory category) {
            return getCategoryFlags() & category;
        }

        bool handled = false;
    };

    class EventDispatcher {
        template <typename T>
        using EventFn = std::function<bool(T&)>;

       public:
        EventDispatcher(Event& event)
            : m_event(event) {};

        template <typename T>
        bool dispatch(EventFn<T> func) {
            if (m_event.getEventType() == T::getStaticType()) {
                m_event.handled = func(*(T*)&m_event);
                return true;
            }
            return false;
        }

       private:
        Event& m_event;
    };

}  // namespace JC2D
