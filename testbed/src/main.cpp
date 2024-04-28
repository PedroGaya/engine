#include <engine/logger.h>
#include <engine/asserts.h>

#include <engine/core/engine.h>

int main(void) {
    if (engine_create()) {
        engine_start();
    };
    return 0;
}