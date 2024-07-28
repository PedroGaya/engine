#include "../../jc2dpch.h"
#include "./vertex_array.h"

namespace JC2D {
    class JC2D_API Renderer {
        void clear();
        void setClearColor(const glm::vec4& color);

        void drawIndexed(const std::shared_ptr<VertexArray>& vertexArray);
    };
}  // namespace JC2D