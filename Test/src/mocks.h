#pragma once
#include "ugine/window.h"
#include "ugine/event/window_event.h"
#include "ugine/renderer.h"
#include "ugine/application.h"

namespace mocks {
    class TestTextureManager2D final: public ugine::TextureManager2D {
    public:
        void render(const ugine::Component2D& component,  const ugine::AssetProps& asset_props) const override {

        }
        void load(const std:: string& asset_path, const std::string& asset_name) override {

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

    class TestApplication2D final: public ugine::SDLApplication2D {
    public:
        explicit TestApplication2D(std::unique_ptr<ugine::Window2D> window): ugine::SDLApplication2D(std::move(window)) {}
        void run() override {
        }
    };
}

