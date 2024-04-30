#include <jc2d.h>

class Game : public JC2D::Application {
   public:
    Game() = default;
    ~Game() = default;
};

JC2D::Application* JC2D::CreateApplication() {
    return new Game();
}