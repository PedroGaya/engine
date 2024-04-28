#include <engine/logger.h>
#include <engine/asserts.h>

#include <engine/core/engine.h>

int main(void) {
    auto engine = new Engine();
    engine->start();
    return 0;
}