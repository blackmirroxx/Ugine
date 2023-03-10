#include "sandbox.h"

static auto create_scenes() {
    auto first_scene = ugine::Scene2D("first_scene");
    first_scene.add_component(std::make_unique<PlayerComponent>());
    return std::array{ugine::Scene2D("menu"), std::move(first_scene) };
}

ugine::Application* ugine::create_application()
{
    auto* const app = new Sandbox();
    auto& scene_manager = app->get_scene_manager();
    app->get_texture_manager().load("assets/Attack.png", "attack");
    for (auto& scene: create_scenes()) {
        scene_manager.add_scene(std::move(scene));
    }
    app->get_texture_manager().render_scene(app->get_scene_manager().get_scene("first_scene"));
    return app;
}

