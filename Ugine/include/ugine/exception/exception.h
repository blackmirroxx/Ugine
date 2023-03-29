#pragma once

#include "ugine/pch.h"
#include "ugine/core.h"

namespace ugine::exception {

    class UGINE_API SceneNotFound : public std::runtime_error {
    public:
        explicit SceneNotFound(const std::string &scene_name) :
                std::runtime_error("The scene " + scene_name + " is not found") {}
    };
    namespace window {
        class UGINE_API WindowInitError : public std::runtime_error {
            using std::runtime_error::runtime_error;
        };

        class UGINE_API WindowAlreadyCreated : public std::runtime_error {
        public:
            WindowAlreadyCreated() : std::runtime_error("The window is already created") {}
        };
    }


    namespace ui {
        class UGINE_API UIAlreadyCreated : public std::runtime_error {
        public:
            UIAlreadyCreated() : std::runtime_error("The UI is already created for a window, you must call close"
                                                    "before creating a new one") {}
        };

        class UGINE_API UINotCreated : public std::runtime_error {
        public:
            UINotCreated() : std::runtime_error("No UI is created, you must call open before") {}
        };
    }
}