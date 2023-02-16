#include "spdlog/spdlog.h"
#include "Ugine/log.h"
#include "spdlog/sinks/stdout_color_sinks.h"

static ugine::log::logger_type core_logger;
static ugine::log::logger_type client_logger;

void ugine::log::init() noexcept
{
	spdlog::set_pattern("%^[%T] %n: %v%$");
	core_logger = spdlog::stdout_color_mt("Ugine");
	core_logger->set_level(spdlog::level::trace);;
	client_logger = spdlog::stdout_color_mt("Client");
	client_logger->set_level(spdlog::level::trace);;
}

ugine::log::logger_type& ugine::log::get_core_logger() noexcept
{
	return core_logger;
}

ugine::log::logger_type&  ugine::log::get_client_logger() noexcept
{
	return client_logger;
}
