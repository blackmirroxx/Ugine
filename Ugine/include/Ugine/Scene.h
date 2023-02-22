#pragma once
#include "Ugine/Core.h"
#include "Ugine/Component.h"
#include <map>
#include <vector>
#include <memory>

namespace ugine {

    class UGINE_API Scene {
    public:
        using component_list_type = std::vector<std::unique_ptr<Component>>;
        explicit Scene(std::string name): name(std::move(name)) {}
        Scene(Scene&&) = default;
        Scene(const Scene&) = delete;
        Scene& operator=(Scene&&) =default;
        Scene& operator=(const Scene&) = delete;
        ~Scene() = default;
        [[nodiscard]] const std::string& get_name() const noexcept {return name;}
        [[nodiscard]] component_list_type& get_component_list() noexcept {return this->component_list;}
        void add_component(std::unique_ptr<Component> component) {
            this->component_list.push_back(std::move(component));
        }
    protected:
        component_list_type component_list;
        std::string name;
    };

    class UGINE_API Scene2D: public Scene {
    public:
        explicit Scene2D(std::string name): Scene(std::move(name)) {}
    };

    class UGINE_API SceneManager {
    public:
        void add_scene(Scene scene) {
            this->scene_map.insert({scene.get_name(), std::move(scene)});
        }
        void remove_scene(const std::string& name) {
            this->scene_map.erase(name);
        }
        Scene& get_scene(const std::string& name);
    private:
        std::map<std::string, Scene> scene_map;
    };
}