#include "./renderer.h"

namespace JC2D {
    void Renderer::clear() {
        glClear(GL_COLOR_BUFFER_BIT);
    };
    void Renderer::setClearColor(const glm::vec4& color) {
        glClearColor(color[0], color[1], color[2], color[3]);
    };

    void Renderer::drawIndexed(const std::shared_ptr<VertexArray>& vertexArray) {
        glDrawElements(GL_TRIANGLES, vertexArray->getIndexBuffer()->getCount(), GL_UNSIGNED_INT, nullptr);
    };
}  // namespace JC2D