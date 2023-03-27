#pragma once

#include "ugine/pch.h"
#include "ugine/core.h"

namespace ugine {

    class UGINE_API Vector {
    public:
        Vector() = default;

        Vector(const Vector &) = default;

        Vector(Vector &&) = default;

        Vector &operator=(const Vector &) = default;

        Vector &operator=(Vector &&) = default;

        virtual ~Vector() = default;

        virtual void normalize() noexcept = 0;

        [[nodiscard]] virtual float length() const noexcept = 0;
    };

    class UGINE_API Vector2D : public Vector {
    public:
        Vector2D(float x, float y) : v_x{x}, v_y{y} {}

        void set_x(float x) noexcept { this->v_x = x; }

        void set_y(float y) noexcept { this->v_y = y; }

        bool operator==(const Vector2D &other) const {
            return this->v_x == other.v_x && this->v_y == other.v_y;
        }

        bool operator!=(const Vector2D &other) const {
            return !(*this == other);
        }

        Vector2D operator+(const Vector2D &other) const {
            auto vec = Vector2D{*this};
            vec += other;
            return vec;
        }

        Vector2D operator-(const Vector2D &other) const {
            auto vec = Vector2D{*this};
            vec -= other;
            return vec;
        }

        Vector2D &operator+=(const Vector2D &other) {
            this->v_x += other.v_x;
            this->v_y += other.v_y;
            return *this;
        }

        Vector2D &operator-=(const Vector2D &other) {
            this->v_x -= other.v_x;
            this->v_y -= other.v_y;
            return *this;
        }

        Vector2D operator*(float scalar) const {
            auto vec = Vector2D{*this};
            vec *= scalar;
            return vec;
        }

        Vector2D &operator*=(float scalar) {
            this->v_y *= scalar;
            this->v_x *= scalar;
            return *this;
        }

        Vector2D operator/(float scalar) const {
            auto vec = Vector2D{*this};
            vec /= scalar;
            return vec;
        }

        Vector2D &operator/=(float scalar) {
            this->v_x /= scalar;
            this->v_y /= scalar;
            return *this;
        }

        void normalize() noexcept override {
            float l = this->length();
            if (l > 0) {
                *this *= (1 / l);
            }
        }

        [[nodiscard]] float get_x() const noexcept { return v_x; }

        [[nodiscard]] float get_y() const noexcept { return v_y; }

        [[nodiscard]] float length() const noexcept override {
            return std::sqrt(v_x * v_x + v_y * v_y);
        }

    private:
        float v_x;
        float v_y;
    };
}