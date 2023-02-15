#pragma once
#include "stdexcept"

class WindowInitError: public std::runtime_error {
    using std::runtime_error::runtime_error;
};