#pragma once

#include <string>
#include <utility>
#include "ugine/core.h"
#include "ugine/input/input_handler.h"

struct SDL_Window;
struct SDL_Renderer;


namespace ugine {
    class SDLTextureManager;

    struct UGINE_API WindowProps {
        std::string title = "Default title";
        int height = 650;
        int width = 650;
    };

    class UGINE_API Window
    {
    public:
        Window() = default;
        virtual ~Window() = default;
        Window(const Window&) = delete;
        Window(Window&&) = delete;
        Window& operator=(const Window&) = delete;
        Window& operator=(Window&&) = delete;
    };

    class UGINE_API SDLWindow: public Window
    {
        friend SDLTextureManager;
    public:
        explicit SDLWindow(WindowProps  props = {}): props(std::move(props)) {
            this->init();
        }
        void render() const;
        SDLWindow(const SDLWindow&) = delete;
        SDLWindow(SDLWindow&&) = delete;
        SDLWindow& operator=(const SDLWindow&) = delete;
        SDLWindow& operator=(SDLWindow&&) = delete;
        ~SDLWindow() override ;
    private:
        void init();
        WindowProps props;
        SDL_Window * sdl_window{nullptr};
        SDL_Renderer* sdl_renderer{nullptr};
    };
}

