#pragma once
#include <functional>
#include "ugine/core.h"

namespace ugine
{
	template <typename ...Args>
	class Signal
	{
		using callback_type = std::function<void(Args...)>;
	public:
		void add_listener(const callback_type& func) noexcept
		{
			this->callback = func;
		}
		void emit(const Args&... args) const noexcept
		{
			if (this->callback) this->callback(args...);
		}
		void clear() noexcept
		{
			this->callback = nullptr;
		}
	private:
		callback_type callback;
	};


	class SignalDispatcher
	{
	public:
		Signal<int> on_start;
	};

}

