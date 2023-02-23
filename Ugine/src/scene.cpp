#include "ugine/scene.h"
#include "ugine/exception/exception.h"

ugine::Scene& ugine::SceneManager::get_scene(const std::string &name) {
    const auto& el = this->scene_map.find(name);
    if (el == this->scene_map.end()) {
        throw ugine::SceneNotFound("The scene " + name + " is not found");
    }
    return this->scene_map.find(name)->second;
}


