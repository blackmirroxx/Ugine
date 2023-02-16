#pragma once
#include "Ugine/Window.h"
#include <string>

struct SDL_Texture;

struct Rectangle
{
    int x, y, w, h;
};

/**
 * Render an asset on a window
 */
class AssetRenderer
{
public:
    /**
     * @param asset_path the file path of the asset
     * @param asset_name the name of the asset
     * @param window the window on which the asset will appear
     */
    AssetRenderer(const std::string &asset_path, std::string asset_name, const Window &window );
    void render(const Rectangle& src, const Rectangle& dest ) const;
private:
    SDL_Texture* texture;
    const Window& window;
    const std::string asset_name;
};