#include <jc2d.h>

class SampleLayer : public JC2D::Layer {
   public:
    SampleLayer()
        : Layer("SampleLayer") {
    }

    void onEvent(JC2D::Event& event) override {
        // JC2D_INFO("{0}", event.toString());
    }
};

class Game : public JC2D::Application {
   public:
    Game() {
        pushLayer(new SampleLayer());
    };
    ~Game() = default;
};

JC2D::Application* JC2D::createApplication() {
    return new Game();
}