#pragma once
#include "ugine/window.h"
#include "ugine/event/window_event.h"
#include "ugine/renderer.h"
#include "ugine/application.h"

namespace mocks {
    class TestTextureManager2D final: public ugine::TextureManager2D {
    public:
        void render_component(const ugine::Component2D& component,  const ugine::AssetProps& asset_props) const override {

        }
        void load_asset(const std:: string& asset_path, const std::string& asset_name) override {

        }
    };

    class TestWindow final: public ugine::Window {
    public:
        TestWindow() = default;
        void create(const ugine::WindowProps &props = {}) override {};
        void close() const override {}
        void on_update() const override {}
        void render() const override {}
        void test_dispatch(const ugine::event::Event& event) {
            this->dispatch(event);
        }
    };

    class TestWindow2D final: public ugine::Window2D {
    public:
        TestWindow2D() = default;
        void create(const ugine::WindowProps &props = {}) override {};
        void close() const override {}
        void on_update() const override {}
        void render() const override {}
        void test_dispatch(const ugine::event::Event& event) {
            this->dispatch(event);
        }
        [[nodiscard]] virtual ugine::TextureManager2D& get_texture_manager() noexcept {
            return texture_manager;
        }
    private:
        TestTextureManager2D texture_manager;
    };

    class TestSceneManager2D final: public ugine::SceneManager<ugine::Scene2D> {

    };

    class TestApplication2D final: public ugine::Application2D {
    public:
        ugine::SceneManager<ugine::Scene2D> & get_scene_manager() noexcept override {
            return scene_manager;
        }
        ugine::TextureManager2D & get_texture_manager() noexcept override {
            return texture_manager;
        }
        void run() override {
        }
    private:
        TestSceneManager2D scene_manager;
        TestTextureManager2D texture_manager;
    };
}

