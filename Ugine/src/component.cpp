#include "ugine/component.h"

void ugine::Component2D::update_position() {
    this->m_velocity += this->m_acceleration;
    this->m_position += this->m_velocity;
}
