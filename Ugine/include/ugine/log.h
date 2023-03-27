#pragma once

#include "ugine/pch.h"
#include "ugine/core.h"
#include <spdlog/spdlog.h>

namespace ugine::log {
    using logger_type = std::shared_ptr<spdlog::logger>;
    UGINE_API void init() noexcept;

    UGINE_API logger_type &get_core_logger() noexcept;

    UGINE_API logger_type &get_client_logger() noexcept;
}

#ifdef UGINE_DEBUG
// core log macros
#define UGINE_CORE_ERROR(...) ugine::log::get_core_logger()->error(__VA_ARGS__)
#define UGINE_CORE_INFO(...) ugine::log::get_core_logger()->info(__VA_ARGS__)
#define UGINE_CORE_WARN(...) ugine::log::get_core_logger()->warn(__VA_ARGS__)
#define UGINE_CORE_TRACE(...) ugine::log::get_core_logger()->trace(__VA_ARGS__)
#else
#define UGINE_CORE_ERROR(...)
#define UGINE_CORE_INFO(...)
#define UGINE_CORE_WARN(...)
#define UGINE_CORE_TRACE(...)
#endif

// client log macros
#define UGINE_ERROR(...) ugine::log::get_client_logger()->error(__VA_ARGS__)
#define UGINE_INFO(...) ugine::log::get_client_logger()->info(__VA_ARGS__)
#define UGINE_WARN(...) ugine::log::get_client_logger()->warn(__VA_ARGS__)
#define UGINE_TRACE(...) ugine::log::get_client_logger()->trace(__VA_ARGS__)
