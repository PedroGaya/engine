#include "../../jc2dpch.h"
#include "./vertex_array.h"

namespace JC2D {
    class JC2D_API Renderer {
       public:
        static void clear();
        static void setClearColor(const glm::vec4& color);

        static void drawIndexed(const std::shared_ptr<VertexArray>& vertexArray);
    };
}  // namespace JC2D