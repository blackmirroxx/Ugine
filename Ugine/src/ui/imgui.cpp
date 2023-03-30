#include "ugine/ui/ui.h"
#include "imgui.h"
#include "backends/imgui_impl_sdl2.h"
#include "backends/imgui_impl_opengl3.h"
#include "ugine/log.h"
#include "../graphic/opengl.h"
#include "../window/sdl_window.h"


namespace {
    class CreateImguiUI final : public ugine::window::WindowImplVisitor {
    public:
        void visit(ugine::window::SDLGlWindow &window) const override {
            UGINE_CORE_INFO("Creating Imgui");
		    window.on_sdl_event([](const SDL_Event &sdl_event) {
                ImGui_ImplSDL2_ProcessEvent(&sdl_event);
            });
            IMGUI_CHECKVERSION();
            ImGui::CreateContext();
            ImGuiIO &gui_io = ImGui::GetIO();
            gui_io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
            gui_io.ConfigFlags |= ImGuiConfigFlags_DockingEnable;         // Enable Docking
            gui_io.ConfigFlags |= ImGuiConfigFlags_ViewportsEnable;       // Enable Multi-Viewport / Platform Windows
            ImGui::StyleColorsDark();
            ImGui_ImplSDL2_InitForOpenGL(window.get_sdl_window(), window.get_gl_context());
            ImGui_ImplOpenGL3_Init(
	std::string("#version " + std::to_string( ugine::graphic::OpenGl::OPENGL_MAJOR_VERSION) +
                                                  std::to_string(ugine::graphic::OpenGl::OPENGL_MINOR_VERSION)
                                                  + "0").c_str()

            );
        }
    };

    class RenderImguiUI final : public ugine::window::WindowImplVisitor {
    public:
        void visit(ugine::window::SDLGlWindow &window) const override {
            bool show_demo = true;
            const ImGuiIO &gui_io = ImGui::GetIO();
            ImGui_ImplOpenGL3_NewFrame();
            ImGui_ImplSDL2_NewFrame();
            ImGui::NewFrame();
            ImGui::ShowDemoWindow(&show_demo);

            ImGui::Render();
            ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
            if ((gui_io.ConfigFlags & ImGuiConfigFlags_ViewportsEnable) != 0) {
                ImGui::UpdatePlatformWindows();
                ImGui::RenderPlatformWindowsDefault();
            }
        }
    };

    class CloseImguiUI final : public ugine::window::WindowImplVisitor {
    public:
        void visit(ugine::window::SDLGlWindow &window) const override {
            ImGui_ImplOpenGL3_Shutdown();
            ImGui_ImplSDL2_Shutdown();
            ImGui::DestroyContext();
        }
    };
}


void ugine::ui::ImguiUI::_add() const {
    this->pt_window_impl->accept(CreateImguiUI());
}

void ugine::ui::ImguiUI::_remove() const {
    this->pt_window_impl->accept(CloseImguiUI());
}

void ugine::ui::ImguiUI::_render() const {
    this->pt_window_impl->accept(RenderImguiUI{});
}

