#include "../../jc2dpch.h"
#include "./debug_render_layer.h"

#include "../application.h"
#include "../logger/logger.h"

#include "./buffers.h"

namespace JC2D {
    void DebugRenderLayer::onAttach() {
        m_shader = new Shader("sample");

        m_shader->compileShader("./engine/src/shaders/sample/sample.vert", GL_VERTEX_SHADER);
        m_shader->compileShader("./engine/src/shaders/sample/sample.frag", GL_FRAGMENT_SHADER);
        m_shader->createProgram();
        m_shader->use();

        unsigned int vertexArray;
        glGenVertexArrays(1, &vertexArray);
        m_vertexArray = vertexArray;
        glBindVertexArray(vertexArray);

        // Triangle!
        float vertices[] = {
            // positions         // colors
            0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f,   // bottom right
            -0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f,  // bottom left
            0.0f, 0.5f, 0.0f, 0.0f, 0.0f, 1.0f     // top
        };

        BufferLayout layout = {
            {RenderDataType::Float3, "aPos"},
            {RenderDataType::Float3, "aColor"},
        };
        VertexBuffer* vertexBuffer = new VertexBuffer(vertices, sizeof(vertices), layout);

        int index = 0;
        for (auto& element : layout) {
            glEnableVertexAttribArray(index);
            glVertexAttribPointer(
                index,
                element.count(),
                JC2D_FLOAT,
                element.normalized,
                layout.getStride(),
                (const void*)element.offset);
            index++;
        }

        unsigned int indices[3] = {0, 1, 2};
        int count = sizeof(indices) / sizeof(unsigned int);
        IndexBuffer* indexBuffer = new IndexBuffer(indices, count);

        glBindVertexArray(0);
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    };
    void DebugRenderLayer::onDetach() {
        delete m_shader;
    };
    void DebugRenderLayer::onUpdate() {
        m_shader->use();

        glBindVertexArray(m_vertexArray);
        glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, 0);
    };
    void DebugRenderLayer::onFixedUpdate() {};
    void DebugRenderLayer::onEvent(Event& event) {};
}  // namespace JC2D
