#include <jc2d.h>

int main(void) {
    auto app = new JC2D::Application();
    JC2D::Log::Init();

    app->Run();
    return 0;
}