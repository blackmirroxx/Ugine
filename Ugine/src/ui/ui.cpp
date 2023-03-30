#include "ugine/ui/ui.h"
#include "ugine/exception/exception.h"
#include "../window/window_impl.h"

void ugine::ui::UI::render() const {
    if (this->pt_window_impl == nullptr) {
        throw ugine::exception::ui::UINotCreated();
    }
    this->_render();
}

void ugine::ui::UI::remove() const {
    if (this->pt_window_impl == nullptr) {
        throw ugine::exception::ui::UINotCreated();
    }
    this->_remove();
}

void ugine::ui::UI::add(ugine::window::WindowImpl &window_impl) {
    if (this->pt_window_impl != nullptr) {
        throw ugine::exception::ui::UIAlreadyCreated();
    }
    this->pt_window_impl = &window_impl;
    this->_add();
}
