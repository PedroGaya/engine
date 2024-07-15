#include "./event/event.h"

namespace JC2D {
    struct WindowProps {
        std::string title;
        unsigned int width;
        unsigned int height;

        WindowProps(const std::string& title = "JC2D",
                    unsigned int width = 1280,
                    unsigned int height = 720)
            : title(title), width(width), height(height) {}
    };

    class JC2D_API Window {
       public:
        using EventCallbackFn = std::function<void(Event&)>;

        virtual ~Window() = default;

        virtual void onUpdate() = 0;

        virtual unsigned int getWidth() const = 0;
        virtual unsigned int getHeight() const = 0;

        virtual void setEventCallback(const EventCallbackFn& callback) = 0;
        virtual void setVSync(bool enabled) = 0;
        virtual bool isVSync() const = 0;

        static Window* create(const WindowProps& props = WindowProps());
    };
}  // namespace JC2D
