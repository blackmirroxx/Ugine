#pragma once
#include "ugine/window.h"
#include "ugine/scene.h"
#include "ugine/log.h"
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

    class UGINE_API TextureManager
    {
    public:
        TextureManager() = default;
        virtual ~TextureManager() = default;
        TextureManager(TextureManager&&) = default;
        TextureManager(const TextureManager&) = default;
        TextureManager& operator=(const TextureManager&) = default;
        TextureManager& operator=(TextureManager&&) = default;
        virtual void render(const std::string& asset_name, const AssetProps& asset_props) const = 0;
        void render_scene(Scene& scene) const {
            UGINE_CORE_INFO("Rendering scene {0}", scene.get_name());
            for (const auto& component: scene.get_component_list())  {
                auto [name, props] = component->initial_rendering();
                this->render(name, props);
            }
        }
    };

    /**
     * Render an asset on a window
     */
    class UGINE_API SDLTextureManager final: public TextureManager
    {
    public:
        /**
         * @param window the window on which the asset will appear
         */
        explicit SDLTextureManager(const SDLWindow &window ): window(window) {};
        SDLTextureManager(SDLTextureManager&&) = default;
        SDLTextureManager(const SDLTextureManager&) = delete;
        SDLTextureManager& operator=(const SDLTextureManager&) = delete;
        SDLTextureManager& operator=(SDLTextureManager&&) = delete;
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
        void render(const std::string& asset_name, const AssetProps& asset_props) const override;
        ~SDLTextureManager() override;
    private:
        std::map<std::string, SDL_Texture*> textures;
        const SDLWindow& window;
    };
}