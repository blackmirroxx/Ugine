#pragma once
#include "Ugine/Entrypoint.h"
#include <iostream>
#include "Ugine/Scene.h"
#include "PlayerComponent.h"



class Sandbox final: public ugine::Application
{
};



inline ugine::Application* ugine::create_application()
{
	const auto app = new Sandbox();
    auto& scene_manager = app->get_scene_manager();
	app->signals.on_start.add_listener([](const int i ) 
		{
			std::cout << " on start event " << i << std::endl;
		});
    app->get_texture_manager().load("assets/Attack.png", "attack");
    auto first_scene = Scene2D("first_scene");
    first_scene.add_component(std::make_unique<PlayerComponent>());
    scene_manager.add_scene(std::move(first_scene));
    app->get_texture_manager().render(scene_manager.get_scene("first_scene"));
	return app;
}

