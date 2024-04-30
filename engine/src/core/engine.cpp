#include "../jc2dpch.h"

#include "engine.h"
#include "./logger/logger.h"

using Clock = std::chrono::high_resolution_clock;
using TimePoint = std::chrono::time_point<Clock>;
using Duration = std::chrono::duration<double>;

bool Engine::loop() {
    double accumulator = 0.;
    TimePoint currentTime = Clock::now();

    JC2D_CORE_INFO("Engine running");

    while (Engine::isRunning()) {
        TimePoint newTime = Clock::now();
        Duration frameTime = newTime - currentTime;

        if (frameTime.count() > 0.25) {
            frameTime = Duration(0.25);
        };
        currentTime = newTime;

        m_deltaTime = frameTime.count();
        accumulator += m_deltaTime;

        while (accumulator >= m_fixedDeltaTime) {
            // updating stuff
            std::this_thread::sleep_for(std::chrono::milliseconds(4));

            m_totalTimeElapsed += m_fixedDeltaTime;
            accumulator -= m_fixedDeltaTime;
            m_globalSimulationFrameCounter += 1;
        };

        const double alpha = accumulator / m_fixedDeltaTime;

        // rendering stuff
        std::this_thread::sleep_for(std::chrono::milliseconds(8));

        m_globalFrameCounter += 1;
    };

    return false;
}