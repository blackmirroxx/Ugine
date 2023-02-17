#include "Ugine/Renderer.h"
#include "Ugine/Log.h"
#include "SDL.h"
#include "SDL_image.h"


void ugine::AssetsRenderer::load(const std::string &asset_path, const std::string& asset_name) {
    SDL_Surface* assert_surface = IMG_Load(asset_path.c_str());
    this->textures[asset_name] = SDL_CreateTextureFromSurface(this->window.sdl_renderer, assert_surface);
    if (assert_surface == nullptr) UGINE_CORE_ERROR("Error loading asset '{0}'", asset_name);
    SDL_FreeSurface(assert_surface);
}


void ugine::AssetsRenderer::render(const std::string& asset_name, const AssetProps& asset_props)  const {
    SDL_Rect src_rect{asset_props.col * asset_props.width, asset_props.row * asset_props.height, asset_props.width, asset_props.height};
    SDL_Rect dest_rect{asset_props.x, asset_props.y, int(float(asset_props.width) * asset_props.zoom), int(float(asset_props.height) * asset_props.zoom)};
    SDL_RenderCopy(this->window.sdl_renderer, this->textures.at(asset_name), &src_rect, &dest_rect);
}

ugine::AssetsRenderer::~AssetsRenderer() {
    for (const auto& [name, texture]: this->textures) {
        SDL_DestroyTexture(texture);
        UGINE_CORE_INFO("Free texture '{0}'", name);
    }
}

