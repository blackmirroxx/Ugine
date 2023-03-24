#include "ugine/ui/ui.h"
#include <imgui.h>
#include <imgui_impl_sdl2.h>
#include <imgui_impl_opengl3.h>
#include <glad/glad.h>
#include <SDL.h>
#include <SDL_opengl.h>
#include "ugine/log.h"
#include "ugine/window/window_impl.h"

namespace {
    class CreateImguiUI: public ugine::window::Window2DVisitor
    {
    public:
        void visit(const ugine::window::SDLWindow& window) const override {
            UGINE_CORE_INFO("Creating Imgui");
            ImGui::CreateContext();
            ImGuiIO& io = ImGui::GetIO();
            io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
            io.BackendFlags |= ImGuiBackendFlags_HasMouseCursors;
            io.BackendFlags |= ImGuiBackendFlags_HasSetMousePos;
            ImGui::StyleColorsDark();
            ImGui_ImplSDL2_InitForOpenGL(window.get_sdl_window(), window.get_gl_context());
            ImGui_ImplOpenGL3_Init(std::string("#version " + std::to_string(
                    ugine::window::SDLWindow::OPENGL_MAJOR_VERSION) + std::to_string(ugine::window::SDLWindow::OPENGL_MINOR_VERSION) + "0"
            ).c_str());
        }
    };

    class CloseImguiUI: public ugine::window::Window2DVisitor
    {
    public:
        void visit(const ugine::window::SDLWindow& window) const override {
            ImGui_ImplOpenGL3_Shutdown();
            ImGui_ImplSDL2_Shutdown();
            ImGui::DestroyContext();
        }
    };

    class RenderImguiUI: public ugine::window::Window2DVisitor {
    public:
        void visit(const ugine::window::SDLWindow& window) const override {
            ImGui_ImplOpenGL3_NewFrame();
            ImGui_ImplSDL2_NewFrame();
            ImGui::NewFrame();
            bool show_demo = true;
            ImGui::ShowDemoWindow(&show_demo);

            ImGui::Render();
            ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
        }
    };
}


void ugine::ui::ImguiUI::create(const ugine::window::Window2DImpl& window) const {
    window.accept(CreateImguiUI());
}

void ugine::ui::ImguiUI::close(const ugine::window::Window2DImpl& window) const {
    window.accept(CloseImguiUI());
}

void ugine::ui::ImguiUI::render(const ugine::window::Window2DImpl& window) const {
    window.accept(RenderImguiUI{});
}

