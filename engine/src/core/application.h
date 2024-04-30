#pragma once

#include "../defines.h"
#include "engine.h"

namespace JC2D {
    class JC2D_API Application {
       public:
        Application()
            : m_engine(){};
        virtual ~Application();

        void Run();

       private:
        Engine m_engine;
    };

    // Defined by client
    Application* CreateApplication();
}  // namespace JC2D
