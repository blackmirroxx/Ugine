#pragma once
#include "ugine/core.h"
#include "stdexcept"

namespace ugine::exception {
    class UGINE_API WindowInitError: public std::runtime_error {
        using std::runtime_error::runtime_error;
    };

    class UGINE_API WindowAlreadyCreated: public std::runtime_error {
    public:
        WindowAlreadyCreated(): std::runtime_error("The window is already created"){}
    };

    class UGINE_API SceneNotFound: public std::runtime_error {
    public:
        explicit SceneNotFound(const std::string& scene_name):
            std::runtime_error( "The scene " + scene_name + " is not found") {}
    };

}