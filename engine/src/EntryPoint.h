#pragma once

#include "core/application.h"
#include "core/logger/logger.h"

extern JC2D::Application* JC2D::CreateApplication();

int main(int argc, char** argv) {
    JC2D::Log::Init();
    auto app = JC2D::CreateApplication();
    JC2D_CORE_INFO("Start");
    app->run();
    delete app;
    return 0;
}