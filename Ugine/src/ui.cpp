#include "ugine/ui/ui.h"
#include <imgui.h>
#include <imgui_impl_sdl2.h>
#include <imgui_impl_opengl3.h>
#include <stdio.h>
#include <SDL.h>
#include <SDL_opengl.h>
#include "ugine/log.h"
#include "ugine/window/window2D.h"


void ugine::ui::ImguiUI::close(const ugine::window::Window2DImpl& window) const {
    window.accept(ugine::ui::CloseImguiUI());
}

void ugine::ui::ImguiUI::create(const ugine::window::Window2DImpl& window) const {
    window.accept(ugine::ui::CreateImguiUI());
}

void ugine::ui::CreateImguiUI::visit(const ugine::window::SDLWindow & window) const {
    UGINE_CORE_INFO("Creating Imgui");
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO();
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
    io.BackendFlags |= ImGuiBackendFlags_HasMouseCursors;
    io.BackendFlags |= ImGuiBackendFlags_HasSetMousePos;
    ImGui::StyleColorsDark();
    ImGui_ImplSDL2_InitForOpenGL(window.sdl_window, window.gl_context);
    ImGui_ImplOpenGL3_Init(std::string("#version " + std::to_string(
            ugine::window::SDLWindow::OPENGL_MAJOR_VERSION) + std::to_string(ugine::window::SDLWindow::OPENGL_MINOR_VERSION) + "0"
            ).c_str());
}

void ugine::ui::CloseImguiUI::visit(const ugine::window::SDLWindow & window) const {
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplSDL2_Shutdown();
    ImGui::DestroyContext();
}
