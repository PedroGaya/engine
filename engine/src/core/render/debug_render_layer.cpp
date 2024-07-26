#include "../../jc2dpch.h"
#include "./debug_render_layer.h"

#include "../application.h"
#include "../logger/logger.h"

namespace JC2D {
    void DebugRenderLayer::onAttach() {
        m_shader = std::shared_ptr<Shader>(new Shader("sample"));

        m_shader->compileShader("./engine/src/shaders/sample/sample.vert", GL_VERTEX_SHADER);
        m_shader->compileShader("./engine/src/shaders/sample/sample.frag", GL_FRAGMENT_SHADER);
        m_shader->createProgram();
        m_shader->use();

        auto vertexArray = new VertexArray();

        m_vertexArray = std::shared_ptr<VertexArray>(vertexArray);
        m_vertexArray->bind();

        // Triangle!
        float vertices[] = {
            // positions         // colors
            0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f,   // bottom right
            -0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f,  // bottom left
            0.0f, 0.5f, 0.0f, 0.0f, 0.0f, 1.0f     // top
        };

        BufferLayout layout = {
            {RenderDataType::Float3, "aPos"},    // layout (location = 0)
            {RenderDataType::Float3, "aColor"},  // layout (location = 1)
        };

        // Can't use std::make_shared due to initializer lists confusing the constructor call.
        auto vertexBuffer = std::shared_ptr<VertexBuffer>(new VertexBuffer(vertices, sizeof(vertices), layout));
        m_vertexArray->addVertexBuffer(vertexBuffer);

        unsigned int indices[3] = {0, 1, 2};
        int count = sizeof(indices) / sizeof(unsigned int);

        auto indexBuffer = std::make_shared<IndexBuffer>(indices, count);
        m_vertexArray->setIndexBuffer(indexBuffer);

        m_vertexArray->unbind();
    };

    void DebugRenderLayer::onDetach() {};
    void DebugRenderLayer::onUpdate() {
        m_shader->use();
        m_vertexArray->bind();

        glDrawElements(GL_TRIANGLES, m_vertexArray->getIndexBuffer()->getCount(), GL_UNSIGNED_INT, nullptr);
    };
    void DebugRenderLayer::onFixedUpdate() {};
    void DebugRenderLayer::onEvent(Event& event) {};
}  // namespace JC2D
