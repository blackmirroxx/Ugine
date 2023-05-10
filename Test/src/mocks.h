#pragma once
#include "pch.h"
#include "ugine/window/window.h"
#include "ugine/window/window_impl.h"
#include "ugine/event/window_event.h"
#include "ugine/renderer.h"
#include "ugine/ui/ui.h"
#include "ugine/application.h"
#include "ugine/utils/keycode.h"
#include "ugine/utils/mouse_button.h"

namespace mocks {
    class TestTextureManager2D final: public ugine::TextureManager2D {
    public:
        void render_component(const ugine::Component2D& component,  const ugine::AssetProps& asset_props) const override {

        }
        void load_asset(const std:: string& asset_path, const std::string& asset_name) override {

        }
    };

    class TestInput final: public ugine::window::Input {
    public:
        [[nodiscard]] bool is_key_pressed(ugine::utils::keycode key_code) const noexcept override {return false;}
        [[nodiscard]] bool is_mouse_button_pressed(ugine::utils::mouse_button button) const noexcept override {return false;}
        [[nodiscard]] std::pair<float,float> get_mouse_position() const noexcept override {return {10.F, 20.F};}
    };

    class TestUI final: public ugine::ui::UI {
    public:
        MOCK_METHOD(void, add_impl, (), (const, override));
        MOCK_METHOD(void, remove_impl, (), (const, override));
        MOCK_METHOD(void, render_impl, (), (const, override));
    };

    class TestWindowImpl final: public ugine::window::WindowImpl {
    public:
        explicit TestWindowImpl(std::unique_ptr<ugine::ui::UI> test_ui = std::make_unique<TestUI>())
        : ui(std::move(test_ui)) {}
        void accept(const ugine::window::WindowImplVisitor& visitor)  override {
        }
        MOCK_METHOD(void, open, (const ugine::window::WindowProps &props), (override));
        MOCK_METHOD(void, close, (), (const, override));
        MOCK_METHOD(void, on_update, (), (const, override));
        MOCK_METHOD(void, render, (), (const, override));
        void test_dispatch(const ugine::event::Event& event) const {
            this->dispatch(event);
        }
        [[nodiscard]] const ugine::window::Input& get_input() const noexcept override {
            return this->input;
        }
    private:
        TestInput input;
        std::unique_ptr<ugine::ui::UI> ui;
    };

    class TestWindow: public ugine::window::Window {
    public:
        void on_event(event_cb_type callback) noexcept override {}
        MOCK_METHOD(void, open, (const ugine::window::WindowProps &props), (override));
        void close() const override {}

        void render() const override {}

        void on_update() const override {}

        [[nodiscard]] const ugine::window::Input &get_input() const noexcept override {return input;}

    private:
        TestInput input;
    };

    class TestSceneManager2D final: public ugine::SceneManager<ugine::Scene2D> {

    };


    class TestApplication2D final: public ugine::Application2D {
    public:
        explicit TestApplication2D(std::unique_ptr<ugine::window::Window> window = std::make_unique<TestWindow>(),
                std::unique_ptr<ugine::SceneManager<ugine::Scene2D>> scene_manager = std::make_unique<TestSceneManager2D>()):
                ugine::Application2D(std::move(window), std::move(scene_manager))
                {}
        void run() override {
        }
    private:
        TestSceneManager2D scene_manager;
    };
}

