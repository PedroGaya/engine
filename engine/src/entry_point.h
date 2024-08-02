#pragma once

#include "core/application.h"
#include "core/logger/logger.h"

extern JC2D::Application* JC2D::createApplication();

int main(int argc, char** argv) {
    JC2D::Log::init();
    auto app = JC2D::createApplication();
    app->init();
    app->run();
    delete app;
    return 0;
}