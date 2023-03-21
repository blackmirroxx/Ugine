#pragma once
#include "pch.h"
#include "ugine/window.h"
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
        [[nodiscard]] bool is_key_pressed(int key_code) const noexcept override {return false;}
        [[nodiscard]] bool is_mouse_button_pressed(ugine::event::mouse_button_type button) const noexcept override {return false;}
        [[nodiscard]] virtual std::pair<float,float> get_mouse_position() const noexcept {return {10.F, 20.F};}
    };

    class TestUI final: public ugine::ui::UI {
    public:
        void create(const ugine::Window&) override {}
    };

    class TestWindow final: public ugine::Window {
    public:
        TestWindow() = default;

        MOCK_METHOD(void, create, (const ugine::WindowProps &props), (override));
        void close() const override {}
        void on_update() const override {}
        void render() const override {}
        [[nodiscard]] const ugine::ui::UI& get_ui() const noexcept override {
            return this->ui;
        }
        [[nodiscard]] void* get_native_window() const noexcept override { return nullptr; }
        void test_dispatch(const ugine::event::Event& event) {
            this->dispatch(event);
        }
        [[nodiscard]] const ugine::Input& get_input() const noexcept override {return this->input;}
    private:
        TestInput input;
        TestUI ui;
    };

    class TestWindow2D final: public ugine::Window2D {
    public:
        TestWindow2D() = default;
        MOCK_METHOD(void, create, (const ugine::WindowProps &props), (override));
        void close() const override {}
        [[nodiscard]] void* get_native_window() const noexcept override { return nullptr; }
        void on_update() const override {}
        void render() const override {}
        [[nodiscard]] const ugine::ui::UI& get_ui() const noexcept override {
            return this->ui;
        }
        void test_dispatch(const ugine::event::Event& event) {
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
        TestUI ui;
    };

    class TestSceneManager2D final: public ugine::SceneManager<ugine::Scene2D> {

    };

    class TestApplication2D final: public ugine::Application2D {
    public:
        explicit TestApplication2D(std::unique_ptr<ugine::Window2D> window = std::make_unique<TestWindow2D>(),
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

