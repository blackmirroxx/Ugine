#pragma once
#include "Ugine/Core.h"
#include "Ugine/Vector.h"
#include <tuple>
#include <string>

namespace ugine {

    struct AssetProps;

    class UGINE_API Component {
    public:
        Component(std::string name): name(std::move(name))  {}
        /**
         * First render of the component in a scene
         * @return name of the asset and its props
         */
        [[nodiscard]] virtual std::tuple<std::string, AssetProps> initial_rendering() const noexcept = 0;
        Component(Component&&) = default;
        Component(const Component&) = default;
        Component& operator=(Component&&) = default;
        Component& operator=(const Component&) = default;
        virtual ~Component() = default;
        [[nodiscard]] const std::string& get_name() const noexcept {return name;}
    protected:
        std::string name;
    };

    class UGINE_API Component2D: public Component {
    public:
        explicit Component2D(std::string name): Component(std::move(name)) {}
        Component2D(Component2D&&) = default;
        Component2D(const Component2D&) = default;
        Component2D& operator=(Component2D&&) = default;
        Component2D& operator=(const Component2D&) = default;
        ~Component2D() override = default;
    private:
        Vector2D position{0, 0};
        Vector2D velocity{0, 0};
        Vector2D acceleration{0, 0};
    };

}

