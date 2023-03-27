#pragma once

namespace ugine::window {
    class SDLGlWindow;

    class UGINE_API WindowImplVisitor {
    public:
        WindowImplVisitor() = default;

        WindowImplVisitor &operator=(WindowImplVisitor &&) noexcept = delete;

        WindowImplVisitor &operator=(const WindowImplVisitor &) noexcept = delete;

        WindowImplVisitor(WindowImplVisitor &&) noexcept = delete;

        WindowImplVisitor(const WindowImplVisitor &) = delete;

        virtual ~WindowImplVisitor() = default;

        virtual void visit(SDLGlWindow &) const = 0;
    };
}