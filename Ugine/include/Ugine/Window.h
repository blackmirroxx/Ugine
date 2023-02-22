#pragma once

#include <string>
#include <utility>
#include "Ugine/Core.h"
#include "Ugine/Input/InputHandler.h"

struct SDL_Window;
struct SDL_Renderer;


namespace ugine {
    class TextureManager;

    struct UGINE_API WindowProps {
        std::string title = "Default title";
        int height = 650;
        int width = 650;
    };

    class UGINE_API Window
    {
        friend TextureManager;
    public:
        Window(WindowProps  props = {}): props(std::move(props)) {
            this->init();
        }
        void render() const;
        Window(const Window&) = delete;
        Window(Window&&) = delete;
        Window& operator=(const Window&) = delete;
        Window& operator=(Window&&) = delete;
        ~Window();
    private:
        void init();
        WindowProps props;
        SDL_Window * sdl_window{nullptr};
        SDL_Renderer* sdl_renderer{nullptr};
    };
}

