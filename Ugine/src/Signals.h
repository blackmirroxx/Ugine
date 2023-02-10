#pragma once
#include <functional>

namespace ugine
{
	template <typename ...Args>
	class Signal
	{
		using callback_type = std::function<void(Args...)>;
	public:
		void add_listener(const callback_type& func) noexcept
		{
			this->callback_ = func;
		}
		void emit(const Args&... args) const noexcept
		{
			if (this->callback_) this->callback_(args...);
		}
		void clear() noexcept
		{
			this->callback_ = nullptr;
		}
	private:
		callback_type callback_;
	};


	class SignalDispatcher
	{
	public:
		Signal<int> on_start;
	};

}

