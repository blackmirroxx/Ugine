#pragma once
#include "pch.h"
#include "ugine/window/window.h"
#include "ugine/window/window_impl.h"
#include "ugine/event/window_event.h"
#include "ugine/renderer.h"
#include "ugine/ui/ui.h"
#include "ugine/application.h"

namespace mocks {
    class TestTextureManager2D final: public ugine::TextureManager2D {
    public:
        void render_component(const ugine::Component2D& component,  const ugine::AssetProps& asset_props) const override {

        }
        void load_asset(const std:: string& asset_path, const std::string& asset_name) override {

        }
    };

    class TestInput final: public ugine::Input {
    public:
        [[nodiscard]] bool is_key_pressed(ugine::utils::keycode key_code) const noexcept override {return false;}
        [[nodiscard]] bool is_mouse_button_pressed(ugine::event::mouse_button_type button) const noexcept override {return false;}
        [[nodiscard]] std::pair<float,float> get_mouse_position() const noexcept override {return {10.F, 20.F};}
    };

    class TestUI final: public ugine::ui::UI {
    public:
        MOCK_METHOD(void, create, (const ugine::window::Window2DImpl&), (const, override));
        MOCK_METHOD(void, close, (const ugine::window::Window2DImpl&), (const, override));
        MOCK_METHOD(void, render, (const ugine::window::Window2DImpl&), (const, override));
        MOCK_METHOD(void, handle, (const ugine::event::WindowQuit&), ());
    };

    class TestWindow2DImpl final: public ugine::window::Window2DImpl {
    public:
        explicit TestWindow2DImpl(std::unique_ptr<ugine::ui::UI> test_ui = std::make_unique<TestUI>())
        : ui(std::move(test_ui))
        {
        }
        void accept(const ugine::window::Window2DVisitor& visitor)  const override {
        }
        MOCK_METHOD(void, create, (const ugine::window::WindowProps &props), (override));
        MOCK_METHOD(void, close, (), (const, override));
        MOCK_METHOD(void, on_update, (), (const, override));
        MOCK_METHOD(void, render, (), (const, override));
        void test_dispatch(const ugine::event::Event& event) const {
            this->dispatch(event);
        }
        [[nodiscard]] ugine::TextureManager2D& get_texture_manager() noexcept override {
            return texture_manager;
        }
        [[nodiscard]] const ugine::Input& get_input() const noexcept override {
            return this->input;
        }
    private:
        TestTextureManager2D texture_manager;
        TestInput input;
        std::unique_ptr<ugine::ui::UI> ui;
    };

    class TestSceneManager2D final: public ugine::SceneManager<ugine::Scene2D> {

    };

    class TestApplication2D final: public ugine::Application2D {
    public:
        explicit TestApplication2D(std::unique_ptr<ugine::window::Window2D> window = std::make_unique<TestWindow2DImpl>(),
                std::unique_ptr<ugine::SceneManager<ugine::Scene2D>> scene_manager = std::make_unique<TestSceneManager2D>()):
                ugine::Application2D(std::move(window), std::move(scene_manager))
                {}
        void run() override {
        }
    private:
        TestSceneManager2D scene_manager;
        TestTextureManager2D texture_manager;
    };
}

