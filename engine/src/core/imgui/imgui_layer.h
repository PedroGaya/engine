#pragma once

#include "../../jc2dpch.h"
#include "../layer/layer.h"

namespace JC2D {
    class JC2D_API ImguiLayer : public Layer {
       public:
        ImguiLayer();
        ~ImguiLayer();

        void onAttach() override;
        void onDetach() override;
        void onUpdate() override;
        void onFixedUpdate() override;
        void onImguiRender() override;
        void onEvent(Event& event) override;

        void begin();
        void end();
        void onImguiUpdate();

       private:
    };
}  // namespace JC2D