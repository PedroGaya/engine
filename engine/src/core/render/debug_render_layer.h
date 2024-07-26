#include "../../jc2dpch.h"
#include "../layer/layer.h"
#include "./shaders/shader.h"

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
        unsigned int m_vertexBuffer;
        unsigned int m_vertexArray;

        Shader* m_shader;
    };
}  // namespace JC2D