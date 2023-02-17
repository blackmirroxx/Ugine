#pragma oncee
#include "Ugine/Core.h"
#include "Ugine/Renderer.h"
#include "Ugine/Vector.h"

namespace ugine {

    class UGINE_API GameObject {

    };

    class UGINE_API GameObject2D: public GameObject {
    public:
        GameObject2D() =default;
    private:
        Vector2D position{0, 0};
        Vector2D velocity{0, 0};
    };

}

