#include "ugine/ui/ui.h"
#include "imgui.h"
#include "backends/imgui_impl_sdl2.h"
#include "backends/imgui_impl_opengl3.h"
#include "ugine/log.h"
#include "ugine/window/window_impl.h"
#include "ugine/event/keyboard_event.h"

namespace {
    class CreateImguiUI final: public ugine::window::Window2DVisitor
    {
    public:
        void visit(ugine::window::SDLWindow& window) const override {
            UGINE_CORE_INFO("Creating Imgui");
            const auto glsl_version =  std::string("#version " + std::to_string(
                    ugine::window::SDLWindow::OPENGL_MAJOR_VERSION) + std::to_string(ugine::window::SDLWindow::OPENGL_MINOR_VERSION)
                            + "0" );
            window.on_sdl_event([](const SDL_Event& sdl_event){
                ImGui_ImplSDL2_ProcessEvent(&sdl_event);
            });
            IMGUI_CHECKVERSION();
            ImGui::CreateContext();
            ImGuiIO& gui_io = ImGui::GetIO();
            gui_io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
            gui_io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;         // Enable Docking
            gui_io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;       // Enable Multi-Viewport / Platform Windows
            ImGui::StyleColorsDark();
            ImGui_ImplSDL2_InitForOpenGL(window.get_sdl_window(), window.get_gl_context());
            ImGui_ImplOpenGL3_Init(glsl_version.c_str());
        }
    };

    class RenderImguiUI final: public ugine::window::Window2DVisitor {
    public:
        void visit(ugine::window::SDLWindow& window) const override {
            ImGuiIO& gui_io = ImGui::GetIO();
            ImGui_ImplOpenGL3_NewFrame();
            ImGui_ImplSDL2_NewFrame();
            ImGui::NewFrame();
            bool show_demo = true;
            ImGui::ShowDemoWindow(&show_demo);

            ImGui::Render();
            ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
            if ((gui_io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable) != 0)
            {
                ImGui::UpdatePlatformWindows();
                ImGui::RenderPlatformWindowsDefault();
            }
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
}


void ugine::ui::ImguiUI::_create() const {
    this->pt_window_impl->accept(CreateImguiUI());
}

void ugine::ui::ImguiUI::_close() const {
    this->pt_window_impl->accept(CloseImguiUI());
}

void ugine::ui::ImguiUI::_render() const {
    this->pt_window_impl->accept(RenderImguiUI{});
}

