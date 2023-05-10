#pragma once

#include "ugine/pch.h"
#include "ugine/core.h"

namespace ugine {
    template<typename ...Args>
    class Signal {
        using callback_type = std::function<void(Args...)>;
    public:
        void add_listener(const callback_type &func) noexcept {
            this->m_callback = func;
        }

        void emit(const Args &... args) const noexcept {
            if (this->m_callback) {
                this->m_callback(args...);
            }
        }

        void clear() noexcept {
            this->m_callback = nullptr;
        }

    private:
        callback_type m_callback;
    };


    class SignalDispatcher {
    public:
        Signal<> on_start;
    };

}

