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
        Vector2D(float x, float y) : m_x{x}, m_y{y} {}

        void set_x(float x) noexcept { this->m_x = x; }

        void set_y(float y) noexcept { this->m_y = y; }

        bool operator==(const Vector2D &other) const {
            return this->m_x == other.m_x && this->m_y == other.m_y;
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
            this->m_x += other.m_x;
            this->m_y += other.m_y;
            return *this;
        }

        Vector2D &operator-=(const Vector2D &other) {
            this->m_x -= other.m_x;
            this->m_y -= other.m_y;
            return *this;
        }

        Vector2D operator*(float scalar) const {
            auto vec = Vector2D{*this};
            vec *= scalar;
            return vec;
        }

        Vector2D &operator*=(float scalar) {
            this->m_y *= scalar;
            this->m_x *= scalar;
            return *this;
        }

        Vector2D operator/(float scalar) const {
            auto vec = Vector2D{*this};
            vec /= scalar;
            return vec;
        }

        Vector2D &operator/=(float scalar) {
            this->m_x /= scalar;
            this->m_y /= scalar;
            return *this;
        }

        void normalize() noexcept override {
            float l = this->length();
            if (l > 0) {
                *this *= (1 / l);
            }
        }

        [[nodiscard]] float get_x() const noexcept { return m_x; }

        [[nodiscard]] float get_y() const noexcept { return m_y; }

        [[nodiscard]] float length() const noexcept override {
            return std::sqrt(m_x * m_x + m_y * m_y);
        }

    private:
        float m_x;
        float m_y;
    };
}