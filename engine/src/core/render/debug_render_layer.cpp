#include "../../jc2dpch.h"
#include "./debug_render_layer.h"

#include "../application.h"
#include "../logger/logger.h"

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

        unsigned int vertexBuffer;
        glGenBuffers(1, &vertexBuffer);
        glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
        glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

        // position attribute
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
        glEnableVertexAttribArray(0);
        // color attribute
        glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
        glEnableVertexAttribArray(1);

        glBindVertexArray(0);

        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    };
    void DebugRenderLayer::onDetach() {
        delete m_shader;
    };
    void DebugRenderLayer::onUpdate() {
        m_shader->use();

        glBindVertexArray(m_vertexArray);
        glDrawArrays(GL_TRIANGLES, 0, 3);
        glDrawArrays(GL_TRIANGLES, 3, 3);
    };
    void DebugRenderLayer::onFixedUpdate() {};
    void DebugRenderLayer::onEvent(Event& event) {};
}  // namespace JC2D
