#pragma once
#include "ugine/core.h"
#include "stdexcept"

namespace ugine::exception {
        class UGINE_API WindowInitError: public std::runtime_error {
            using std::runtime_error::runtime_error;
        };
        class UGINE_API SceneNotFound: public std::runtime_error {
            using std::runtime_error::runtime_error;
        };

    }