#pragma once

#include <string>
#include <utility>
#include "Ugine/Core.h"

struct UGINE_API WindowProps {
    std::string title = "Default title";
    unsigned int height = 1080;
    unsigned int width = 1920;
};

class UGINE_API Window
{
public:
    Window(WindowProps props = WindowProps()): props(std::move(props)) {}
private:
    void init() const;
    WindowProps props;
};

