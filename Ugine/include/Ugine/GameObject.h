#pragma oncee
#include "Ugine/Renderer.h"

namespace ugine {

    class GameObject {
    public:
        explicit GameObject(const TextureManager& texture_manager): manager{texture_manager} {}
    private:
        const TextureManager& manager;
    };

}

