#pragma once
#include "Ugine/Core.h"
#include <memory>
#include <spdlog/spdlog.h>

namespace ugine::log
	{
		using logger_type = std::shared_ptr<spdlog::logger>;
		UGINE_API void init() noexcept;
		UGINE_API logger_type& get_core_logger() noexcept;
		UGINE_API logger_type& get_client_logger() noexcept;
	}

#ifdef UGINE_DEBUG
	// core log macros
	#define UGINE_CORE_ERROR(msg) ugine::log::get_core_logger()->error(msg)
	#define UGINE_CORE_INFO(msg) ugine::log::get_core_logger()->info(msg)
	#define UGINE_CORE_WARN(msg) ugine::log::get_core_logger()->warn(msg)
	#define UGINE_CORE_TRACE(msg) ugine::log::get_core_logger()->trace(msg)
#else
	#define UGINE_CORE_ERROR(msg) 
	#define UGINE_CORE_INFO(msg) 
	#define UGINE_CORE_WARN(msg) 
	#define UGINE_CORE_TRACE(msg)
#endif

// client log macros
#define UGINE_ERROR(msg) ugine::log::get_client_logger()->error(msg)
#define UGINE_INFO(msg) ugine::log::get_client_logger()->info(msg)
#define UGINE_WARN(msg) ugine::log::get_client_logger()->warn(msg)
#define UGINE_TRACE(msg) ugine::log::get_client_logger()->trace(msg)
