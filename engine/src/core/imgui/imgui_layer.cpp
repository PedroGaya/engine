#include "../../jc2dpch.h"
#include "./imgui_layer.h"

#include "../application.h"
#include "../logger/logger.h"

#include "../event/mouse_event.h"
#include "../event/key_event.h"

namespace JC2D {
    ImguiLayer::ImguiLayer()
        : Layer("ImguiLayer") {};
    ImguiLayer::~ImguiLayer() {};

    void ImguiLayer::onAttach() {
        IMGUI_CHECKVERSION();
        ImGui::CreateContext();

        ImGuiIO& io = ImGui::GetIO();
        io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;
        io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;
        io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;

        Application& app = Application::get();
        GLFWwindow* window = static_cast<GLFWwindow*>(app.getWindow().getNativeWindow());

        ImGui_ImplGlfw_InitForOpenGL(window, true);
        ImGui_ImplOpenGL3_Init();
    };

    void ImguiLayer::onDetach() {
        ImGui_ImplOpenGL3_Shutdown();
        ImGui_ImplGlfw_Shutdown();
        ImGui::DestroyContext();
    };

    void ImguiLayer::onUpdate() {
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        ImGui::ShowDemoWindow();

        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
    };

    void ImguiLayer::onFixedUpdate() {}

    void ImguiLayer::onEvent(Event& event) {
        ImGuiIO& io = ImGui::GetIO();

        if (io.WantCaptureMouse) {
            EventDispatcher dispatcher(event);

            dispatcher.dispatch<MouseButtonPressedEvent>([](Event& event) { JC2D_CORE_INFO("Imgui: {0}", event.toString()); return true; });
            dispatcher.dispatch<MouseButtonReleasedEvent>([](Event& event) { JC2D_CORE_INFO("Imgui: {0}", event.toString()); return true; });
            dispatcher.dispatch<MouseMovedEvent>([](Event& event) { JC2D_CORE_INFO("Imgui: {0}", event.toString()); return true; });
            dispatcher.dispatch<MouseScrolledEvent>([](Event& event) { JC2D_CORE_INFO("Imgui: {0}", event.toString()); return true; });
        }

        if (io.WantCaptureKeyboard) {
            EventDispatcher dispatcher(event);

            dispatcher.dispatch<KeyPressedEvent>([](Event& event) { JC2D_CORE_INFO("Imgui: {0}", event.toString()); return true; });
            dispatcher.dispatch<KeyReleasedEvent>([](Event& event) { JC2D_CORE_INFO("Imgui: {0}", event.toString()); return true; });
        }
    };

}  // namespace JC2D