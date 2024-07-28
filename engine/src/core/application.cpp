#include "./application.h"
#include "./input.h"
#include "./render/renderer.h"

#include "./logger/logger.h"
#include "../asserts.h"

#include "./imgui/imgui_layer.h"
#include "./render/debug_render_layer.h"

using Clock = std::chrono::high_resolution_clock;
using TimePoint = std::chrono::time_point<Clock>;
using Duration = std::chrono::duration<double>;
namespace JC2D {
    Application* Application::s_instance = nullptr;

    Application::Application() {
        JC2D_ASSERT_MSG(!s_instance, "App already exists.");

        s_instance = this;

        m_totalTimeElapsed = 0.;
        m_globalFrameCounter = 0;
        m_globalSimulationFrameCounter = 0;
        m_running = false;
        m_paused = false;
        m_deltaTime = 0.;
        m_fixedDeltaTime = 0.0083;

        auto windowProps = new WindowProps();
        m_window = std::unique_ptr<Window>(Window::create(*windowProps));
        m_window->init(*windowProps);
        m_window->setEventCallback(std::bind(&Application::onEvent, this, std::placeholders::_1));

        m_layerStack.pushLayer(new DebugRenderLayer());
        m_layerStack.pushOverlay(new ImguiLayer());

        m_metrics = std::unique_ptr<Metrics>(new Metrics());
    }
    Application::~Application() {}

    void Application::onEvent(Event& event) {
        EventDispatcher dispatcher(event);

        dispatcher.dispatch<WindowCloseEvent>(std::bind(&Application::onWindowClose, this, std::placeholders::_1));

        dispatcher.dispatch<KeyPressedEvent>(std::bind(&Application::onKeyPressedEvent, this, std::placeholders::_1));
        dispatcher.dispatch<MouseButtonPressedEvent>(std::bind(&Application::onMouseButtonPressedEvent, this, std::placeholders::_1));

        for (auto it = m_layerStack.end(); it != m_layerStack.begin();) {
            (*--it)->onEvent(event);
            if (event.handled) {
                break;
            }
        }
    };

    bool Application::onWindowClose(WindowCloseEvent& event) {
        stop();
        return true;
    };
    bool Application::onKeyPressedEvent(KeyPressedEvent& event) {
        if (event.GetRepeatCount() == 0) {
            JC2D::Input::pushToBuffer(event.getKeyCode());
        }
        return false;
    }
    bool Application::onKeyReleasedEvent(KeyReleasedEvent& event) {
        JC2D::Input::pushToBuffer(event.getKeyCode());
        return false;
    }
    bool Application::onMouseButtonPressedEvent(MouseButtonPressedEvent& event) {
        JC2D::Input::pushToBuffer(event.getMouseButton());
        return false;
    }
    bool Application::onMouseButtonReleasedEvent(MouseButtonReleasedEvent& event) {
        JC2D::Input::pushToBuffer(event.getMouseButton());
        return false;
    }

    // used for logic
    void Application::fixedUpdate() {
        for (Layer* layer : m_layerStack) {
            layer->onFixedUpdate();
        }
    }

    // used for rendering
    void Application::update() {
        JC2D::Renderer::setClearColor({0.8, 0.8, 0.8, 0.9});
        JC2D::Renderer::clear();

        for (Layer* layer : m_layerStack) {
            layer->onUpdate();
        }
        m_window->onUpdate();
    }

    void Application::run() {
        double accumulator = 0.;
        TimePoint currentTime = Clock::now();

        start();

        JC2D_CORE_INFO("Engine running");

        while (Application::isRunning()) {
            TimePoint newTime = Clock::now();
            Duration frameTime = newTime - currentTime;

            if (frameTime.count() > 0.25) {
                frameTime = Duration(0.25);
            };
            currentTime = newTime;

            m_deltaTime = frameTime.count();
            accumulator += m_deltaTime;

            m_window->pollEvents();

            while (accumulator >= m_fixedDeltaTime) {
                fixedUpdate();
                m_totalTimeElapsed += m_fixedDeltaTime;
                accumulator -= m_fixedDeltaTime;
                m_globalSimulationFrameCounter += 1;
            };

            const double alpha = accumulator / m_fixedDeltaTime;

            update();

            m_globalFrameCounter += 1;

            if (m_metrics->isEnabled()) {
                m_metrics->pushFrameTime(m_deltaTime);
                m_metrics->setUptime(m_totalTimeElapsed);
            }

            JC2D::Input::clearBuffer();
        };
    }
}  // namespace JC2D
