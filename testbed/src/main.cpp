#include <jc2d.h>

int main(void) {
    auto app = new JC2D::Application();
    JC2D::Log::Init();

    JC2D_ASSERT(true)

    app->Run();
    return 0;
}