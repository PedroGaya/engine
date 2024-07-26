#include "../../jc2dpch.h"
#include "../layer/layer.h"
#include "./shaders/shader.h"

#include "./vertex_array.h"

namespace JC2D {
    class JC2D_API DebugRenderLayer : public Layer {
       public:
        DebugRenderLayer() = default;
        ~DebugRenderLayer() = default;

        void onAttach();
        void onDetach();
        void onUpdate();
        void onFixedUpdate();
        void onEvent(Event& event);

       private:
        std::shared_ptr<Shader> m_shader;

        std::shared_ptr<VertexArray> m_vertexArray;
        std::shared_ptr<VertexBuffer> m_vertexBuffer;
        std::shared_ptr<IndexBuffer> m_indexBuffer;
    };
}  // namespace JC2D