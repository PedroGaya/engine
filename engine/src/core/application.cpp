#include "./application.h"

#include "./logger/logger.h"
#include "../asserts.h"

#include "./imgui/imgui_layer.h"

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

        m_layerStack.pushOverlay(new ImguiLayer());

        m_metrics = std::unique_ptr<Metrics>(new Metrics());
    }
    Application::~Application() {}

    void Application::onEvent(Event& event) {
        EventDispatcher dispatcher(event);

        dispatcher.dispatch<WindowCloseEvent>(std::bind(&Application::onWindowClose, this, std::placeholders::_1));

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

    // used for logic
    void Application::fixedUpdate() {
        for (Layer* layer : m_layerStack) {
            layer->onFixedUpdate();
        }
    }

    // used for rendering
    void Application::update() {
        glClearColor(1, 1, 1, 1);
        glClear(GL_COLOR_BUFFER_BIT);

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
            }
        };
    }
}  // namespace JC2D
