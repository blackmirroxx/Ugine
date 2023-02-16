#include "Ugine/Renderer.h"
#include "Ugine/Log.h"
#include "SDL.h"
#include "SDL_image.h"


AssetRenderer::AssetRenderer(const std::string &asset_path, std::string asset_name, const Window &window
                             ) : window(window), asset_name(std::move(asset_name)) {
    SDL_Surface* assert_surface = IMG_Load(asset_path.c_str());
    this->texture = SDL_CreateTextureFromSurface(this->window.sdl_renderer, assert_surface);
    SDL_FreeSurface(assert_surface);
    if (assert_surface == nullptr) UGINE_CORE_ERROR("Error loading asset {0}", this->asset_name);
}


void AssetRenderer::render(const AssetPosition& asset_pos, int frame, int row ) const {
    SDL_Rect src_rect{frame * asset_pos.width,row * asset_pos.height, asset_pos.width, asset_pos.height};
    SDL_Rect dest_rect{asset_pos.x, asset_pos.y, asset_pos.width, asset_pos.height};
    SDL_RenderCopy(this->window.sdl_renderer, this->texture, &src_rect, &dest_rect);
}

