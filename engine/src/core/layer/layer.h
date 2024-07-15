#pragma once

#include "../../defines.h"
#include "../../jc2dpch.h"
#include "../event/event.h"

namespace JC2D {
    class JC2D_API Layer {
       public:
        Layer(const std::string& name = "Layer");
        virtual ~Layer();

        virtual void onAttach() {}
        virtual void onDetach() {}
        virtual void onUpdate() {}
        virtual void onEvent(Event& event) {}

        inline const std::string& getName() const { return m_name; }

       private:
        std::string m_name;
    };
}  // namespace JC2D