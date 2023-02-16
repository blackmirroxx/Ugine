#include "Ugine/Renderer.h"
#include "Ugine/Log.h"
#include "SDL.h"
#include "SDL_image.h"


AssetRenderer::AssetRenderer(const std::string &asset_path, std::string asset_name, const Window &window
                             ) : window(window), asset_name(std::move(asset_name)) {
    SDL_Surface* assert_surface = IMG_Load(asset_path.c_str());
    this->texture = SDL_CreateTextureFromSurface(this->window.sdl_renderer, assert_surface);
    SDL_FreeSurface(assert_surface);
    if (assert_surface == nullptr) UGINE_CORE_ERROR("Error loading asset {0}", asset_name);
}

static SDL_Rect rectangle_to_sdl_rect(const Rectangle & rect) {
    return {rect.x, rect.y, rect.w, rect.h};
}

void AssetRenderer::render(const Rectangle &src, const Rectangle &dest) const {
    SDL_Rect src_rect{rectangle_to_sdl_rect(src)};
    SDL_Rect dest_rect{rectangle_to_sdl_rect(dest)};
    SDL_RenderCopy(this->window.sdl_renderer, this->texture, &src_rect, &dest_rect);
}

