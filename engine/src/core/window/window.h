#include "../event/event.h"

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

        static Window* create(const WindowProps& props = WindowProps());
        virtual ~Window();

        virtual void onUpdate();
        virtual void pollEvents();

        inline unsigned int getWidth() const { return m_data.width; }
        inline unsigned int getHeight() const { return m_data.height; }

        inline void setEventCallback(const EventCallbackFn& callback) { m_data.callback = callback; }
        virtual void setVSync(bool enabled);
        virtual bool isVSync() const;

        inline GLFWwindow* getNativeWindow() const { return m_window; };

        virtual void init(const WindowProps& props);

       private:
        Window(const WindowProps& props) {};
        virtual void shutdown();

       private:
        GLFWwindow* m_window;

        struct WindowData {
            std::string title;
            unsigned int width, height;
            bool VSync;

            EventCallbackFn callback;
        };

        WindowData m_data;
    };
}  // namespace JC2D
