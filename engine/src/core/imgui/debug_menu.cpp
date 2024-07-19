#include "../../jc2dpch.h"
#include "./debug_menu.h"
#include "../application.h"

namespace JC2D {
    void DebugMenu::renderApplicationInfo() {
        Metrics& metrics = Application::get().getMetrics();

        ImGui::Begin("Application Info");
        ImGui::Text("dt: %.2f ms", metrics.getAverageDeltaTimeMilliseconds());
        ImGui::Text("FPS: %.1f", metrics.getAverageFPS());
        ImGui::End();
    };
}  // namespace JC2D