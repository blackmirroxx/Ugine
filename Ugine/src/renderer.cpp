#include "ugine/renderer.h"
#include "ugine/log.h"
#include "SDL.h"
#include "SDL_image.h"


void ugine::SDLTextureManager::load(const std::string &asset_path, const std::string& asset_name) {
    SDL_Surface* assert_surface = IMG_Load(asset_path.c_str());
    this->textures[asset_name] = SDL_CreateTextureFromSurface(this->window.sdl_renderer, assert_surface);
    if (assert_surface == nullptr) UGINE_CORE_ERROR("Error loading asset '{0}'", asset_name);
    SDL_FreeSurface(assert_surface);
}


void ugine::SDLTextureManager::render(const Component2D& component,  const AssetProps& asset_props)  const {
    SDL_Rect src_rect{ asset_props.x + asset_props.col * asset_props.width, asset_props.y + asset_props.row * asset_props.height, asset_props.width, asset_props.height};
    SDL_Rect dest_rect{int(component.get_position().get_x()), int(component.get_position().get_y()), int(float(asset_props.width) * asset_props.zoom), int(float(asset_props.height) * asset_props.zoom)};
    SDL_RenderCopy(this->window.sdl_renderer, this->textures.at(asset_props.name), &src_rect, &dest_rect);
}

ugine::SDLTextureManager::~SDLTextureManager() {
    for (const auto& [name, texture]: this->textures) {
        SDL_DestroyTexture(texture);
        UGINE_CORE_INFO("Free texture '{0}'", name);
    }
}

