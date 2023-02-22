#include "pch.h"
#include "Ugine/Application.h"
#include "Ugine/Exception/Exception.h"


TEST(Scene, AddGetRemoveScene) {
    auto scene = ugine::Scene("menu");
    auto scene_manager = ugine::SceneManager();
    scene_manager.add_scene(scene);
    auto& retrieved_scene = scene_manager.get_scene("menu");
    EXPECT_EQ(retrieved_scene.get_name(), "menu");
    EXPECT_THROW(
            scene_manager.get_scene("not_existing_scene"),
            ugine::SceneNotFound
            );
    scene_manager.remove_scene("menu");
    EXPECT_THROW(
            scene_manager.get_scene("menu"),
            ugine::SceneNotFound
    );
}