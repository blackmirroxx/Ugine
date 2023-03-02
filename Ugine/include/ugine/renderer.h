#pragma once
#include "ugine/window.h"
#include "ugine/component.h"
#include "ugine/scene.h"
#include "ugine/log.h"
#include <string>
#include <map>

struct SDL_Texture;

namespace ugine {
    struct AssetProps
    {
        std::string name;
        int x{0}, y{0}, width{}, height{};
        float zoom = 1;
        int col = 0, row = 0;
    };

    template <typename S>
    class UGINE_API TextureManager
    {
    public:
        TextureManager() = default;
        virtual ~TextureManager() = default;
        TextureManager(TextureManager&&) = default;
        TextureManager(const TextureManager&) = default;
        TextureManager& operator=(const TextureManager&) = default;
        TextureManager& operator=(TextureManager&&) = default;
        virtual void render_scene(S& scene) const = 0;
    };

    class UGINE_API TextureManager2D: public TextureManager<Scene2D>
    {
    public:
        virtual void render(const Component2D& component,  const AssetProps& asset_props) const = 0;
        void render_scene(Scene2D& scene) const override  {
            UGINE_CORE_INFO("Rendering scene {0}", scene.get_name());
            for (const auto& component: scene.get_component_list())  {
                auto props = component->initial_rendering();
                this->render( *component, props);
            }
        }
    };

    /**
     * Render an asset on a window
     */
    class UGINE_API SDLTextureManager final: public TextureManager2D
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
        void render(const Component2D& component, const AssetProps& asset_props) const override;
        ~SDLTextureManager() override;
    private:
        std::map<std::string, SDL_Texture*> textures;
        const SDLWindow& window;
    };
}