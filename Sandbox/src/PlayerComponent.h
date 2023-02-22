#pragma once
#include "Ugine/Component.h"
#include "Ugine/Renderer.h"


class PlayerComponent final: public ugine::Component2D {
public:
    PlayerComponent(): ugine::Component2D("player") {}
    [[nodiscard]] std::tuple<std::string, ugine::AssetProps> initial_rendering() const noexcept override {
        return {"attack", {0,0, 100, 100, 1 }};
    }
};