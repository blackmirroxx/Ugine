#pragma once
#include "Ugine/component.h"
#include "Ugine/renderer.h"


class PlayerComponent final: public ugine::Component2D {
public:
    PlayerComponent(): ugine::Component2D("player", {1, 2}) {}
    [[nodiscard]] ugine::AssetProps initial_rendering() const noexcept override {
        return {"attack", 0,0, 100, 100, 1 };
    }
};