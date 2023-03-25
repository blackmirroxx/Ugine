#include "ugine/ui/ui.h"
#include <imgui.h>
#include <imgui_impl_sdl2.h>
#include <imgui_impl_opengl3.h>
#include <glad/glad.h>
#include <SDL.h>
#include <SDL_opengl.h>
#include "ugine/log.h"
#include "ugine/window/window_impl.h"
#include "ugine/event/keyboard_event.h"
#include "ugine/utils/keycode.h"
#include "utils/keyboard_mapping.h"

namespace {
    class CreateImguiUI final: public ugine::window::Window2DVisitor
    {
    public:
        void visit(ugine::window::SDLWindow& window) const override {
            UGINE_CORE_INFO("Creating Imgui");
            window.on_sdl_event([](const SDL_Event& sdl_event){
                ImGui_ImplSDL2_ProcessEvent(&sdl_event);
            });
            ImGui::CreateContext();
            ImGuiIO& io = ImGui::GetIO();
            io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
            ImGui::StyleColorsDark();
            ImGui_ImplSDL2_InitForOpenGL(window.get_sdl_window(), window.get_gl_context());
            ImGui_ImplOpenGL3_Init(std::string("#version " + std::to_string(
                    ugine::window::SDLWindow::OPENGL_MAJOR_VERSION) + std::to_string(ugine::window::SDLWindow::OPENGL_MINOR_VERSION) + "0"
            ).c_str());
        }
    };

    class CloseImguiUI final: public ugine::window::Window2DVisitor
    {
    public:
        void visit(ugine::window::SDLWindow& window) const override {
            ImGui_ImplOpenGL3_Shutdown();
            ImGui_ImplSDL2_Shutdown();
            ImGui::DestroyContext();
        }
    };

    class RenderImguiUI final: public ugine::window::Window2DVisitor {
    public:
        void visit(ugine::window::SDLWindow& window) const override {
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


void ugine::ui::ImguiUI::create() const {
    assert(this->pt_window_impl);
    this->pt_window_impl->accept(CreateImguiUI());
}

void ugine::ui::ImguiUI::close() const {
    assert(this->pt_window_impl);
    this->pt_window_impl->accept(CloseImguiUI());
}

void ugine::ui::ImguiUI::render() const {
    assert(this->pt_window_impl);
    this->pt_window_impl->accept(RenderImguiUI{});
}

