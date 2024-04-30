#pragma once

#include "../defines.h"
#include "engine.h"

class JC2D_API Application {
   public:
    Application()
        : m_engine(){};
    virtual ~Application();

    void Run();

   private:
    Engine m_engine;
};