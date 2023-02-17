#pragma once
#include "Ugine/Window.h"
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
    class AssetsRenderer
    {
    public:
        /**
         * @param asset_path the file path of the asset
         * @param asset_name the name of the asset
         * @param window the window on which the asset will appear
         */
        explicit AssetsRenderer(const Window &window ): window(window) {};
        AssetsRenderer(AssetsRenderer&&) = default;
        AssetsRenderer(const AssetsRenderer&) = delete;
        AssetsRenderer& operator=(const AssetsRenderer&) = delete;
        AssetsRenderer& operator=(AssetsRenderer&&) = delete;
        void load(const std:: string& asset_path, const std::string& asset_name);
        void render(const std::string& asset_name, const AssetProps& asset_props) const;
        ~AssetsRenderer();
    private:
        std::map<std::string, SDL_Texture*> textures;
        const Window& window;
    };
}