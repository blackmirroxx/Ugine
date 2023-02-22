#pragma once
#include "Ugine/Core.h"
#include "Ugine/Exception/Exception.h"
#include <map>

namespace ugine {
    class UGINE_API Scene {
    public:
        explicit Scene(std::string name): name(std::move(name)) {}
        [[nodiscard]] const std::string& get_name() const noexcept {return name;}
    private:
        std::string name;
    };

    class UGINE_API SceneManager {
    public:
        void add_scene(Scene scene) {
            this->scene_map.insert({scene.get_name(), std::move(scene)});
        }
        void remove_scene(const std::string& name) {
            this->scene_map.erase(name);
        }
        Scene& get_scene(const std::string& name)  {
            const auto& el = this->scene_map.find(name);
            if (el == this->scene_map.end()) {
                throw ugine::SceneNotFound("The scene " + name + " is not found");
            }
            return this->scene_map.find(name)->second;
        }
    private:
        std::map<std::string, Scene> scene_map;
    };
}