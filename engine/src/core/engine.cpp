#include <chrono>
#include <stdio.h>

using Clock = std::chrono::high_resolution_clock;
using TimePoint = std::chrono::time_point<Clock>;
using Duration = std::chrono::duration<double>;

typedef struct engine_state_t {
    double totalTimeElapsed;
    long globalSimulationFrameCounter;
    long globalFrameCounter;

    short targetSimulationFPS;
    short targetFPS;
    double maxSimulationDeltaTime;
    double maxDeltaTime;

    bool running;
    bool paused;

    double deltaTime;
    double fixedDeltaTime;
} engine_state_t;

static engine_state_t* engine_state;

bool engine_create() {
    engine_state->totalTimeElapsed = 0.;
    engine_state->globalFrameCounter = 0;
    engine_state->globalSimulationFrameCounter = 0;

    engine_state->targetFPS = 60;
    engine_state->targetSimulationFPS = 20;
    engine_state->maxDeltaTime = 1 / engine_state->targetFPS;
    engine_state->maxSimulationDeltaTime = 1 / engine_state->targetSimulationFPS;

    engine_state->running = false;
    engine_state->paused = false;

    engine_state->deltaTime = engine_state->maxDeltaTime;
    engine_state->fixedDeltaTime = engine_state->maxSimulationDeltaTime;

    return true;
}

bool engine_start() {
    if (!engine_create()) {
        return false;
    };

    Duration accumulator = Duration(0);
    TimePoint currentTime = Clock::now();

    // GameState previousState;
    // GameState currentState;

    while (engine_state->running) {
        TimePoint newTime = Clock::now();
        Duration frameTime = currentTime - newTime;
        Duration maxFrameTime = Duration(engine_state->maxDeltaTime);

        if (frameTime > maxFrameTime) {
            frameTime = maxFrameTime;
        };

        currentTime = newTime;
        accumulator += frameTime;

        Duration fixedDeltaTime = Duration(engine_state->fixedDeltaTime);
        while (accumulator >= fixedDeltaTime) {
            // previousState = currentState;
            // simulationUpdate(currentState, engine_state->totalTimeElapsed, engine_state->fixedDeltaTime);
            engine_state->totalTimeElapsed += fixedDeltaTime.count();
            accumulator -= fixedDeltaTime;
            engine_state->globalSimulationFrameCounter += 1;
        };

        const double alpha = accumulator.count() / fixedDeltaTime.count();

        // State state = currentState * alpha + previousState * (1 - alpha);
        // render(state);

        engine_state->globalFrameCounter += 1;

        printf("Render frame counter : %i\n", engine_state->globalFrameCounter);
        printf("Sinulation frame counter : %i\n", engine_state->globalSimulationFrameCounter);
    };

    return true;
}