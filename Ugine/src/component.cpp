#include "ugine/component.h"

void ugine::Component2D::update_position() {
    this->velocity += this->acceleration;
    this->position += this->velocity;
}
