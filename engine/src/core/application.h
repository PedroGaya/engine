#pragma once

#include "../defines.h"
#include "window.h"

#include "./event/application_event.h"
#include "./layer/layer_stack.h"

namespace JC2D {
    class JC2D_API Application {
       public:
        Application();
        ~Application();

        void onEvent(Event& event);

        bool onWindowClose(WindowCloseEvent& event);

        void pushLayer(Layer* layer) { m_layerStack.pushLayer(layer); };
        void pusOverlay(Layer* overlay) { m_layerStack.pushOverlay(overlay); };

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
        LayerStack m_layerStack;

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
    Application* CreateApplication();
}  // namespace JC2D
