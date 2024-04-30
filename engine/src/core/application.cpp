#include "application.h"

JC2D::Application::~Application() {}

void JC2D::Application::Run() {
    m_engine.start();
}