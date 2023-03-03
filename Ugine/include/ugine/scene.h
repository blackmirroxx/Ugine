#pragma once
#include "ugine/core.h"
#include "ugine/component.h"
#include "ugine/exception/exception.h"
#include <map>
#include <vector>
#include <memory>

namespace ugine {

    template <typename C>
    class UGINE_API Scene {
    public:
        using component_list_type = std::vector<std::unique_ptr<C>>;
        explicit Scene(std::string name): name(std::move(name)) {}
        Scene(Scene&&) = default;
        Scene(const Scene&) = delete;
        Scene& operator=(Scene&&) =default;
        Scene& operator=(const Scene&) = delete;
        ~Scene() = default;
        [[nodiscard]] const std::string& get_name() const noexcept {return name;}
        [[nodiscard]] component_list_type& get_component_list() noexcept {return this->component_list;}
        void add_component(std::unique_ptr<C> component) {
            this->component_list.emplace_back(std::move(component));
        }
    protected:
        std::string name;
        component_list_type component_list;
    };

    class UGINE_API Scene2D: public Scene<Component2D> {
    public:
        explicit Scene2D(std::string name): Scene(std::move(name)) {}
    };

    template <typename S>
    class UGINE_API SceneManager {
    public:
        void add_scene(S scene) {
            this->scene_map.insert({scene.get_name(), std::move(scene)});
        }
        void remove_scene(const std::string& name) {
            this->scene_map.erase(name);
        }
        S& get_scene(const std::string& name) {
            const auto& el = this->scene_map.find(name);
            if (el == this->scene_map.end()) {
                throw ugine::SceneNotFound("The scene " + name + " is not found");
            }
            return this->scene_map.find(name)->second;
        }
    private:
        std::map<std::string, S> scene_map;
    };

    class UGINE_API SceneManager2D: public SceneManager<Scene2D>
    {
    };
}