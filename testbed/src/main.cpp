#include <engine/logger.h>
#include <engine/asserts.h>

int main(void) {
    JC2D_INFO("What's up %s", "Gamers");
    JC2D_ASSERT(FALSE);
    return 0;
}