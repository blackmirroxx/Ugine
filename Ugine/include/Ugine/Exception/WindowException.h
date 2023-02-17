#pragma once
#include "stdexcept"

namespace ugine {
    class WindowInitError: public std::runtime_error {
        using std::runtime_error::runtime_error;
    };
}