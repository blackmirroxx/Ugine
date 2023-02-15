#pragma once

#include <string>
#include <utility>
#include "Ugine/Core.h"
#include "SDL.h"
#include "Ugine/Event/EventHandler.h"

struct UGINE_API WindowProps {
    std::string title = "Default title";
    int height = 650;
    int width = 650;
};

class UGINE_API Window
{
public:
    Window(WindowProps  props = {}): props(std::move(props)) {
        this->init();
    }
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

