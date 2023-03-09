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
        virtual void create(const WindowProps& props = {}) = 0;
        virtual void close() const = 0;
        virtual void render() const = 0;
        virtual void on_update() const = 0;
    };

    class UGINE_API SDLWindow: public Window
    {
        friend SDLTextureManager;
    public:
        SDLWindow();
        void create(const WindowProps& props) override;
        void render() const override;
        SDLWindow(const SDLWindow&) = delete;
        SDLWindow(SDLWindow&&) = delete;
        SDLWindow& operator=(const SDLWindow&) = delete;
        SDLWindow& operator=(SDLWindow&&) = delete;
        ~SDLWindow() override ;
        void on_update() const override;
        void close() const override;
    private:
        SDL_Window* sdl_window{nullptr};
        SDL_Renderer* sdl_renderer{nullptr};
    };
}

