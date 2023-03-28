#pragma once

#include "ugine/pch.h"
#include "ugine/core.h"
#include "ugine/graphic/graphic_context.h"
#include "ugine/platfrom.h"

namespace ugine::window {
    class WindowImpl;

    class UGINE_API WindowImplFactory {
    public:
        WindowImplFactory() = default;

        WindowImplFactory(const WindowImplFactory &) = default;

        WindowImplFactory(WindowImplFactory &&) = default;

        WindowImplFactory &operator=(const WindowImplFactory &) = default;

        WindowImplFactory &operator=(WindowImplFactory &&) = default;

        virtual ~WindowImplFactory() = default;

        [[nodiscard]] virtual std::unique_ptr<ugine::window::WindowImpl> create_with_opengl() const = 0;
    };

    class UGINE_API WindowsWindowFactory final : public WindowImplFactory {
    public:
        [[nodiscard]] std::unique_ptr<ugine::window::WindowImpl> create_with_opengl() const override;
    };

    class UGINE_API LinuxWindowFactory final : public WindowImplFactory {
    public:
        [[nodiscard]] std::unique_ptr<ugine::window::WindowImpl> create_with_opengl() const override;
    };

    class UGINE_API AppleWindowFactory final : public WindowImplFactory {
    public:
        [[nodiscard]] std::unique_ptr<ugine::window::WindowImpl> create_with_opengl() const override;
    };

}

#ifdef UGINE_PLATFORM_APPLE
    #define UGINE_WINDOW_FACTORY ugine::window::AppleWindowFactor()
#elif UGINE_PLATFORM_LINUX
    #define UGINE_WINDOW_FACTORY ugine::window::LinuxWindowFactor()
#else
    #define UGINE_WINDOW_FACTORY ugine::window::WindowsWindowFactory()
#endif
