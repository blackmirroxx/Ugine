#pragma once

#include "ugine/pch.h"
#include "ugine/core.h"

namespace ugine::window {
    class WindowImpl;

    class UGINE_API WindowImplFactory {
    public:
        WindowImplFactory() = default;

        WindowImplFactory(const WindowImplFactory &) = default;

        WindowImplFactory(WindowImplFactory &&) noexcept = default;

        WindowImplFactory &operator=(const WindowImplFactory &) = default;

        WindowImplFactory &operator=(WindowImplFactory &&) noexcept = default;

        virtual ~WindowImplFactory() = default;

        /**
         * Create a window embedded with a graphic api which fit best the current platform.
         * @return WindowImpl
         */
        [[nodiscard]] virtual std::unique_ptr<WindowImpl> create() const = 0;
    };

    class UGINE_API WindowsWindowFactory final : public WindowImplFactory {
    public:
        [[nodiscard]] std::unique_ptr<WindowImpl> create() const override;
    };

    class UGINE_API LinuxWindowFactory final : public WindowImplFactory {
    public:
        [[nodiscard]] std::unique_ptr<WindowImpl> create() const override;
    };

    class UGINE_API AppleWindowFactory final : public WindowImplFactory {
    public:
        [[nodiscard]] std::unique_ptr<WindowImpl> create() const override;
    };

}

#ifdef UGINE_PLATFORM_APPLE
    #define UGINE_WINDOW_FACTORY ugine::window::AppleWindowFactor
#elif defined(UGINE_PLATFORM_LINUX)
    #define UGINE_WINDOW_FACTORY ugine::window::LinuxWindowFactory
#else
    #define UGINE_WINDOW_FACTORY ugine::window::WindowsWindowFactory
#endif
