#include "../../core/window.h"

namespace JC2D {
    class LinuxWindow : public Window {
       public:
        LinuxWindow(const WindowProps& props);
        virtual ~LinuxWindow();

        void onUpdate() override;

        inline unsigned int getWidth() const override { return m_data.width; }
        inline unsigned int getHeight() const override { return m_data.height; }

        // Window attributes
        inline void setEventCallback(const EventCallbackFn& callback) { m_data.callback = callback; }
        void setVSync(bool enabled) override;
        bool isVSync() const override;

       private:
        virtual void init(const WindowProps& props);
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