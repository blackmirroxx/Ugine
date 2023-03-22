#pragma once

namespace ugine::window {
    class SDLWindow;
    class UGINE_API Window2DVisitor {
            public:
            Window2DVisitor() = default;
            Window2DVisitor& operator=(Window2DVisitor&&) noexcept = delete;
            Window2DVisitor& operator=(const Window2DVisitor&) noexcept = delete;
            Window2DVisitor(Window2DVisitor&&) noexcept = delete;
            Window2DVisitor(const Window2DVisitor&) = delete;
            virtual ~Window2DVisitor() = default;
            virtual void visit(const SDLWindow&) const = 0;
    };
}