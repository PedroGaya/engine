#include "jc2dpch.h"
#include "linux_window.h"

namespace JC2D {
    static bool s_GLFWInitialized = false;

    Window* Window::Create(const WindowProps& props) {
        return new LinuxWindow(props);
    }

    LinuxWindow::LinuxWindow(const WindowProps& props) {
        Init(props);
    }

    LinuxWindow::~LinuxWindow() {
        Shutdown();
    }

    void LinuxWindow::Init(const WindowProps& props) {
        m_Data.Title = props.Title;
        m_Data.Width = props.Width;
        m_Data.Height = props.Height;

        JC2D_CORE_INFO("Creating window {0} ({1},{2})", props.Title, props.Width, props.Height);

        if (!s_GLFWInitialized) {
            // TODO: glfwTerminate on sys shutdown

            int success = glfwInit();
            JC2D_ASSERT_MSG(success, "Failed to initialize GLFW");
            s_GLFWInitialized = true;
        }

        m_Window = glfwCreateWindow((int)props.Width, (int)props.Height, m_Data.Title.c_str(), nullptr, nullptr);
        glfwMakeContextCurrent(m_Window);
        glfwSetWindowUserPointer(m_Window, &m_Data);
        SetVSync(true);
    }

    void LinuxWindow::Shutdown() {
        glfwDestroyWindow(m_Window);
    }

}  // namespace JC2D