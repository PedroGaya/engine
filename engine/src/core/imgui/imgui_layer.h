#include "../../jc2dpch.h"
#include "../layer/layer.h"

namespace JC2D {
    class JC2D_API ImguiLayer : public Layer {
       public:
        ImguiLayer();
        ~ImguiLayer();

        void onAttach();
        void onDetach();
        void onUpdate();
        void onFixedUpdate();
        void onEvent(Event& event);

       private:
    };
}  // namespace JC2D