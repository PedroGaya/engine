#include <jc2d.h>

class SampleLayer : public JC2D::Layer {
   public:
    SampleLayer()
        : Layer("SampleLayer") {
    }

    void onEvent(JC2D::Event& event) override {
        // JC2D_INFO("{0}", event.toString());
    }

    void onUpdate() override {
        if (JC2D::Input::isKeyJustPressed(JC2D_KEY_SPACE)) {
            JC2D_INFO("Spacebar just pressed");
        } else if (JC2D::Input::isKeyJustReleased(JC2D_KEY_SPACE)) {
            JC2D_INFO("Spacebar just released");
        }

        if (JC2D::Input::isMouseButtonJustPressed(JC2D_MOUSE_BUTTON_LEFT)) {
            JC2D_INFO("LMB just pressed");
        } else if (JC2D::Input::isKeyJustReleased(JC2D_MOUSE_BUTTON_LEFT)) {
            JC2D_INFO("LMB just released");
        }
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