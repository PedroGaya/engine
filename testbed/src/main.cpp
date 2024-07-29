#include <jc2d.h>

class SampleLayer : public JC2D::Layer {
   public:
    SampleLayer()
        : Layer("SampleLayer") {
    }

    void onAttach() {
        m_shader = JC2D::Shader::create("Sample");

        m_shader->compileShader("vert", GL_VERTEX_SHADER);
        m_shader->compileShader("frag", GL_FRAGMENT_SHADER);
        m_shader->createProgram();
        m_shader->use();

        m_vertexArray = JC2D::VertexArray::create();
        m_vertexArray->bind();

        // Triangle!
        float vertices[] = {
            // positions         // colors
            0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f,   // bottom right
            -0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f,  // bottom left
            0.0f, 0.5f, 0.0f, 0.0f, 0.0f, 1.0f     // top
        };

        JC2D::BufferLayout layout = {
            {JC2D::RenderDataType::Float3, "aPos"},    // layout (location = 0)
            {JC2D::RenderDataType::Float3, "aColor"},  // layout (location = 1)
        };

        auto vertexBuffer = JC2D::VertexBuffer::create(vertices, sizeof(vertices), layout);
        m_vertexArray->addVertexBuffer(vertexBuffer);

        unsigned int indices[3] = {0, 1, 2};
        int count = sizeof(indices) / sizeof(unsigned int);

        auto indexBuffer = JC2D::IndexBuffer::create(indices, count);
        m_vertexArray->setIndexBuffer(indexBuffer);

        m_vertexArray->unbind();
    }

    void onEvent(JC2D::Event& event) override {
        // JC2D_INFO("{0}", event.toString());
    }

    void onUpdate() override {
        if (JC2D::Input::isKeyJustPressed(JC2D_KEY_SPACE)) {
            JC2D_INFO("space");
        }

        m_shader->use();
        m_vertexArray->bind();

        JC2D::Renderer::drawIndexed(m_vertexArray);
    }

    std::shared_ptr<JC2D::VertexArray> m_vertexArray;
    std::shared_ptr<JC2D::Shader> m_shader;
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