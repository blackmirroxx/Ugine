#pragma once
#include "ugine/pch.h"
#include "ugine/core.h"
#include "ugine/vector.h"

namespace ugine {

    struct AssetProps;

    class UGINE_API Component {
    public:
        explicit Component(std::string name): name(std::move(name))  {}
        Component(Component&&) = default;
        Component(const Component&) = default;
        Component& operator=(Component&&) = default;
        Component& operator=(const Component&) = default;
        virtual ~Component() = default;
        [[nodiscard]] const std::string& get_name() const noexcept {return name;}
        virtual void update_position() = 0;
    protected:
        std::string name;
    };

    class UGINE_API Component2D: public Component {
    public:
        explicit Component2D(std::string name, Vector2D pos = {0,0} , Vector2D vel = {0,0},
                             Vector2D accel = {0,0}): Component(std::move(name)),
                             position{std::move(pos)}, velocity{std::move(vel)}, acceleration{std::move(accel)}
                             {}
        /**
         * First render_scene of the component in a scene
         * @return name of the asset and its props
         */
        [[nodiscard]] virtual AssetProps initial_rendering() const noexcept = 0;
        Component2D(Component2D&&) = default;
        Component2D(const Component2D&) = default;
        Component2D& operator=(Component2D&&) = default;
        Component2D& operator=(const Component2D&) = default;
        ~Component2D() override = default;
        void set_position(Vector2D pos) noexcept {this->position = std::move(pos);}
        void set_velocity(Vector2D vel) noexcept {this->velocity = std::move(vel);}
        void set_acceleration(Vector2D accel) noexcept {this->acceleration = std::move(accel);}
        [[nodiscard]] const Vector2D& get_position() const noexcept {return this->position;}
        [[nodiscard]] const Vector2D& get_velocity() const noexcept {return this->velocity;}
        [[nodiscard]] const Vector2D& get_acceleration() const noexcept {return this->acceleration;}
        void update_position() override;
    protected:
        Vector2D position;
        Vector2D velocity;
        Vector2D acceleration;
    };

}

