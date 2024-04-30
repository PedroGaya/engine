#pragma once

#include <chrono>
#include <stdio.h>

using Clock = std::chrono::high_resolution_clock;
using TimePoint = std::chrono::time_point<Clock>;
using Duration = std::chrono::duration<double>;

class Engine {
   public:
    Engine()
        : m_totalTimeElapsed(0.),
          m_globalFrameCounter(0),
          m_globalSimulationFrameCounter(0),
          m_running(false),
          m_paused(false),
          m_deltaTime(0.),
          m_fixedDeltaTime(0.0083){};

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
        bool error = loop();
        return error;
    };
    bool stop() {
        m_running = false;
        return m_running;
    };

    void step(int frameCount);
    bool loop();

   private:
    double m_totalTimeElapsed;
    long m_globalSimulationFrameCounter;
    long m_globalFrameCounter;

    bool m_running;
    bool m_paused;

    double m_deltaTime;
    double m_fixedDeltaTime;
};