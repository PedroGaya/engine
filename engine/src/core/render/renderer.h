#include "../../jc2dpch.h"
#include "./vertex_array.h"

namespace JC2D {
    class JC2D_API Renderer {
        inline static void clear();
        inline static void setClearColor(const glm::vec4& color);

        inline static void drawIndexed(const std::shared_ptr<VertexArray>& vertexArray);
    };
}  // namespace JC2D