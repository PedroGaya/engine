#include "./application.h"

#include "./logger/logger.h"

using Clock = std::chrono::high_resolution_clock;
using TimePoint = std::chrono::time_point<Clock>;
using Duration = std::chrono::duration<double>;
namespace JC2D {
    Application::Application() {
        m_totalTimeElapsed = 0.;
        m_globalFrameCounter = 0;
        m_globalSimulationFrameCounter = 0;
        m_running = false;
        m_paused = false;
        m_deltaTime = 0.;
        m_fixedDeltaTime = 0.0083;

        m_window = std::unique_ptr<Window>(Window::Create());
        m_window->SetEventCallback(std::bind(&Application::onEvent, this, std::placeholders::_1));
    }
    Application::~Application() {}

    void Application::onEvent(Event& event) {
        EventDispatcher dispatcher(event);

        dispatcher.Dispatch<WindowCloseEvent>(std::bind(&Application::onWindowClose, this, std::placeholders::_1));

        JC2D_CORE_INFO("{0}", event.ToString());
    };

    bool Application::onWindowClose(WindowCloseEvent& event) {
        stop();
        return true;
    };

    void Application::update() {
        // rendering stuff
        m_window->OnUpdate();
        std::this_thread::sleep_for(std::chrono::milliseconds(8));
    }
    void Application::fixedUpdate() {
        // updating stuff
        std::this_thread::sleep_for(std::chrono::milliseconds(4));
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
        };
    }
}  // namespace JC2D
