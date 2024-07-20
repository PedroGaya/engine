#pragma once

#include "../defines.h"
#include "window/window.h"

#include "./event/application_event.h"
#include "./event/key_event.h"
#include "./event/mouse_event.h"
#include "./layer/layer_stack.h"

#include "./metrics.h"

namespace JC2D {
    class JC2D_API Application {
       public:
        Application();
        ~Application();

        void onEvent(Event& event);

        bool onWindowClose(WindowCloseEvent& event);

        bool onKeyPressedEvent(KeyPressedEvent& event);
        bool onKeyReleasedEvent(KeyReleasedEvent& event);
        bool onMouseButtonPressedEvent(MouseButtonPressedEvent& event);
        bool onMouseButtonReleasedEvent(MouseButtonReleasedEvent& event);

        void pushLayer(Layer* layer) { m_layerStack.pushLayer(layer); };
        void pusOverlay(Layer* overlay) { m_layerStack.pushOverlay(overlay); };

        inline static Application& get() { return *s_instance; }
        inline Window& getWindow() { return *m_window; }
        inline Metrics& getMetrics() { return *m_metrics; }

        inline double getDeltaTime() { return m_deltaTime * 1000; }
        inline double getFixedDeltaTime() { return m_fixedDeltaTime * 1000; }
        inline double getFPS() { return 1 / m_deltaTime; }

       public:  // Game loop code
        bool isPaused() { return m_paused; };
        bool pause() {
            m_paused = true;
            return m_paused;
        };
        bool unpause() {
            m_paused = false;
            return m_paused;
        };
        bool isRunning() { return m_running; };
        bool start() {
            m_running = true;
            return m_running;
        };
        bool stop() {
            m_running = false;
            return m_running;
        };

        void step(int frameCount);

        void run();

        void update();
        void fixedUpdate();

       private:
        std::unique_ptr<Window> m_window;
        std::unique_ptr<Metrics> m_metrics;

        LayerStack m_layerStack;
        static Application* s_instance;

       private:  // Game loop vars
        double m_totalTimeElapsed;
        long m_globalSimulationFrameCounter;
        long m_globalFrameCounter;

        bool m_running;
        bool m_paused;

        double m_deltaTime;
        double m_fixedDeltaTime;
    };

    // Defined by client
    Application* createApplication();
}  // namespace JC2D
