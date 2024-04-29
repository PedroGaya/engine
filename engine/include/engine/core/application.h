#pragma once
#include "../../src/defines.h"

#include <engine.h>

class JC2D_API Application {
    Engine m_engine;

   public:
    Application()
        : m_engine(){};
    virtual ~Application();

    void Run();
};