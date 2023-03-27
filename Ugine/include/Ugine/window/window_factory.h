#pragma once
#include "ugine/pch.h"
#include "ugine/core.h"
#include "ugine/graphic/graphic_context.h"

namespace ugine::window {
    class WindowImpl;
    class UGINE_API WindowImplFactory {
    public:
        WindowImplFactory() = default;
        WindowImplFactory(const WindowImplFactory&) = default;
        WindowImplFactory(WindowImplFactory&&) = default;
        WindowImplFactory& operator=(const WindowImplFactory&) = default;
        WindowImplFactory& operator=(WindowImplFactory&&) = default;
        virtual ~WindowImplFactory() = default;
        [[nodiscard]] virtual std::unique_ptr<ugine::window::WindowImpl> create_with_opengl() const = 0;
    };

    class UGINE_API SDLFactory final: public WindowImplFactory {
    public:
        [[nodiscard]] std::unique_ptr<ugine::window::WindowImpl> create_with_opengl() const override;
    };

}