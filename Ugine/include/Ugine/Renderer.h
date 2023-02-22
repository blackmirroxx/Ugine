#pragma once
#include "Ugine/Window.h"
#include "Ugine/Scene.h"
#include <string>
#include <map>

struct SDL_Texture;

namespace ugine {
    struct AssetProps
    {
        int x{}, y{}, width{}, height{};
        float zoom = 1;
        int col = 0, row = 0;
    };

/**
 * Render an asset on a window
 */
    class TextureManager
    {
    public:
        /**
         * @param window the window on which the asset will appear
         */
        explicit TextureManager(const Window &window ): window(window) {};
        TextureManager(TextureManager&&) = default;
        TextureManager(const TextureManager&) = delete;
        TextureManager& operator=(const TextureManager&) = delete;
        TextureManager& operator=(TextureManager&&) = delete;
        /**
         * load an asset
         * @param asset_path the file path of the asset
         * @param asset_name the name of the asset
         */
        void load(const std:: string& asset_path, const std::string& asset_name);
        /**
         * Render the asset in the screen
         * @param asset_name
         * @param asset_props
         */
        void render(const std::string& asset_name, const AssetProps& asset_props) const;
        void render(Scene& scene) const {
            for (const auto& component: scene.get_component_list())  {
                auto [name, props] = component->initial_rendering();
                this->render(name, props);
            }
        }
        ~TextureManager();
    private:
        std::map<std::string, SDL_Texture*> textures;
        const Window& window;
    };
}