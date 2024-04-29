#include <application.h>

Application::~Application() {}

void Application::Run() {
    m_engine.start();
}